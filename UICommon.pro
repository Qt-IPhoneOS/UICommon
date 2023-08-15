QT += quick virtualkeyboard
CONFIG += c++20

TEMPLATE = lib
TARGET = uicommon
DESTDIR = $$PWD/../Executable

SOURCES += \

resources.prefix = /$${TARGET}
RESOURCES += UICommon.qrc

HEADERS += \
    Signal.h

DISTFILES +=
