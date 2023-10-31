#ifndef LOG_H
#define LOG_H

#include <QDebug>
#include <QMetaEnum>

// print enum
#define LogEnum(str, val)                                             \
    QMetaEnum metaEnum = QMetaEnum::fromType<decltype(val)>();        \
    const char* enumStr = metaEnum.valueToKey(static_cast<int>(val)); \
    if (enumStr) {                                                    \
        QString enumString = QString(enumStr);                        \
        qWarning() << str << enumString;                              \
    }

// print primitive data
#define LogBool(str, val)                                                 \
    if (std::is_same<decltype(val), bool>::value) {                   \
        qWarning() << str << (val ? "true" : "false");                \
    }                                                                 \

// To Do

#endif // LOG_H
