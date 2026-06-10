// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#include "zshotdbusadapter.h"
#include "core/zshot.h"
#include "core/zshotdaemon.h"

ZshotDBusAdapter::ZshotDBusAdapter(QObject* parent)
  : QDBusAbstractAdaptor(parent)
{}

ZshotDBusAdapter::~ZshotDBusAdapter() = default;

void ZshotDBusAdapter::captureScreen()
{
    Zshot::instance()->gui(CaptureRequest(CaptureRequest::GRAPHICAL_MODE));
}

void ZshotDBusAdapter::attachScreenshotToClipboard(const QByteArray& data)
{
    ZshotDaemon::instance()->attachScreenshotToClipboard(data);
}

void ZshotDBusAdapter::attachTextToClipboard(const QString& text,
                                                 const QString& notification)
{
    ZshotDaemon::instance()->attachTextToClipboard(text, notification);
}

void ZshotDBusAdapter::attachPin(const QByteArray& data)
{
    ZshotDaemon::instance()->attachPin(data);
}
