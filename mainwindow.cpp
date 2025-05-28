#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "cbitmap.h"
#include "mygrar.h"
#include "interpreter.h"
#include "codeexportdialog.h"
#include "importdialog.h"
#include "iconhandler.h"
#include "imageinfodialog.h"

#include <QWheelEvent>
#include <QGraphicsProxyWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , cbitmap(new CBitmap), scene(new QGraphicsScene(this))
    , iconHandler(new IconHandler(this))
{
    ui->setupUi(this);
    view = ui->graphicsView;

    // UI Components
    scene->setSceneRect(QRect(0, 0, 50, 50));
    view->setScene(scene);

    view->setZoomRange(0.1, 10.0);

    ui->pb_5->hide();

    // view->installEventFilter(this); // Now use Promoted widget, so no longer required
    // view->viewport()->installEventFilter(this);
    // std::invoke(&QAbstractScrollArea::installEventFilter, view, this);

    proxy = scene->addWidget(cbitmap);

    ui->cbxPenMode->addItem(iconHandler->generateIcon("://line_stripped", 25, 25), "Free", CBitmap::PenFree);
    ui->cbxPenMode->addItem(iconHandler->generateIcon("://line", 25, 25), "Line", CBitmap::PenLine);
    ui->cbxPenMode->addItem(iconHandler->generateIcon("://rectangle", 25, 25), "Rectangle", CBitmap::PenRectangle);
    ui->cbxPenMode->addItem(iconHandler->generateIcon("://circle", 25, 25), "Circle", CBitmap::PenCircle);

    ui->cbxFillMode->addItem(iconHandler->generateIcon("://rectangle", 25, 25), "None", CBitmap::FillNone);
    ui->cbxFillMode->addItem(iconHandler->generateIcon("://rectangle_filled", 25, 25), "Solid", CBitmap::FillSolid);
    // ui->cbxFillMode->addItem("Alternate", CBitmap::FillAlternate); // Wasn't complete

    // Optimization
    view->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

    // Draw / Erase
    connect(ui->pbPen, &QPushButton::clicked, this, [&]{
        ui->pbPen->setChecked(true); ui->pbEraser->setChecked(false);
        cbitmap->setActionMode(CBitmap::ActionPen);
    });

    connect(ui->pbEraser, &QPushButton::clicked, this, [&]{
        ui->pbPen->setChecked(false); ui->pbEraser->setChecked(true);
        cbitmap->setActionMode(CBitmap::ActionEraser);
    });

    connect(ui->cbxPenMode, &QComboBox::currentIndexChanged, this, [&]{
        cbitmap->setPenMode(static_cast<CBitmap::PenMode>(ui->cbxPenMode->currentData().toInt()));
    });
    connect(ui->cbxFillMode, &QComboBox::currentIndexChanged, this, [&]{
        cbitmap->setFillMode(static_cast<CBitmap::FillMode>(ui->cbxFillMode->currentData().toInt()));
    });

    // Undo & Redo
    connect(ui->pbUndo, &QPushButton::clicked, cbitmap->undoStack(), &QUndoStack::undo);
    connect(ui->pbRedo, &QPushButton::clicked, cbitmap->undoStack(), &QUndoStack::redo);
    connect(cbitmap->undoStack(), &QUndoStack::canUndoChanged, ui->pbUndo, &QPushButton::setEnabled);
    connect(cbitmap->undoStack(), &QUndoStack::canRedoChanged, ui->pbRedo, &QPushButton::setEnabled);

    // View
    connect(ui->pbResetView, &QPushButton::clicked, this, [&](){
        view->resetTransform();
        view->centerOn(proxy);
        m_currentScale = DEFAULT_SCALE;
        updateZoomLabel(view->currentZoom());
    });

    connect(cbitmap, &CBitmap::bitmapSizeChanged, this, &MainWindow::updateView);
    connect(cbitmap, &CBitmap::bitmapSizeChanged, this, &MainWindow::updateResolutionLabel);
    connect(cbitmap, &CBitmap::cursorUpdated, this, [&](const QString& status){
        ui->lbCBitmapStatus->setText(status);
    });

    connect(view, &MyGraphicsArea::zoomChanged, this, &MainWindow::updateZoomLabel);

    // Info Dialog
    connect(ui->pbImageInfo, &QPushButton::clicked, this, [&]{
        ImageInfoDialog dialog(cbitmap, this);
        dialog.exec();
    });

    // Save & Load
    connect(ui->pbExport, &QPushButton::clicked, this, [&] {
        Interpreter interpreter(cbitmap);
        CodeExportDialog dialog(interpreter, CodeExportDialog::ExportMode, this);
        dialog.exec();
    });
    connect(ui->pbImport, &QPushButton::clicked, this, [&] {
        Interpreter interpreter(cbitmap);
        CodeExportDialog dialog(interpreter, CodeExportDialog::ImportMode, this);
        dialog.exec();
    });

    connect(ui->pbImportImage, &QPushButton::clicked, this, [&] {
        ImportDialog dialog(cbitmap, this);
        dialog.exec();
    });

    // connect(view, &QGraphicsView::
    // view->transform().m11() > 2.0)


    // Post Initialize

    cbitmap->setBitmapSize(QSize(128, 64));
    updateView();

    ui->pbUndo->setEnabled(cbitmap->undoStack()->canUndo());
    ui->pbRedo->setEnabled(cbitmap->undoStack()->canRedo());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateView()
{
    scene->setSceneRect(cbitmap->generateSceneRect());
    proxy->setGeometry(cbitmap->generateGeometry());
    // qDebug() << cbitmap->generateSceneRect() << cbitmap->generateGeometry();
    view->resetTransform();
    view->centerOn(proxy);
}

void MainWindow::updateResolutionLabel(const QSize &size)
{
    ui->lbResolution->setText(QString("%1*%2").arg(size.width()).arg(size.height()));
}

void MainWindow::updateZoomLabel(qreal zoom)
{
    // The first step in rendering was already 400%
    ui->lbZoom->setText(QString::number(static_cast<int>(zoom*400)) + "%");
}

// bool MainWindow::eventFilter(QObject *object, QEvent *event)
// {
//     if (event->type() == QEvent::Wheel && object == view) {
//         QWheelEvent *wheelEvent = static_cast<QWheelEvent*>(event);
//         qDebug() << QString("wheelEvent catched%1").arg((wheelEvent->modifiers() & Qt::ControlModifier)?" with modifier":"");
//         if (wheelEvent->modifiers() & Qt::ControlModifier) {
//             // 计算缩放因子
//             qreal zoomFactor = (wheelEvent->angleDelta().y() > 0) ? 1.1 : 0.9;

//             // 计算新缩放比例
//             qreal newScale = m_currentScale * zoomFactor;
//             newScale = qBound(MIN_SCALE, newScale, MAX_SCALE);

//             // 计算相对于鼠标位置的缩放
//             QPointF oldPos = view->mapToScene(wheelEvent->position().toPoint());
//             view->scale(newScale / m_currentScale, newScale / m_currentScale);

//             // 调整视图中心以保持鼠标位置不变
//             QPointF newPos = view->mapToScene(wheelEvent->position().toPoint());
//             QPointF delta = newPos - oldPos;
//             view->translate(delta.x(), delta.y());

//             m_currentScale = newScale;
//             updateZoomLabel();

//             return true; // 阻止事件继续传播
//         }
//     }
//     return QMainWindow::eventFilter(object, event);
// }
