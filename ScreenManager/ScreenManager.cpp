#include "ScreenManager.h"

using namespace uicommon;

ScreenManager::ScreenManager()
{
    mView = new QQuickView();
    mContext = mView->rootContext();
    mView->engine()->addImportPath("qrc:/");

    this->registerProperty("ScreenSource", "");
    this->registerProperty("ScreenWidth", 600);
    this->registerProperty("ScreenHeight", 900);
}

ScreenManager::~ScreenManager()
{
}

QQuickView *ScreenManager::getViewer()
{
    return mView;
}

void ScreenManager::createView()
{
    mView->setSource(QUrl("qrc:/Resources/Screens/MainView.qml"));
    mView->show();
}

void ScreenManager::registerProperty(const QString &str, const QVariant &val)
{
    if (mContextProperties.contains(str))
        return;

    mContextProperties.append(str);
    mContext->setContextProperty(str, val);
}

void ScreenManager::updateProperty(const QString &str, const QVariant &val)
{
    if (!mContextProperties.contains(str))
        return;

    mContext->setContextProperty(str, val);
}
