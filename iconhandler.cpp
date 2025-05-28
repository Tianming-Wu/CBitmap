#include "iconhandler.h"

#include <QPainter>
#include <QPalette>
#include <QEvent>

IconHandler::IconHandler(QWidget *parent)
    : QWidget{parent}
{
    setAttribute(Qt::WA_WState_Visible, false);
}

QIcon IconHandler::generateIcon(const QIcon &base, QSize size)
{
    QSize pixmapSize = size*4;
    QPixmap result(pixmapSize);
    QPixmap basepm = base.pixmap(pixmapSize);
    QColor targetColor = palette().color(QPalette::Text);

    result.fill(Qt::transparent);

    QPainter painter(&result);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.drawPixmap(0, 0, basepm);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(result.rect(), targetColor);

    return QIcon(result);
}

QIcon IconHandler::generateIcon(const QString &respath, int width, int height)
{
    return generateIcon(QIcon(respath), QSize(width, height));
}

void IconHandler::bindItem(const HandlerObject &obj)
{

}

void IconHandler::bindItem(QWidget *ref, QIcon baseIcon)
{

}

bool IconHandler::event(QEvent* e)
{
    if(e->type() == QEvent::PaletteChange) {
        // Not completed yet
    }
    return QWidget::event(e);
}

void IconHandler::updateIcons()
{

}
