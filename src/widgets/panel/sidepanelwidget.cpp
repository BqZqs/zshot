// SPDX-License-Identifier: GPL-3.0-or-later
#include "sidepanelwidget.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>

SidePanelWidget::SidePanelWidget(QWidget* parent)
  : QWidget(parent)
  , m_layout(new QVBoxLayout(this))
  , m_toolSizeSpin(new QSpinBox(this))
  , m_toolSizeSlider(new QSlider(Qt::Horizontal, this))
{
    const QStringList presetColors = {
        "#FFFFFF", "#C0C0C0", "#808080", "#000000",
        "#FF0000", "#FF4500", "#FFA500", "#FFFF00",
        "#00FF00", "#00CED1", "#0000FF", "#8A2BE2",
        "#FF69B4", "#FFB6C1", "#8B4513", "#F5F5DC"
    };

    auto* colorGrid = new QGridLayout();
    colorGrid->setSpacing(2);

    for (int i = 0; i < presetColors.size(); ++i) {
        const QColor color(presetColors[i]);
        auto* btn = new QPushButton(this);
        btn->setFixedSize(20, 20);
        btn->setCursor(Qt::PointingHandCursor);
        btn->setProperty("btnColor", color);

        connect(btn, &QPushButton::clicked, this, [this, color]() {
            m_color = color;
            updateColorButtonStyles();
            emit colorChanged(color);
        });

        colorGrid->addWidget(btn, i / 4, i % 4);
        m_colorButtons.append(btn);
    }

    m_layout->addLayout(colorGrid);

    auto* sizeRow = new QHBoxLayout();
    auto* sizeLabel = new QLabel(tr("Tool size:"), this);
    m_toolSizeSpin->setRange(1, maxToolSize);
    m_toolSizeSpin->setSingleStep(1);
    m_toolSizeSlider->setRange(1, maxToolSize);
    m_toolSizeSlider->setMinimumWidth(minSliderWidth);

    sizeRow->addWidget(sizeLabel);
    sizeRow->addWidget(m_toolSizeSpin);
    m_layout->addLayout(sizeRow);
    m_layout->addWidget(m_toolSizeSlider);

    connect(m_toolSizeSpin,
            QOverload<int>::of(&QSpinBox::valueChanged),
            this, &SidePanelWidget::toolSizeChanged);
    connect(m_toolSizeSlider, &QSlider::valueChanged,
            this, &SidePanelWidget::toolSizeChanged);
    connect(this, &SidePanelWidget::toolSizeChanged,
            this, &SidePanelWidget::onToolSizeChanged);

    m_color = QColor("#FF0000");
    updateColorButtonStyles();
}

void SidePanelWidget::onColorChanged(const QColor& color)
{
    m_color = color;
    updateColorButtonStyles();
}

void SidePanelWidget::onToolSizeChanged(int t)
{
    m_toolSize = qBound(0, t, maxToolSize);
    m_toolSizeSlider->setValue(m_toolSize);
    m_toolSizeSpin->setValue(m_toolSize);
}

void SidePanelWidget::updateColorButtonStyles()
{
    for (auto* btn : m_colorButtons) {
        QColor btnColor = btn->property("btnColor").value<QColor>();
        QString border = (btnColor == m_color)
            ? QStringLiteral("2px solid #FFFFFF")
            : QStringLiteral("1px solid #333333");
        btn->setStyleSheet(QStringLiteral(
            "QPushButton { background-color: %1; border: %2; border-radius: 0px; padding: 0px; }"
        ).arg(btnColor.name(), border));
    }
}
