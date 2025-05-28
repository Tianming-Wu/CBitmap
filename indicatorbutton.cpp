#include "indicatorbutton.h"
#include <QPainter>
#include <QStyleOptionButton>
#include <QEvent>
#include <QGuiApplication>

IndicatorButton::IndicatorButton(QWidget *parent)
    : QPushButton(parent)
{
    // 初始图标尺寸
    if(iconSize().isEmpty()) {
        setIconSize(QSize(24, 24));
    }
}

bool IndicatorButton::event(QEvent *e)
{
    if(e->type() == QEvent::PaletteChange) {
        generateIcon();
    }
    return QPushButton::event(e);
}

void IndicatorButton::generateIcon()
{
    QSize pixmapSize = this->iconSize()*4;
    QPixmap result(pixmapSize);
    QPixmap base = m_baseIcon.pixmap(pixmapSize);
    QColor targetColor = palette().color(QPalette::Text);

    result.fill(Qt::transparent);

    QPainter painter(&result);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.drawPixmap(0, 0, base);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(result.rect(), targetColor);

    QPushButton::setIcon(QIcon(result));
}

void IndicatorButton::setIcon(const QIcon &icon)
{
    m_baseIcon = icon;
    generateIcon();
}

void IndicatorButton::setIndicatorStyle(const QColor &color, int width)
{
    m_indicatorColor = color;
    m_indicatorWidth = qBound(1, width, 5);
    update();
}

void IndicatorButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    QStyleOptionButton option;
    initStyleOption(&option);
    style()->drawControl(QStyle::CE_PushButton, &option, &painter, this);

    // 3. 绘制图标（精确居中）
    // if(!m_cachedPixmap.isNull()) {
    //     QSize pixmapSize = m_cachedPixmap.size() / m_cachedPixmap.devicePixelRatio();
    //     QRect iconRect(QPoint(0, 0), pixmapSize.boundedTo(rect().size()));
    //     iconRect.moveCenter(rect().center());

    //     painter.drawPixmap(iconRect, m_cachedPixmap);
    // }

    // 4. 绘制选中指示器
    if(isChecked()) {
        painter.save();

        const int sysRadius = style()->pixelMetric(QStyle::PM_ButtonMargin) / 2;
        const int margin = qMax(2, m_indicatorWidth);
        QRect innerRect = rect().adjusted(margin, margin, -margin, -margin);

        painter.setPen(QPen(m_indicatorColor, m_indicatorWidth));
        painter.setBrush(Qt::NoBrush);

        if(sysRadius > 0) {
            painter.drawRoundedRect(innerRect, sysRadius-1, sysRadius-1);
        } else {
            painter.drawRect(innerRect);
        }

        painter.restore();
    }
}
