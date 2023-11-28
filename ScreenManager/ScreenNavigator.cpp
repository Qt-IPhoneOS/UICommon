#include "ScreenNavigator.h"
#include <QDebug>

ScreenNagivator::ScreenNagivator()
{
}

ScreenNagivator::~ScreenNagivator()
{

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
