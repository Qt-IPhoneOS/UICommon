#ifndef TASKSTATEPROCESSCALLBACK_H
#define TASKSTATEPROCESSCALLBACK_H

#include <tuple>

namespace uicommon {

template <typename T>
class TaskStateProcessCallback {
public:
    inline void initialize(std::tuple<T> initTuple)
    {
        mParam = std::move(std::get<0>(initTuple));
    }

    inline void moveTo(T& param)
    {
        param = std::move(std::move(mParam));
    }

private:
    T mParam;
};

}

#endif // TASKSTATEPROCESSCALLBACK_H
