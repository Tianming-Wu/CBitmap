#pragma once
#include <QPushButton>

class IndicatorButton : public QPushButton
{
    Q_OBJECT
public:
    explicit IndicatorButton(QWidget *parent = nullptr);

    void setIcon(const QIcon &icon);
    void setIndicatorStyle(const QColor &color, int width);

protected:
    void paintEvent(QPaintEvent *) override;
    bool event(QEvent *e) override;

private:
    void generateIcon();

    QColor m_indicatorColor = QColor(30, 144, 255);
    int m_indicatorWidth = 1;

    QIcon m_baseIcon;
};
