QT += quick virtualkeyboard
CONFIG += c++20

TEMPLATE = lib
TARGET = uicommon
DESTDIR = $$PWD/../../Executable

SOURCES += \

resources.prefix = /$${TARGET}
RESOURCES += UICommon.qrc

HEADERS += \
    FeatureClass/CommonType.h \
    FeatureClass/Signal.h \
    FeatureClass/StackingTask.h

DISTFILES +=
