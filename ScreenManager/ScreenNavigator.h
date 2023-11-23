#ifndef SCREENNAVIGATOR_H
#define SCREENNAVIGATOR_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlEngine>
#include "ScreenInfo.h"

class ScreenNagivator : public QObject
{
    Q_OBJECT
public:
    static ScreenNagivator *instance();
    ~ScreenNagivator();

    QQuickView* getViewer();
    void createView();
    void showScreen(uchar screen);

    void registerProperty(const QString& str, const QVariant&);
    void updateProperty(const QString&, const QVariant&);

    void registerScreen(const uchar& screenId, const QString& name, const QString& url);

private:
    ScreenNagivator();

    QQuickView* mView {nullptr};
    QQmlContext* mContext {nullptr};
    QQmlEngine mEngine;
    QVector<QString> mContextProperties;
    std::unordered_map<uchar, ScreenInfo*> mScreenProperties;
};

#endif // SCREENNAVIGATOR_H
