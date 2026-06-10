// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include <QSpinBox>
#include <QVector>
#include <QWidget>

class QVBoxLayout;
class QPushButton;
class QSlider;

constexpr int maxToolSize = 50;
constexpr int minSliderWidth = 100;

class SidePanelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SidePanelWidget(QWidget* parent = nullptr);

signals:
    void colorChanged(const QColor& color);
    void toolSizeChanged(int size);

public slots:
    void onToolSizeChanged(int tool);
    void onColorChanged(const QColor& color);

private:
    void updateColorButtonStyles();

    QVBoxLayout* m_layout;
    QSpinBox* m_toolSizeSpin;
    QSlider* m_toolSizeSlider;
    int m_toolSize{};
    QColor m_color;
    QVector<QPushButton*> m_colorButtons;
};
