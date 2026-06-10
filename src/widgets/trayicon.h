// SPDX-License-Identifier: GPL-3.0-or-later
// Stub tray icon for zshot lite - no actual tray functionality

#pragma once

#include <QObject>
#include <QString>

class QSystemTrayIcon;
class QMenu;

class TrayIcon : public QObject
{
    Q_OBJECT
public:
    explicit TrayIcon(QObject* parent = nullptr);
    ~TrayIcon();

    void show();
    void hide();
    void showMessage(const QString& title, const QString& msg,
                     const QIcon& icon = QIcon(), int timeout = 10000);

signals:
    void activated();

private:
    QSystemTrayIcon* m_trayIcon;
    QMenu* m_menu;
};
