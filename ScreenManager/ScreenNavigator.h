#ifndef SCREENNAVIGATOR_H
#define SCREENNAVIGATOR_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlEngine>
#include "ScreenInfo.h"
#include "ScreenManager.h"

class ScreenNagivator : public ScreenManager
{
public:
    static ScreenNagivator *instance();
    ~ScreenNagivator();

    void showScreen(uchar screen);

    void registerScreen(const uchar& screenId, const QString& name, const QString& url);

private:
    ScreenNagivator();

    std::unordered_map<uchar, ScreenInfo*> mScreenProperties;
};

#endif // SCREENNAVIGATOR_H
