#include "ScreenInfo.h"


ScreenInfo::ScreenInfo(const QString& name, const QString &source) : mSource(source), mName(name)
{

}

QString ScreenInfo::getSource() const
{
    return mSource;
}

QString ScreenInfo::getName() const
{
    return mName;
}
