#ifndef STACKINGSTASK_H
#define STACKINGSTASK_H

#include <tuple>
#include <deque>
#include <vector>
#include <future>
#include <functional>

namespace uicommon {

class StackingTaskState {
public:
    inline bool isPerforming() const
    {
        return mIsPerforming;
    }
    inline void setIsPerforming(const bool& performing)
    {
        mIsPerforming = performing;
    }
private:
    bool mIsPerforming {false};
};

template<typename T, typename ...Args>
class StackingTask {
public:
    using InitializeTuple = std::tuple<Args...>;
    using Functions = std::vector<std::function<bool(T&)>>;
    StackingTask()
    {
    }

    StackingTask(StackingTask&& other)
    {
        mFuncs = std::move(other.mFuncs);
        mInitializeArgs = std::move(other.mInitializeArgs);
    }

    StackingTask(Functions funcs)
    {
        mFuncs = std::move(funcs);
    }

    StackingTask& operator=(StackingTask& other)
    {
        mFuncs = std::move(other.mFuncs);
        mMutexInitializeArgs.lock();
        mInitializeArgs = std::move(other.mInitializeArgs);
        mMutexInitializeArgs.unlock();
        return *this;
    }

    void perform(Args... args)
    {
        mMutexInitializeArgs.lock();
        mInitializeArgs.push_back(std::make_tuple(args...));
        mMutexInitializeArgs.unlock();

        std::unique_lock<std::mutex> lockerState(mMutexState);
        if (mState.isPerforming())
            return;

        lockerState.unlock();
        priPerform();
    }

    void patchInitializeArgs(std::function<void(InitializeTuple&, const StackingTaskState&)> fn)
    {
        if (fn == nullptr)
            return;

        std::unique_lock<std::mutex> lock(mMutexInitializeArgs);
        std::unique_lock<std::mutex> lockerState(mMutexState);
        fn(mInitializeArgs, mState);
    }

private:
    void priPerform()
    {
        std::unique_lock<std::mutex> lockerState(mMutexState);
        if (!mState.isPerforming())
        {
            lockerState.unlock();
            doTask();
        }
    }

    void doTask()
    {
        mTask = std::async(std::launch::async, [&] {
            bool trap = false;
            do {
                std::unique_lock<std::mutex> lockState(mMutexState);
                mState.setIsPerforming(true);
                mMutexState.unlock();

                std::unique_lock<std::mutex> lock(mMutexInitializeArgs);
                if (!mInitializeArgs.empty()) {
                    InitializeTuple initTuple = mInitializeArgs.front();
                    mInitializeArgs.pop_front();
                    lock.unlock();

                    // implement initialize function
                    //mStateObj.initialize(initTuple);

                    for (auto& func : mFuncs)
                    {
                        if (func != nullptr)
                        {
                            if (!func(mStateObj))
                                break;
                        }
                    }
                } else {
                    lock.unlock();
                }

                lockState.lock();
                mState.setIsPerforming(false);
                trap = (0 < mInitializeArgs.size());
                lockState.unlock();

            } while(true);
        });
    }

    std::vector<std::function<bool(T&)>> mFuncs;
    std::future<void> mTask;

    std::deque<InitializeTuple> mInitializeArgs;
    std::mutex mMutexInitializeArgs;

    T mStateObj;

    StackingTaskState mState;
    std::mutex mMutexState;
};

}

#endif
