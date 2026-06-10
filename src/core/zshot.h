// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#pragma once

#include "core/capturerequest.h"

#include <QObject>
#include <QPointer>

class CaptureWidget;

enum ErrCode : uint8_t
{
    E_OK = 0,
    E_GENERAL,
    E_ABORTED,
    E_DBUSCONN,
    E_SIG_BASE = 128,
    E_SIGINT = E_SIG_BASE + 2,
    E_SIGTERM = E_SIG_BASE + 15,
};

class Zshot : public QObject
{
    Q_OBJECT

public:
    static Zshot* instance();

public slots:
    CaptureWidget* gui(
      const CaptureRequest& req = CaptureRequest::GRAPHICAL_MODE);
    void requestCapture(const CaptureRequest& request);
    void exportCapture(const QPixmap& p,
                       QRect& selection,
                       const CaptureRequest& req);

signals:
    void captureTaken(QPixmap p);
    void captureFailed();

private:
    Zshot();
    bool resolveAnyConfigErrors();

    QPointer<CaptureWidget> m_captureWindow;
};
