// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#include "capturebutton.h"
#include "utils/globalvalues.h"

#include <QGraphicsDropShadowEffect>

CaptureButton::CaptureButton(QWidget* parent)
  : QPushButton(parent)
{
    init();
}

CaptureButton::CaptureButton(const QString& text, QWidget* parent)
  : QPushButton(text, parent)
{
    init();
}

CaptureButton::CaptureButton(const QIcon& icon,
                             const QString& text,
                             QWidget* parent)
  : QPushButton(icon, text, parent)
{
    init();
}

void CaptureButton::init()
{
    setCursor(Qt::ArrowCursor);
    setFocusPolicy(Qt::NoFocus);

    auto* dsEffect = new QGraphicsDropShadowEffect(this);
    dsEffect->setBlurRadius(5);
    dsEffect->setOffset(0);
    dsEffect->setColor(QColor(Qt::black));

    setGraphicsEffect(dsEffect);
}

QString CaptureButton::globalStyleSheet()
{
    return CaptureButton(nullptr).styleSheet();
}

QString CaptureButton::styleSheet() const
{
    // Pixel-style pink theme: flat colors, square corners, monospace
    QString baseSheet =
      "CaptureButton {"
      "  border: 2px solid #FF69B4;"
      "  padding: 3px 8px;"
      "  background-color: #FFB6C1;"
      "  color: #4A0030;"
      "  font-family: monospace;"
      "  border-radius: 0px;"
      "}"
      "CaptureButton:hover {"
      "  background-color: #FF91A4;"
      "}"
      "CaptureButton:pressed {"
      "  background-color: #FF69B4;"
      "  color: #FFFFFF;"
      "}"
      "CaptureToolButton {"
      "  border-radius: 0px;"
      "  padding: 0;"
      "}";
    return baseSheet;
}

void CaptureButton::setColor(const QColor& c)
{
    m_mainColor = c;
    setStyleSheet(styleSheet());
}

QColor CaptureButton::m_mainColor = QColor("#FFB6C1");
