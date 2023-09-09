#ifndef __SIGNAL_H
#define __SIGNAL_H

#include <functional>
#include <list>
#include <memory>
#include <mutex>
#include <shared_mutex>

namespace signal
{
    /**
     * @brief _Signature is a type parameter that represent a function signature or
     * operator signature.
     */
    enum class SignalState {
        State_Connect,
        State_Disconnect
    };

    template <typename _Signature>
    class Signal;
    class Connect;

    struct ConnectState
    {
        ConnectState() : mState(SignalState::State_Connect){}

        std::shared_mutex mMutex;
        SignalState mState;
    };

    /**
     * @brief Func(Args...) represents a function signature.
     * By using _Signature as the type parameter in template<typename _Signature>.
     * we can define a class template Signal that can accept and work with different
     * typoes of functions with different signatures.
     * @param Func is the return type of the function.
     * @param Args is the list of function parameters.
     */
    template <typename Func, typename... Args>
    class Signal<Func(Args...)>
    {
    public:
        Connect connect(const std::function<Func(Args...)> &slot);

        Func operator()(Args... args);

        void disconnectAllConnection();

        bool isEmpty() const;

    private:
        std::shared_mutex mMutex;

        /**
         * @brief Use std::weak_ptr track ConnectState objects in the list without
         * creating additional strong references. Access the ConnectState through
         * the std::weak_ptr by converting it to a std::shared_ptr using the lock()
         * method.
         */
        std::list<
            std::pair<std::weak_ptr<ConnectState>, std::function<Func(Args...)>>>
            mSlotList;
    };

    class Connect
    {
    public:
        Connect(){};

        Connect(const std::shared_ptr<ConnectState> &conStsPtr)
        {
            mConStsPtr = conStsPtr;
        }

        // Copy constructor
        Connect(const Connect &other) { mConStsPtr = other.mConStsPtr; }

        // Copy assignment operator
        Connect &operator=(const Connect &other)
        {
            mConStsPtr = other.mConStsPtr;
            return *this;
        }

        void disconnect()
        {
            std::unique_lock<std::shared_mutex> lock(mConStsPtr->mMutex);
            mConStsPtr->mState = SignalState::State_Disconnect;
        }

    protected:
        std::shared_ptr<ConnectState> mConStsPtr;
    };

    template <typename Func, typename... Args>
    inline Connect
    Signal<Func(Args...)>::connect(const std::function<Func(Args...)> &slot)
    {
        std::shared_ptr<ConnectState> conSts = std::make_shared<ConnectState>();
        std::unique_lock<std::shared_mutex> lock(mMutex);
        mSlotList.emplace_back(
            std::make_pair(std::weak_ptr<ConnectState>(conSts), slot));
        return Connect(conSts);
    }

    template <typename Func, typename... Args>
    Func
    Signal<Func(Args...)>::operator()(Args... args)
    {
        bool removeFlg = false;
        {
            std::shared_lock<std::shared_mutex> lock(mMutex);

            /**
             * @brief typename inform the compiler that
             * td::list<std::pair<std::weak_ptr<ConnectState>,std::function<_Res(_Args...)>>>
             * is a type and not a variable or function.
             */
            for (typename std::list<
                     std::pair<std::weak_ptr<ConnectState>,
                               std::function<Func(Args...)>>>::iterator it =
                     mSlotList.begin();
                 it != mSlotList.end(); ++it)
            {
                std::shared_ptr<ConnectState> conSts =
                    std::get<0>(*it).lock(); // lock(): convert to weak_ptr
                if (conSts == nullptr)
                    removeFlg = true;
                else
                {
                    std::shared_lock<std::shared_mutex> lock(conSts->mMutex);
                    if (conSts->mState == SignalState::State_Connect)
                    {
                        std::get<1> (*it)(args...);
                    }
                    else
                    {
                        removeFlg = true;
                    }
                }
            }
            if (removeFlg)
            {
                std::unique_lock<std::shared_mutex> lock(mMutex);
                typename std::list<
                    std::pair<std::weak_ptr<ConnectState>,
                              std::function<Func(Args...)>>>::iterator it =
                    mSlotList.begin();
                while (it != mSlotList.end())
                {
                    std::shared_ptr<ConnectState> conSts = std::get<0>(*it).lock();
                    if (conSts == nullptr)
                    {
                        mSlotList.erase(it++);
                    }
                    else
                    {
                        std::shared_lock<std::shared_mutex> lock(conSts->mMutex);
                        if (conSts->mState == SignalState::State_Connect)
                        {
                            ++it;
                        }
                        else
                        {
                            mSlotList.erase(it++);
                        }
                    }
                }
            }
        }
    }

    template <typename Func, typename... Args>
    void
    Signal<Func(Args...)>::disconnectAllConnection()
    {
        std::unique_lock<std::shared_mutex> lock(mMutex);
        if (!isEmpty())
        {
            mSlotList.clear();
        }
    }

    template <typename Func, typename... Args>
    bool
    Signal<Func(Args...)>::isEmpty() const
    {
        std::shared_lock<std::shared_mutex> lock(mMutex);
        return mSlotList.empty();
    }
} // namespace signal

#endif
