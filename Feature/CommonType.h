#ifndef COMMONTYPE_H
#define COMMONTYPE_H

#include <memory>
#include <string>
#include <shared_mutex>
#include <mutex>

using TypePtr = std::shared_ptr<void>;

class CommonType {
private:
    TypePtr mType;
    mutable std::shared_mutex mMutex;

public:
    CommonType()
    {
    }

    ~CommonType()
    {
    }

    template<typename Type>
    CommonType(const Type& val)
    {
        mType = std::make_shared<Type>(val);
    }

    template <typename Type>
    void setValue(const Type& value)
    {
        std::shared_ptr<Type> newPtr = std::make_shared<Type>(value);
        {
            std::unique_lock<std::shared_mutex> lock(mMutex);
            mType = std::move(newPtr);
        }
    }

    template <typename Type>
    Type value() const
    {
        std::shared_lock<std::shared_mutex> lock(mMutex);
        Type* type = std::static_pointer_cast<Type>(mType).get(); // cast the value to the root type
        return *type;
    }
};


#endif // COMMONTYPE_H
