// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#include "zshot.h"
#include "core/zshotdaemon.h"

#include "config/configresolver.h"
#include "utils/confighandler.h"
#include "utils/screenshotsaver.h"
#include "widgets/capture/capturewidget.h"

#include <QApplication>
#include <QMessageBox>
#include <QThread>
#include <QTimer>

Zshot::Zshot()
  : m_captureWindow(nullptr)
{
    QString StyleSheet = CaptureButton::globalStyleSheet();
    qApp->setStyleSheet(StyleSheet);
}

Zshot* Zshot::instance()
{
    static Zshot c;
    return &c;
}

CaptureWidget* Zshot::gui(const CaptureRequest& req)
{
    if (!resolveAnyConfigErrors()) {
        return nullptr;
    }

    if (nullptr == m_captureWindow) {
        int timeout = 5000; // 5 seconds
        const int delay = 100;
        QWidget* modalWidget = nullptr;
        for (; timeout >= 0; timeout -= delay) {
            modalWidget = qApp->activeModalWidget();
            if (nullptr == modalWidget) {
                break;
            }
            modalWidget->close();
            modalWidget->deleteLater();
            QThread::msleep(delay);
        }
        if (0 == timeout) {
            QMessageBox::warning(
              nullptr, tr("Error"), tr("Unable to close active modal widgets"));
            return nullptr;
        }

        m_captureWindow = new CaptureWidget(req);
#ifdef Q_OS_WIN
        m_captureWindow->show();
#else
        m_captureWindow->showFullScreen();
#endif
        return m_captureWindow;
    } else {
        emit captureFailed();
        return nullptr;
    }
}

bool Zshot::resolveAnyConfigErrors()
{
    bool resolved = true;
    ConfigHandler confighandler;
    if (!confighandler.checkUnrecognizedSettings() ||
        !confighandler.checkSemantics()) {
        auto* resolver = new ConfigResolver();
        QObject::connect(
          resolver, &ConfigResolver::rejected, [resolver, &resolved]() {
              resolved = false;
              resolver->deleteLater();
          });
        QObject::connect(
          resolver, &ConfigResolver::accepted, [resolver, &resolved]() {
              resolved = true;
              resolver->close();
              resolver->deleteLater();
              qApp->processEvents();
          });
        resolver->exec();
        qApp->processEvents();
    }
    return resolved;
}

void Zshot::requestCapture(const CaptureRequest& request)
{
    if (!resolveAnyConfigErrors()) {
        return;
    }

    switch (request.captureMode()) {
        case CaptureRequest::GRAPHICAL_MODE:
            QTimer::singleShot(
              request.delay(), this, [this, request]() { gui(request); });
            break;
        default:
            emit captureFailed();
            break;
    }
}

void Zshot::exportCapture(const QPixmap& capture,
                              QRect& selection,
                              const CaptureRequest& req)
{
    using CR = CaptureRequest;
    int tasks = req.tasks();
    QString path = req.path();

    if (tasks & CR::SAVE) {
        if (req.path().isEmpty()) {
            saveToFilesystemGUI(capture);
        } else {
            saveToFilesystem(capture, path);
        }
    }

    if (tasks & CR::COPY) {
        ZshotDaemon::copyToClipboard(capture);
    }

    if (tasks & CR::PIN) {
        ZshotDaemon::createPin(capture, selection);
    }

    emit captureTaken(capture);
}
