#pragma once
#include <QObject>
class TrayIcon : public QObject {
    Q_OBJECT
public:
    explicit TrayIcon(QObject* p = nullptr) : QObject(p) {}
    void show() {}
    void hide() {}
    void showMessage(const QString&, const QString&, const QIcon& = QIcon(), int = 10000) {}
signals:
    void activated();
};
