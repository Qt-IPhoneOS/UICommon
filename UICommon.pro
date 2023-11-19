QT += quick virtualkeyboard
CONFIG += c++20

TEMPLATE = lib
TARGET = uicommon
DESTDIR = $$PWD/../../Executable

INCLUDEPATH += $$PWD/Feature \

SOURCES += \

resources.prefix = /$${TARGET}
RESOURCES += UICommon.qrc

HEADERS += \
    Feature/CommonType.h \
    Feature/Log.h \
    Feature/Signal.h \
    Feature/StackingTask.h \
    Feature/TaskStateProcessCallback.h

DISTFILES +=
