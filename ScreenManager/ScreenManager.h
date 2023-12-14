#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlEngine>

namespace uicommon {

class ScreenManager : public QObject
{
    Q_OBJECT
public:
    ScreenManager();
    ~ScreenManager();

    QQuickView* getViewer();
    void createView();

    void registerProperty(const QString& str, const QVariant&);
    void updateProperty(const QString&, const QVariant&);

protected:
    QQuickView* mView {nullptr};
    QQmlContext* mContext {nullptr};
    QVector<QString> mContextProperties;
};

}

#endif // SCREENMANAGER_H
