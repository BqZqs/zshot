// SPDX-License-Identifier: GPL-3.0-or-later
// Stub tray icon implementation - does nothing

#include "trayicon.h"
#include <QSystemTrayIcon>

TrayIcon::TrayIcon(QObject* parent)
  : QObject(parent)
  , m_trayIcon(nullptr)
  , m_menu(nullptr)
{
}

TrayIcon::~TrayIcon()
{
    delete m_trayIcon;
    delete m_menu;
}

void TrayIcon::show()
{
    // No-op in lite version
}

void TrayIcon::hide()
{
    // No-op in lite version
}

void TrayIcon::showMessage(const QString&, const QString&,
                            const QIcon&, int)
{
    // No-op in lite version
}
