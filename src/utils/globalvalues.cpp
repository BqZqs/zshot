// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#include "globalvalues.h"

#include <QApplication>
#include <QFontMetrics>

int GlobalValues::buttonBaseSize()
{
    return QFontMetrics(qApp->font()).lineSpacing() * 2.2;
}

QString GlobalValues::versionInfo()
{
    return QStringLiteral("Zshot " APP_VERSION " (" ZSHOT_GIT_HASH ")"
                          "\nCompiled with Qt " QT_VERSION_STR);
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
