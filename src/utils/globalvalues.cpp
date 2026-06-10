#include "globalvalues.h"
#include <QApplication>
#include <QFontMetrics>

int GlobalValues::buttonBaseSize()
{
    return QFontMetrics(qApp->font()).lineSpacing() * 2.2;
}

QString GlobalValues::versionInfo()
{
    return QStringLiteral("Zshot " APP_VERSION);
}

QString GlobalValues::iconPath()
{
    return { ":img/icons/app.svg" };
}

QString GlobalValues::iconPathPNG()
{
    return { ":img/icons/app.svg" };
}

QString GlobalValues::trayIconPath()
{
    return { ":img/icons/app.svg" };
}
