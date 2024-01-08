#include "ScreenNavigator.h"
#include <QDebug>

using namespace uicommon;

ScreenNavigator::ScreenNavigator()
{
}

ScreenNavigator::~ScreenNavigator()
{

}

void ScreenNavigator::showScreen(uchar screen)
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

void ScreenNavigator::registerScreen(const uchar &screenId, const QString& name, const QString &url)
{
    if (mScreenProperties.find(screenId) != mScreenProperties.end())
        return;

    ScreenInfo* screen = new ScreenInfo(name, url);
    mScreenProperties[screenId] = screen;
}

ScreenNavigator* ScreenNavigator::instance()
{
    ScreenNavigator* ins = nullptr;
    if (ins == nullptr)
    {
        ins = new ScreenNavigator();
    }
    return ins;
}
