QT += quick virtualkeyboard
CONFIG += c++20

TEMPLATE = lib
TARGET = uicommon
DESTDIR = $$PWD/../../build/executable

INCLUDEPATH += $$PWD/Feature \
               $$PWD/ScreenManager \

SOURCES += \
    ScreenManager/ScreenInfo.cpp \
    ScreenManager/ScreenManager.cpp \
    ScreenManager/ScreenNavigator.cpp \
    ScreenManager/ScreenQueue.cpp

QML_IMPORT_PATH += $$PWD/

RESOURCES += \
    UICommon.qrc

HEADERS += \
    Feature/CommonStruct.h \
    Feature/CommonType.h \
    Feature/Log.h \
    Feature/Signal.h \
    Feature/StackingTask.h \
    Feature/TaskStateProcessCallback.h \
    ScreenManager/ScreenInfo.h \
    ScreenManager/ScreenManager.h \
    ScreenManager/ScreenNavigator.h \
    ScreenManager/ScreenQueue.h

DISTFILES +=
