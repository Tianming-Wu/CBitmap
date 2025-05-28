#include "mygrar.h"

#include <QEvent>
#include <QWheelEvent>
#include <QScrollBar>
#include <QApplication>
// #include <QPropertyAnimation>

MyGraphicsArea::MyGraphicsArea(QWidget *parent)
    : QGraphicsView(parent)
{
    m_originalCursor = cursor();
}

void MyGraphicsArea::setZoomRange(qreal min, qreal max)
{
    m_minZoom = min;
    m_maxZoom = max;
}

void MyGraphicsArea::resetView()
{
    resetTransform();
    m_currentZoom = 1.0;
    emit zoomChanged(m_currentZoom);
}

void MyGraphicsArea::setViewZoom(qreal zoom)
{
    qreal acturalZoom = qBound(m_minZoom, zoom, m_maxZoom);
    resetTransform();
    scale(acturalZoom, acturalZoom);
    m_currentZoom = acturalZoom;
    emit zoomChanged(m_currentZoom);
}

void MyGraphicsArea::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier) {
        // 计算缩放因子
        const qreal zoomFactor = event->angleDelta().y() > 0 ? 1.1 : 0.9;
        const qreal newZoom = qBound(m_minZoom, m_currentZoom * zoomFactor, m_maxZoom);

        // 基于鼠标位置的缩放
        QPointF oldPos = mapToScene(event->position().toPoint());
        scale(newZoom / m_currentZoom, newZoom / m_currentZoom);

        // QPropertyAnimation *anim = new QPropertyAnimation(this, "zoom");
        // anim->setDuration(100);
        // anim->setStartValue(m_currentZoom);
        // anim->setEndValue(newZoom);
        // anim->start(QAbstractAnimation::DeleteWhenStopped);

        // 调整视图中心保持鼠标位置不变
        QPointF newPos = mapToScene(event->position().toPoint());
        QPointF delta = newPos - oldPos;
        translate(delta.x(), delta.y());

        m_currentZoom = newZoom;
        emit zoomChanged(m_currentZoom);

        event->accept();
    } else if ((event->modifiers() & Qt::ShiftModifier) && (event->angleDelta().y() != 0)) {
        // Shift+滚轮 = 水平滚动
        QWheelEvent fakeEvent(event->position(), event->globalPosition(),
                              event->pixelDelta(), QPoint(event->angleDelta().y(), 0),
                              event->buttons(), event->modifiers()&~Qt::ShiftModifier, event->phase(),
                              event->inverted(), event->source());
        QGraphicsView::wheelEvent(&fakeEvent);
        event->accept();
    } else {
        QGraphicsView::wheelEvent(event); // 普通滚动行为
    }
}

void MyGraphicsArea::mousePressEvent(QMouseEvent *event)
{
    if (event->modifiers() & Qt::AltModifier) {
        // Alt+点击 = 开始拖动视图
        m_isDragging = true;
        m_lastDragPos = event->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        return;
    }

    QGraphicsView::mousePressEvent(event);
}

void MyGraphicsArea::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging) {
        // 处理视图拖动
        QPoint delta = event->pos() - m_lastDragPos;
        m_lastDragPos = event->pos();

        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());

        event->accept();
        return;
    }

    QGraphicsView::mouseMoveEvent(event);
}

void MyGraphicsArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isDragging) {
        m_isDragging = false;
        setCursor(m_originalCursor);
        event->accept();
        return;
    }

    QGraphicsView::mouseReleaseEvent(event);
}
