#include "importdialog.h"
#include "ui_importdialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QImageReader>
#include <QSvgRenderer>
#include <QPainter>
#include <QGraphicsProxyWidget>

// #include <QLibraryInfo>

ImportDialog::ImportDialog(CBitmap *cbitmap, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ImportDialog)
    , m_cbitmap(cbitmap), scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    view = ui->graphicsView;

    lbPreview = new QLabel;

    scene->setSceneRect(QRect(0, 0, 32, 32));
    view->setScene(scene);
    view->setZoomRange(0.25, 10.0);
    proxy = scene->addWidget(lbPreview);

    connect(ui->spnWidth, QOverload<int>::of(&QSpinBox::valueChanged), this, &ImportDialog::onSizeChanged);
    connect(ui->spnHeight, QOverload<int>::of(&QSpinBox::valueChanged), this, &ImportDialog::onSizeChanged);
    connect(ui->btnOpen, &QPushButton::clicked, this, &ImportDialog::onOpenClicked);
    connect(ui->btnImport, &QPushButton::clicked, this, &ImportDialog::onImportClicked);

    updateScene();
}

ImportDialog::~ImportDialog()
{
    delete ui;
}

void ImportDialog::onOpenClicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                "Open Image", "",
                                                "Images (*.png *.bmp *.svg *.jpg *.jpeg)");

    if(path.isEmpty()) return;

    // Load image
    QImage img;
    if(path.endsWith(".svg", Qt::CaseInsensitive)){
        QSvgRenderer renderer(path);
        if (!renderer.isValid()) {
            QMessageBox::warning(this, "Error", "Failed to load SVG file");
            return;
        }
        img = QImage(renderer.defaultSize(), QImage::Format_ARGB32);
        img.fill(Qt::transparent);
        QPainter painter(&img);
        renderer.render(&painter);
    } else {
        img = QImage(path);
        if(img.isNull()) {
            QMessageBox::warning(this, "Error", "Failed to load image");
            return;
        }
    }

    // Set initial size (must do this before format check)
    ui->spnWidth->setValue(img.width());
    ui->spnHeight->setValue(img.height());

    // Check format compatibility
    QString suffix = QFileInfo(path).suffix().toLower();
    m_mode = static_cast<Mode>(ui->cmbMode->currentIndex());

    if((suffix == "jpg" || suffix == "jpeg") &&
        (m_mode == ByTransparency || m_mode == ByTransparency50p))
    {
        showFormatWarning(suffix);
        return;
    }

    m_sourceImage = img;
    m_frame = convertImageToFrame(img); // 立即转换并存储到m_frame
    generatePreview();
}

void ImportDialog::onImportClicked()
{
    // 确保尺寸有效
    if(ui->spnWidth->value() <= 0 || ui->spnHeight->value() <= 0) {
        QMessageBox::warning(this, "Error", "Invalid image dimensions");
        return;
    }

    // 重新转换当前预览尺寸的图像
    m_frame = convertImageToFrame(m_sourceImage);

    if(!m_cbitmap->loadFrame(m_frame)) {
        QMessageBox::warning(this, "Error", "Failed to load frame into CBitmap");
        return;
    }

    accept(); // 关闭对话框
}

CBitmap::Frame ImportDialog::convertImageToFrame(const QImage& img) const
{
    QSize targetSize(ui->spnWidth->value(), ui->spnHeight->value());
    QImage scaled = img.scaled(targetSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    CBitmap::Frame frame;
    frame.size = targetSize;
    frame.data.resize(targetSize.width() * targetSize.height());

    for(int y = 0; y < targetSize.height(); ++y){
        for(int x = 0; x < targetSize.width(); ++x){
            QColor color = scaled.pixelColor(x, y);
            bool value = false;

            switch(m_mode){
            case ByTransparency:
                value = (color.alpha() == 255);
                break;
            case ByTransparency50p:
                value = (color.alpha() > 127);
                break;
            case ByColor:
                value = (color.lightness() < 127);
                break;
            case ByColorReverse:
                value = (color.lightness() >= 127);
                break;
            }
            frame.data[y * targetSize.width() + x] = value;
        }
    }
    return frame;
}

void ImportDialog::updateScene()
{
    QSize targetSize(ui->spnWidth->value(), ui->spnHeight->value());
    QRect sceneRect = QRect(0, 0, qMax(targetSize.width()*4, view->width()*4), qMax(targetSize.height()*4, view->height()*4));
    QRect WidgetGeometry = QRect(QPoint((sceneRect.width()-targetSize.width())/2, (sceneRect.width()-targetSize.height())/2), targetSize * 2);

    scene->setSceneRect(sceneRect);
    proxy->setGeometry(WidgetGeometry);
    view->resetView();
    view->centerOn(proxy);
}

void ImportDialog::onSizeChanged()
{
    if(!ui->chkAspectRatio->isChecked() || m_sourceImage.isNull()) return;

    QSize origSize = m_sourceImage.size();
    double aspect = origSize.width() / (double)origSize.height();

    if(sender() == ui->spnWidth){
        ui->spnHeight->blockSignals(true);
        ui->spnHeight->setValue(ui->spnWidth->value() / aspect);
        ui->spnHeight->blockSignals(false);
    }else{
        ui->spnWidth->blockSignals(true);
        ui->spnWidth->setValue(ui->spnHeight->value() * aspect);
        ui->spnWidth->blockSignals(false);
    }

    generatePreview();
}

void ImportDialog::showFormatWarning(const QString& format)
{
    QMessageBox::warning(this, "Format Warning",
                         QString("Selected mode doesn't support %1 format").arg(format.toUpper()));
}

void ImportDialog::updatePreview()
{
    if (m_previewImage.isNull()) {
        lbPreview->clear();
        return;
    }

    // 1. 缩放预览图像以适应QLabel（保持比例）
    QPixmap pixmap = QPixmap::fromImage(m_previewImage)
                         .scaled(lbPreview->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // 2. 显示预览（带边框效果）
    lbPreview->setPixmap(pixmap);
    lbPreview->setStyleSheet("border: 1px solid gray; background: white;");
    lbPreview->setAlignment(Qt::AlignCenter);
}

void ImportDialog::generatePreview()
{
    if (m_sourceImage.isNull()) {
        lbPreview->clear();
        return;
    }

    updateScene();

    // 1. 创建高质量预览图像
    QSize targetSize(ui->spnWidth->value(), ui->spnHeight->value());
    QImage preview(targetSize, QImage::Format_ARGB32);

    // 使用纯黑白颜色确保边缘清晰
    QColor activeColor = Qt::white;
    QColor inactiveColor = Qt::black;

    // 2. 高质量缩放+二值化处理
    QImage scaled = m_sourceImage.scaled(
        targetSize,
        Qt::IgnoreAspectRatio, // 精确匹配目标尺寸
        Qt::SmoothTransformation
        );

    for (int y = 0; y < targetSize.height(); ++y) {
        for (int x = 0; x < targetSize.width(); ++x) {
            QColor color = scaled.pixelColor(x, y);
            bool isActive = false;

            switch (m_mode) {
            case ByTransparency:    isActive = (color.alpha() == 255); break;
            case ByTransparency50p: isActive = (color.alpha() > 127); break;
            case ByColor:           isActive = (color.lightness() < 127); break;
            case ByColorReverse:    isActive = (color.lightness() >= 127); break;
            }

            preview.setPixelColor(x, y, isActive ? activeColor : inactiveColor);
        }
    }

    // 3. 显示预览（保持1:1像素映射）
    QPixmap pixmap = QPixmap::fromImage(preview);
    pixmap = pixmap.scaled(
        lbPreview->size(),
        Qt::KeepAspectRatio,
        Qt::FastTransformation // 禁用抗锯齿
        );

    lbPreview->setPixmap(pixmap);
    lbPreview->setStyleSheet("border: 1px solid gray;");
}
