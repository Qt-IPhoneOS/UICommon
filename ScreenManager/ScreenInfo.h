#ifndef SCREENINFO_H
#define SCREENINFO_H

#include <QObject>
#include <QString>

namespace uicommon {

class ScreenInfo : public QObject {
    Q_OBJECT

public:
    ScreenInfo(const QString& name, const QString& source);

    QString getSource() const;
    QString getName() const;

private:
    QString mSource;
    QString mName;
};

}

#endif // SCREENINFO_H
