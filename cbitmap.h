#pragma once

#include <QWidget>
#include <QVector>
#include <QUndoStack>
#include <QUndoCommand>


class BitmapCommand;

class CBitmap : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QSize bitmapSize READ bitmapSize WRITE setBitmapSize NOTIFY bitmapSizeChanged)
    Q_PROPERTY(PenMode penMode READ penMode WRITE setPenMode NOTIFY penModeChanged)
    Q_PROPERTY(FillMode fillMode READ fillMode WRITE setFillMode NOTIFY fillModeChanged)
    Q_PROPERTY(ActionMode actionMode READ actionMode WRITE setActionMode NOTIFY actionModeChanged)
    Q_PROPERTY(bool showGrid READ showGrid WRITE setShowGrid NOTIFY showGridChanged)

    friend class BitmapCommand;

public:
    explicit CBitmap(QWidget *parent = nullptr);
    explicit CBitmap(int width, int height, QWidget *parent = nullptr);
    explicit CBitmap(const QSize& size, QWidget *parent = nullptr);
    ~CBitmap();

    // 二值位图数据结构
    struct Frame {
        QVector<bool> data;
        QSize size;

        Frame(){}
        Frame(const QSize& size):data(QVector<bool>(size.width()*size.height(), false)), size(size) {}

        inline void clear() { data.fill(false); }
        inline bool& at(int x, int y) { return data[y * size.width() + x]; }
        inline const bool& at(int x, int y) const { return data[y * size.width() + x]; }
        inline const bool& at(int id) const { return data[id]; }
        inline qsizetype length() const { return data.size(); }

        Frame& operator+=(const Frame& merge) {
            for(int i = 0; i < length(); i++)
                data[i] = ( data[i] || merge.at(i) );
            return *this;
        }

        Frame& operator-=(const Frame& merge) {
            for(int i = 0; i < length(); i++)
                data[i] = merge.at(i) ? false : data[i];
            return *this;
        }
    };

    enum PenMode {
        PenNone, PenFree, PenLine, PenRectangle, PenCircle
    };
    Q_ENUM(PenMode)

    enum FillMode {
        FillNone, FillSolid, FillAlternate
    };
    Q_ENUM(FillMode)

    enum ActionMode {
        ActionNone, ActionPen, ActionEraser, ActionSelection
    };
    Q_ENUM(ActionMode)

    // 导出数据为单片机可用的格式
    QVector<uint8_t> exportToByteArray() const;
    QVector<uint32_t> exportToUInt32Array() const;
    QByteArray exportToByteArrayPadded() const;

    // 属性访问
    QSize bitmapSize() const { return m_frame.size; }
    PenMode penMode() const { return m_penMode; }
    FillMode fillMode() const { return m_fillMode; }
    ActionMode actionMode() const { return m_actionMode; }
    bool showGrid() const { return m_showGrid; }

    bool loadFrame(const Frame& frame);

    QRect validGeometry(const QRect& orig) const;
    QRect generateGeometry() const;
    QRect generateSceneRect() const;

    QUndoStack* undoStack() { return m_undoStack; }

public slots:
    void clear();
    void setBitmapSize(const QSize& size);
    void setPenMode(PenMode penMode);
    void setFillMode(FillMode fillMode);
    void setActionMode(ActionMode actionMode);
    void setShowGrid(bool showGrid);

signals:
    void bitmapSizeChanged(QSize);
    void penModeChanged(PenMode);
    void fillModeChanged(FillMode);
    void actionModeChanged(ActionMode);
    void showGridChanged(bool);
    void cursorUpdated(const QString& status);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    // void resizeEvent(QResizeEvent *event) override;

private: // Functions
    // 绘制算法
    void drawPixel(int x, int y);
    void drawLine(const QPoint& p1, const QPoint& p2);
    void drawRectangle(const QPoint& p1, const QPoint& p2);
    void drawCircle(const QPoint& center, int radius);

    QString formatPosition(const QPoint& pos) const;
    QString formatLine(const QPoint& p1, const QPoint& p2) const;
    QString formatRect(const QPoint& p1, const QPoint& p2) const;
    QString formatCircle(const QPoint& center, const QPoint& edge) const;
    void updateStatus(const QString& status);

    void mergePreview();

    void general_Init();

    QPoint widgetToBitmapPos(const QPoint& pos) const;

private: // Members

    // Frame Storage
    Frame m_frame;
    Frame m_previewFrame;

    // Visibiliy options
    QColor m_onColor = Qt::white;
    QColor m_offColor = Qt::black;
    QColor m_gridColor = QColor(80, 80, 80);
    bool m_showGrid = true;

    // Pen / Fill
    PenMode m_penMode = PenFree;
    FillMode m_fillMode = FillNone;
    ActionMode m_actionMode = ActionPen;

    // Drawing
    bool m_isDrawing = false;
    QPoint m_lastPos;
    QPoint m_startPos; // 用于形状绘制

    // Undo
    QUndoStack* m_undoStack;
    void saveState();
    void restoreFrame(const Frame& frame);
    Frame m_lastState;

    // Mouse Status
    QString m_lastStatus;
    bool m_statusChanged = false;

    // Buffering
    QPixmap m_bufferPixmap;
};


class BitmapCommand : public QUndoCommand {
public:
    BitmapCommand(CBitmap::Frame before, CBitmap::Frame after, CBitmap* bitmap)
        : m_before(before), m_after(after), m_bitmap(bitmap) {}

    void undo() override { m_bitmap->restoreFrame(m_before); }
    void redo() override { m_bitmap->restoreFrame(m_after); }

private:
    CBitmap::Frame m_before;
    CBitmap::Frame m_after;
    CBitmap* m_bitmap;
};
