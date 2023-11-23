#include "ScreenNavigator.h"
#include <QDebug>

ScreenNagivator::ScreenNagivator()
{
    mView = new QQuickView();
    mContext = mView->rootContext();

    this->registerProperty("ScreenSource", "");
    this->registerProperty("ScreenWidth", 600);
    this->registerProperty("ScreenHeight", 900);
}

ScreenNagivator::~ScreenNagivator()
{

}

QQuickView *ScreenNagivator::getViewer()
{
    return mView;
}

void ScreenNagivator::createView()
{
    mView->setSource(QUrl("qrc:/Resources/Screens/MainView.qml"));
    mView->show();
}

void ScreenNagivator::showScreen(uchar screen)
{
    if (mView == nullptr)
        return;

    for (auto &item : mScreenProperties)
    {
        if (item.first == screen)
        {
            ScreenInfo* screen = item.second;
            this->updateProperty("ScreenSource", screen->getSource());
        }
    }
}

void ScreenNagivator::registerProperty(const QString &str, const QVariant& val)
{
    if (mContextProperties.contains(str))
        return;

    mContextProperties.append(str);
    mContext->setContextProperty(str, val);
}

void ScreenNagivator::updateProperty(const QString &str, const QVariant &val)
{
    if (!mContextProperties.contains(str))
        return;

    mContext->setContextProperty(str, val);
}

void ScreenNagivator::registerScreen(const uchar &screenId, const QString& name, const QString &url)
{
    if (mScreenProperties.find(screenId) != mScreenProperties.end())
        return;

    ScreenInfo* screen = new ScreenInfo(name, url);
    mScreenProperties[screenId] = screen;
}

ScreenNagivator* ScreenNagivator::instance()
{
    ScreenNagivator* ins = nullptr;
    if (ins == nullptr)
    {
        ins = new ScreenNagivator();
    }
    return ins;
}
