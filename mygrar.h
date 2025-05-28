#pragma once

#include <QGraphicsView>

class MyGraphicsArea : public QGraphicsView
{
    Q_OBJECT
public:
    MyGraphicsArea(QWidget *parent = nullptr);

    void setZoomRange(qreal min, qreal max);
    qreal currentZoom() const { return m_currentZoom; }

public slots:
    void resetView();
    void setViewZoom(qreal zoom);

signals:
    void zoomChanged(qreal zoomLevel);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    qreal m_minZoom = 0.1;
    qreal m_maxZoom = 10.0;
    qreal m_currentZoom = 1.0;

    bool m_isDragging = false;
    QPoint m_lastDragPos;
    QCursor m_originalCursor;
};
