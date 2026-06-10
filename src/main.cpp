// SPDX-License-Identifier: GPL-3.0-or-later
#include "core/capturerequest.h"
#include "core/zshot.h"
#include "widgets/capture/capturewidget.h"

#include <QApplication>

Q_DECLARE_METATYPE(QList<int>)

int main(int argc, char* argv[])
{
    qRegisterMetaType<QList<int>>();

    QApplication app(argc, argv);
    app.setApplicationVersion(APP_VERSION);
    app.setApplicationName(QStringLiteral("zshot"));
    app.setOrganizationName(QStringLiteral("zshot"));

#if defined(Q_OS_WIN) && QT_VERSION >= QT_VERSION_CHECK(6, 5, 0)
    app.setStyle("Fusion");
#endif

    Zshot* zshot = Zshot::instance();

    QObject::connect(zshot, &Zshot::captureTaken, &app, [&app](const QPixmap&) {
        app.exit(E_OK);
    });
    QObject::connect(zshot, &Zshot::captureFailed, &app, [&app]() {
        app.exit(E_ABORTED);
    });

    if (!zshot->gui(CaptureRequest(CaptureRequest::GRAPHICAL_MODE))) {
        return E_ABORTED;
    }

    return app.exec();
}
