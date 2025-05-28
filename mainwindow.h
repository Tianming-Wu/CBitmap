#pragma once

#include <QMainWindow>
#include <QGraphicsScene>

class CBitmap;
class MyGraphicsArea;
class IconHandler;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateView();
    void updateResolutionLabel(const QSize& size);
    void updateZoomLabel(qreal zoom);

// protected:
//     bool eventFilter(QObject *object, QEvent *event);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    MyGraphicsArea *view;
    CBitmap *cbitmap;
    QGraphicsProxyWidget *proxy;

    const qreal MIN_SCALE = 0.1;
    const qreal MAX_SCALE = 10.0;
    const qreal DEFAULT_SCALE = 1.0;
    qreal m_currentScale = DEFAULT_SCALE;

    IconHandler *iconHandler;
};
