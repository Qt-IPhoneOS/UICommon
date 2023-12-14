#ifndef LOG_H
#define LOG_H

#pragma once

#include <QDebug>
#include <QMetaEnum>

namespace uicommon {
// print enum
#define LOG_ENUM(str, val)                                                 \
    {                                                                     \
        QMetaEnum metaEnum = QMetaEnum::fromType<decltype(val)>();        \
        const char* enumStr = metaEnum.valueToKey(static_cast<int>(val)); \
        if (enumStr) {                                                    \
            QString enumString = QString(enumStr);                        \
            qWarning() << str << enumString;                              \
        }                                                                 \
    }

// print primitive data
#define LOG_BOOL(str, val)                                                 \
    {                                                                     \
        if (std::is_same<decltype(val), bool>::value) {                   \
            qWarning() << str << (val ? "true" : "false");                \
        }                                                                 \
        if (std::is_same<decltype(val), const bool&>::value) {            \
                qWarning() << str << (val ? "true" : "false");            \
        }                                                                 \
    }

// To Do

}

#endif // LOG_H
