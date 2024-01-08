#ifndef SCREENNAVIGATOR_H
#define SCREENNAVIGATOR_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlEngine>
#include "ScreenInfo.h"
#include "ScreenManager.h"

namespace uicommon {

class ScreenNavigator : public ScreenManager
{
public:
    static ScreenNavigator *instance();
    ~ScreenNavigator();

    void showScreen(uchar screen);

    void registerScreen(const uchar& screenId, const QString& name, const QString& url);

private:
    ScreenNavigator();

    std::unordered_map<uchar, ScreenInfo*> mScreenProperties;
};

}
#endif // SCREENNAVIGATOR_H
