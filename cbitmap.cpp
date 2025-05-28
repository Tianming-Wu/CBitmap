#include "cbitmap.h"

#include <QPainter>
#include <QMouseEvent>
#include <cmath>
#include <functional>

CBitmap::CBitmap(QWidget *parent)
    : QWidget(parent), m_undoStack(new QUndoStack(this))
{
    setBitmapSize(QSize(128, 64)); // 默认大小，适合OLED
    general_Init();
}

CBitmap::CBitmap(int width, int height, QWidget *parent)
    : QWidget(parent), m_undoStack(new QUndoStack(this))
{
    setBitmapSize(QSize(width, height));
    general_Init();
}

CBitmap::CBitmap(const QSize& size, QWidget *parent)
    : QWidget(parent), m_undoStack(new QUndoStack(this))
{
    setBitmapSize(size);
    general_Init();
}

CBitmap::~CBitmap() {}

void CBitmap::setBitmapSize(const QSize& size)
{
    if (size == m_frame.size) return;

    m_frame.size = size;
    m_frame.data.resize(size.width() * size.height());
    m_frame.data.fill(false);

    m_previewFrame.size = size;
    m_previewFrame.data.resize(size.width() * size.height());
    m_previewFrame.data.fill(false);

    m_lastState.size = size;
    m_lastState.data.resize(size.width() * size.height());
    m_lastState.data.fill(false);

    m_undoStack->clear();
    // saveState(); // 将空白状态作为第一个有效状态

    emit bitmapSizeChanged(size);
    update();
}

void CBitmap::clear()
{
    m_frame.clear();
    update();
}

QVector<uint8_t> CBitmap::exportToByteArray() const
{
    // 现在也使用高位在前的格式
    QVector<uint8_t> result;
    const int totalBits = m_frame.data.size();
    result.reserve((totalBits + 7) / 8);

    uint8_t currentByte = 0;
    int bitPos = 0;

    for (bool bit : m_frame.data) {
        if (bit) {
            currentByte |= (1 << (7 - bitPos)); // 高位在前
        }

        if (++bitPos == 8) {
            result.append(currentByte);
            currentByte = 0;
            bitPos = 0;
        }
    }

    if (bitPos != 0) {
        result.append(currentByte);
    }

    return result;
}

QVector<uint32_t> CBitmap::exportToUInt32Array() const
{
    QVector<uint32_t> result;
    result.reserve((m_frame.data.size() + 31) / 32);

    uint32_t currentWord = 0;
    int bitPos = 0;

    for (bool bit : m_frame.data) {
        if (bit) {
            currentWord |= (1 << (31 - bitPos));
        }

        if (++bitPos == 32) {
            result.append(currentWord);
            currentWord = 0;
            bitPos = 0;
        }
    }

    if (bitPos != 0) {
        result.append(currentWord);
    }

    return result;
}

QByteArray CBitmap::exportToByteArrayPadded() const
{
    const int width = m_frame.size.width();
    const int height = m_frame.size.height();
    const int bytesPerRow = (width + 7) / 8; // 计算每行需要的字节数

    QByteArray result;
    result.resize(bytesPerRow * height, 0x00);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (m_frame.at(x, y)) {
                int byteIndex = y * bytesPerRow + x / 8;
                int bitIndex = 7 - (x % 8); // 高位在前
                result[byteIndex] |= (1 << bitIndex);
            }
        }
    }

    return result;
}

bool CBitmap::loadFrame(const Frame &frame)
{
    // 检查数据尺寸是否匹配
    if (frame.size.width() * frame.size.height() != frame.data.size()) {
        qWarning() << "Frame data size does not match dimensions";
        return false;
    }

    m_undoStack->clear();

    // 设置新尺寸并复制数据
    setBitmapSize(frame.size);
    m_frame.data = frame.data;

    // 触发重绘
    update();
    return true;
}

QRect CBitmap::validGeometry(const QRect& orig) const
{
    // 保持位图宽高比
    qreal aspectRatio = static_cast<qreal>(m_frame.size.width()) / m_frame.size.height();
    int width = orig.width();
    int height = static_cast<int>(width / aspectRatio);

    // 如果计算的高度超过可用高度，则重新计算
    if (height > orig.height()) {
        height = orig.height();
        width = static_cast<int>(height * aspectRatio);
    }

    return QRect(orig.topLeft(), QSize(width, height));
}

QRect CBitmap::generateGeometry() const
{
    return QRect(2*bitmapSize().width(), 2*bitmapSize().height(), 4*bitmapSize().width(), 4*bitmapSize().height());
}

QRect CBitmap::generateSceneRect() const
{
    return QRect(0, 0, 8*bitmapSize().width(), 8*bitmapSize().height());
}

void CBitmap::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // 绘制背景
    painter.fillRect(rect(), m_offColor);

    // 计算每个像素的显示大小
    qreal pixelWidth = width() / static_cast<qreal>(m_frame.size.width());
    qreal pixelHeight = height() / static_cast<qreal>(m_frame.size.height());

    painter.setPen(Qt::NoPen);

    std::function<void(QPainter&,int,int)> paintPixel = [&](QPainter& painter, int x, int y) {
        QRectF pixelRect(x * pixelWidth, y * pixelHeight, pixelWidth, pixelHeight);
        painter.drawRect(pixelRect);
    };


    if(!m_isDrawing) {
        m_bufferPixmap = QPixmap(this->size());
        QPainter bufPainter(&m_bufferPixmap);
        bufPainter.fillRect(rect(), m_offColor);
        bufPainter.setPen(Qt::NoPen);
        bufPainter.setBrush(m_onColor);

        for (int y = 0; y < m_frame.size.height(); ++y) {
            for (int x = 0; x < m_frame.size.width(); ++x) {
                if (m_frame.at(x, y)) paintPixel(bufPainter, x, y);
            }
        }
        painter.drawPixmap(QRect(QPoint(0,0), m_bufferPixmap.size()), m_bufferPixmap);
    } else { // Stack Preview Above
        painter.drawPixmap(QRect(QPoint(0,0), m_bufferPixmap.size()), m_bufferPixmap);
        switch(m_actionMode) {
        case ActionPen:
            painter.setBrush(m_onColor);
            painter.setOpacity(0.5);
            for (int y = 0; y < m_previewFrame.size.height(); ++y) {
                for (int x = 0; x < m_previewFrame.size.width(); ++x) {
                    if (m_previewFrame.at(x, y)) paintPixel(painter, x, y);
                }
            }
            painter.setOpacity(1.0);
            break;

        case ActionEraser:
            painter.setBrush(m_offColor);
            painter.setOpacity(0.5);
            for (int y = 0; y < m_previewFrame.size.height(); ++y) {
                for (int x = 0; x < m_previewFrame.size.width(); ++x) {
                    if (m_previewFrame.at(x, y)) paintPixel(painter, x, y);
                }
            }
            painter.setOpacity(1.0);
            break;

        case ActionSelection:
            break;

        default:
            break;
        }
    }

    // 绘制网格线
    if(m_showGrid) {
        // painter.drawPixmap(QRect(QPoint(0,0), m_gridPixmap.size()), m_gridPixmap);
        painter.setPen(QPen(m_gridColor, 0.5));
        for (int x = 0; x <= m_frame.size.width(); ++x) {
            painter.drawLine(
                QPointF(x * pixelWidth, 0),
                QPointF(x * pixelWidth, height())
                );
        }
        for (int y = 0; y <= m_frame.size.height(); ++y) {
            painter.drawLine(
                QPointF(0, y * pixelHeight),
                QPointF(width(), y * pixelHeight)
                );
        }
    };
}

QPoint CBitmap::widgetToBitmapPos(const QPoint& pos) const
{
    if (m_frame.size.width() <= 0 || m_frame.size.height() <= 0) {
        return QPoint(0, 0); // 或抛出异常
    }
    int x = pos.x() * m_frame.size.width() / width();
    int y = pos.y() * m_frame.size.height() / height();

    // 确保坐标在有效范围内
    x = qBound(0, x, m_frame.size.width() - 1);
    y = qBound(0, y, m_frame.size.height() - 1);

    return QPoint(x, y);
}

void CBitmap::saveState()
{
    if(m_frame.data != m_lastState.data) {
        m_undoStack->push(new BitmapCommand(m_lastState, m_frame, this));
        m_lastState = m_frame;
    }
}

void CBitmap::restoreFrame(const Frame &frame)
{
    if (frame.size.isEmpty()) return;
    m_lastState = m_frame = frame;
    update();
}

void CBitmap::drawPixel(int x, int y)
{
    if (x >= 0 && x < m_frame.size.width() &&
        y >= 0 && y < m_frame.size.height()) {
        m_previewFrame.at(x, y) = true; // Even if it is in eraser mode. See mergePreview().
        update();
    }
}

void CBitmap::drawLine(const QPoint& p1, const QPoint& p2)
{
    // Bresenham算法
    int x0 = p1.x(), y0 = p1.y();
    int x1 = p2.x(), y1 = p2.y();

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (true) {
        drawPixel(x0, y0);
        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void CBitmap::drawRectangle(const QPoint& p1, const QPoint& p2)
{
    int x1 = qMin(p1.x(), p2.x());
    int x2 = qMax(p1.x(), p2.x());
    int y1 = qMin(p1.y(), p2.y());
    int y2 = qMax(p1.y(), p2.y());

    switch(m_fillMode){
    case FillSolid: // 填充矩形
        for (int y = y1; y <= y2; ++y) {
            for (int x = x1; x <= x2; ++x) {
                drawPixel(x, y);
            }
        }
        break;
    case FillNone: // 只绘制边框
        for (int x = x1; x <= x2; ++x) {
            drawPixel(x, y1);
            drawPixel(x, y2);
        }
        for (int y = y1 + 1; y < y2; ++y) {
            drawPixel(x1, y);
            drawPixel(x2, y);
        }
        break;
    case FillAlternate:
        // A little bit tricky...
        break;
    }
}

void CBitmap::drawCircle(const QPoint& center, int radius)
{
    if (radius < 0) return;

    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        // 绘制8个对称点
        drawPixel(center.x() + x, center.y() + y);
        drawPixel(center.x() + y, center.y() + x);
        drawPixel(center.x() - y, center.y() + x);
        drawPixel(center.x() - x, center.y() + y);
        drawPixel(center.x() - x, center.y() - y);
        drawPixel(center.x() - y, center.y() - x);
        drawPixel(center.x() + y, center.y() - x);
        drawPixel(center.x() + x, center.y() - y);

        // 改进的判断条件
        if (err <= 0) {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }
    }
    if (m_fillMode == FillSolid) {
        // 优化的填充算法 - 只填充有效区域
        for (int dy = -radius; dy <= radius; ++dy) {
            for (int dx = -radius; dx <= radius; ++dx) {
                // 检查是否在圆内 (使用平方比较避免sqrt)
                if (dx*dx + dy*dy <= radius*radius) {
                    drawPixel(center.x() + dx, center.y() + dy);
                }
            }
        }
    }

    // if (m_fillMode == FillNone) {
    //     for (int i = -radius; i <= radius; i++) {
    //         drawPixel(center.x() + i, center.y()); // 水平轴
    //         drawPixel(center.x(), center.y() + i); // 垂直轴
    //     }
    // }
}
// {
//     int x0 = center.x();
//     int y0 = center.y();
//     int x = radius;
//     int y = 0;
//     int err = 0;

//     while (x >= y) {
//         drawPixel(x0 + x, y0 + y);
//         drawPixel(x0 + y, y0 + x);
//         drawPixel(x0 - y, y0 + x);
//         drawPixel(x0 - x, y0 + y);
//         drawPixel(x0 - x, y0 - y);
//         drawPixel(x0 - y, y0 - x);
//         drawPixel(x0 + y, y0 - x);
//         drawPixel(x0 + x, y0 - y);

//         if (err <= 0) {
//             y += 1;
//             err += 2 * y + 1;
//         }
//         if (err > 0) {
//             x -= 1;
//             err -= 2 * x + 1;
//         }
//     }

//     // 填充圆形
//     if (m_fillMode == FillSolid) {
//         for (int y = -radius; y <= radius; ++y) {
//             for (int x = -radius; x <= radius; ++x) {
//                 if (x*x + y*y <= radius*radius) {
//                     drawPixel(x0 + x, y0 + y);
//                 }
//             }
//         }
//     }
// }

void CBitmap::mergePreview()
{
    switch(m_actionMode) {
    case ActionPen:
        m_frame += m_previewFrame;
        m_previewFrame.clear();
        saveState();
        break;
    case ActionEraser:
        m_frame -= m_previewFrame;
        m_previewFrame.clear();
        saveState();
        break;
    default:
        break;
    }
    update();
}

void CBitmap::general_Init()
{
    // setAttribute(Qt::WA_TransparentForMouseEvents, false); // 确保不阻止鼠标事件? (originally false)
    setFocusPolicy(Qt::NoFocus);
    m_undoStack->setUndoLimit(15);
    clear();
}

void CBitmap::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDrawing = true;
        // setMouseTracking(true);
        m_startPos = m_lastPos = widgetToBitmapPos(event->pos());
        QString status;

        switch (m_penMode) {
        case PenFree:
            drawPixel(m_lastPos.x(), m_lastPos.y());
        case PenLine:
        case PenRectangle:
        case PenCircle:
            status = formatPosition(m_startPos);
            break;
        default:
            break;
        }
        updateStatus(status);
    }
}

void CBitmap::mouseMoveEvent(QMouseEvent *event)
{
    QPoint currentPos = widgetToBitmapPos(event->pos());
    QString status;

    if (m_isDrawing) {

        switch (m_penMode) {
        case PenFree:
            status = formatPosition(currentPos);
            drawLine(m_lastPos, currentPos);
            m_lastPos = currentPos;
            break;
        case PenLine:
            status = formatLine(m_startPos, currentPos);
            m_previewFrame.clear();
            drawLine(m_startPos, currentPos);
            break;
        case PenRectangle:
            status = formatRect(m_startPos, currentPos);
            m_previewFrame.clear();
            drawRectangle(m_startPos, currentPos);
            break;
        case PenCircle: {
            status = formatCircle(m_startPos, currentPos);
            m_previewFrame.clear();
            int radius = static_cast<int>(std::sqrt(
                std::pow(currentPos.x() - m_startPos.x(), 2) +
                std::pow(currentPos.y() - m_startPos.y(), 2)
                ));
            drawCircle(m_startPos, radius);
            break;
        }
        default:
            break;
        }
    } else {
        if (!(event->modifiers() & Qt::AltModifier)) status = formatPosition(currentPos);
    }

    updateStatus(status);
}

void CBitmap::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_isDrawing) {
        mouseMoveEvent(event);
        // setMouseTracking(false);
        updateStatus(formatPosition(widgetToBitmapPos(event->pos())));
        m_isDrawing = false;
        mergePreview();
    }
}

void CBitmap::enterEvent(QEnterEvent *event)
{
    setMouseTracking(true);
    // updateStatus(formatPosition(widgetToBitmapPos(cursor().pos())));
    // updateStatus(formatPosition(widgetToBitmapPos(event->position())));
    QWidget::enterEvent(event);
}

void CBitmap::leaveEvent(QEvent *event)
{
    setMouseTracking(false);
    updateStatus(""); // 清空状态
    QWidget::leaveEvent(event);
}

// void CBitmap::resizeEvent(QResizeEvent *event)
// {
//     return QWidget::resizeEvent(event);
// }

QString CBitmap::formatPosition(const QPoint& pos) const {
    return QString("(%1, %2)").arg(pos.x()).arg(pos.y());
}

QString CBitmap::formatLine(const QPoint& p1, const QPoint& p2) const {
    return QString("%1->%2")
        .arg(formatPosition(p1))
        .arg(formatPosition(p2));
}

QString CBitmap::formatRect(const QPoint& p1, const QPoint& p2) const {
    int width = abs(p2.x() - p1.x()) + 1;
    int height = abs(p2.y() - p1.y()) + 1;
    return QString("%1, %2x%3")
        .arg(formatLine(p1, p2))
        .arg(width).arg(height);
}

QString CBitmap::formatCircle(const QPoint& center, const QPoint& edge) const {
    int dx = edge.x() - center.x();
    int dy = edge.y() - center.y();
    int radius = static_cast<int>(sqrt(dx*dx + dy*dy));
    return QString("%1, r=%2")
        .arg(formatLine(center, edge))
        .arg(radius);
}

void CBitmap::updateStatus(const QString& status) {
    if (status != m_lastStatus) {
        m_lastStatus = status;
        emit cursorUpdated(status);
    }
}

void CBitmap::setPenMode(PenMode penMode) { emit penModeChanged((m_penMode = penMode)); }
void CBitmap::setFillMode(FillMode fillMode) { emit fillModeChanged((m_fillMode = fillMode)); }
void CBitmap::setActionMode(ActionMode actionMode) { emit actionModeChanged((m_actionMode = actionMode)); }
void CBitmap::setShowGrid(bool showGrid) { emit showGridChanged((m_showGrid = showGrid)); update(); }
