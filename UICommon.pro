QT += quick virtualkeyboard
CONFIG += c++20

TEMPLATE = lib
TARGET = uicommon
DESTDIR = $$PWD/../../Executable

INCLUDEPATH += $$PWD/Feature \
               $$PWD/ScreenManager \

SOURCES += \
    ScreenManager/ScreenInfo.cpp \
    ScreenManager/ScreenNavigator.cpp

resources.prefix = /$${TARGET}
RESOURCES += UICommon.qrc

HEADERS += \
    Feature/CommonStruct.h \
    Feature/CommonType.h \
    Feature/Log.h \
    Feature/Signal.h \
    Feature/StackingTask.h \
    Feature/TaskStateProcessCallback.h \
    ScreenManager/ScreenInfo.h \
    ScreenManager/ScreenNavigator.h

DISTFILES +=
