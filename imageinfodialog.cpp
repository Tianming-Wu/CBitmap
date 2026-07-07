#include "imageinfodialog.h"
#include "ui_imageinfodialog.h"

#include "cbitmap.h"

#include <QMessageBox>

#include <functional>

namespace {
CBitmap::Frame::Alignment toFrameAlignment(int alignId)
{
    using A = CBitmap::Frame::Alignment;
    switch (alignId) {
    case 0: return A::Topleft;
    case 1: return A::Top;
    case 2: return A::TopRight;
    case 3: return A::Left;
    case 4: return A::Center;
    case 5: return A::Right;
    case 6: return A::BottomLeft;
    case 7: return A::Bottom;
    case 8: return A::BottomRight;
    default: return A::Center;
    }
}
}

ImageInfoDialog::ImageInfoDialog(CBitmap *cbitmap, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ImageInfoDialog)
    , m_cbitmap(cbitmap), btnAlignGroup(new QButtonGroup(this))
{
    ui->setupUi(this);

    // Calculation
    QSize bitmapSize = m_cbitmap->bitmapSize();
    int width = bitmapSize.width(), height = bitmapSize.height();
    int bytes = ((width + 7) / 8) * height;

    aspect = bitmapSize.width() / (double)bitmapSize.height();

    // Properties
    ui->pr_sizeLabel->setText(QString("Size: %1*%2").arg(width).arg(height));
    ui->pr_bytesLabel->setText(QString("Length: %1B").arg(bytes));

    // Display Settings
    ui->ds_cbxShowGrid->setChecked(m_cbitmap->showGrid());

    // New Image
    ui->ni_spnWidth->setValue(width);
    ui->ni_spnHeight->setValue(height);

    // Adjust Image
    ui->ad_spnWidth->setValue(width);
    ui->ad_spnHeight->setValue(height);

    pbAlign[bTL] = ui->ad_pbAlignTL; pbAlign[bT] = ui->ad_pbAlignT ; pbAlign[bTR] = ui->ad_pbAlignTR;
    pbAlign[bL]  = ui->ad_pbAlignL ; pbAlign[bC] = ui->ad_pbAlignC ; pbAlign[bR]  = ui->ad_pbAlignR ;
    pbAlign[bBL] = ui->ad_pbAlignBL; pbAlign[bB] = ui->ad_pbAlignB ; pbAlign[bBR] = ui->ad_pbAlignBR;

    for(int i=0;i<9;i++)
        btnAlignGroup->addButton(pbAlign[i], i);

    connect(btnAlignGroup, &QButtonGroup::idClicked, this, &ImageInfoDialog::onAdjustAlignmentChanged);

    // General
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &ImageInfoDialog::updateUIElements);

    connect(ui->pbApply, &QPushButton::clicked, this, &ImageInfoDialog::onApply);
    connect(ui->pbExit, &QPushButton::clicked, this, &ImageInfoDialog::onExit);

    // Spin box
    connect(ui->ni_spnWidth, &QSpinBox::valueChanged, this, &ImageInfoDialog::onSizeSpinChange_ni);
    connect(ui->ni_spnHeight, &QSpinBox::valueChanged, this, &ImageInfoDialog::onSizeSpinChange_ni);

    connect(ui->ad_spnWidth, &QSpinBox::valueChanged, this, &ImageInfoDialog::onSizeSpinChange_ad);
    connect(ui->ad_spnHeight, &QSpinBox::valueChanged, this, &ImageInfoDialog::onSizeSpinChange_ad);
}

ImageInfoDialog::~ImageInfoDialog()
{
    delete ui;
}

void ImageInfoDialog::updateUIElements()
{
    ui->pbApply->setText(getUIElementName(BtnApply));
    ui->pbApply->setVisible((getPageIndex() != PageProperty));

    ui->pbExit->setText(getUIElementName(BtnExit));
}

void ImageInfoDialog::onApply()
{
    switch(getPageIndex()) {
    case PageDisplaySettings: {
        m_cbitmap->setShowGrid(ui->ds_cbxShowGrid->isChecked());
        break;
    }
    case PageNewImage: {
        QSize newSize = QSize(ui->ni_spnWidth->value(), ui->ni_spnHeight->value());
        if(newSize.width() > 0 && newSize.height() > 0) {
            m_cbitmap->newFrame(newSize);
            accept();
        } else QMessageBox::warning(this, "new Image", QString("Invalid Size: %1*%2").arg(newSize.width()).arg(newSize.height()));
        return;
    }
    case PageAdjust: {
        QSize newSize = QSize(ui->ad_spnWidth->value(), ui->ad_spnHeight->value());
        if(newSize.width() > 0 && newSize.height() > 0) {
            m_cbitmap->resizeFrame(newSize, toFrameAlignment(static_cast<int>(align)));
            accept();
        } else QMessageBox::warning(this, "Adjust Image", QString("Invalid Size: %1*%2").arg(newSize.width()).arg(newSize.height()));
        break;
    }
    default:
        return;
    }
}

void ImageInfoDialog::onExit()
{
    accept();
}

void ImageInfoDialog::onSizeSpinChange_ni()
{
    if(!ui->ni_chkAspectRatio->isChecked()) return;

    if(sender() == ui->ni_spnWidth){
        ui->ni_spnHeight->blockSignals(true);
        ui->ni_spnHeight->setValue(ui->ni_spnWidth->value() / aspect);
        ui->ni_spnHeight->blockSignals(false);
    } else {
        ui->ni_spnWidth->blockSignals(true);
        ui->ni_spnWidth->setValue(ui->ni_spnHeight->value() * aspect);
        ui->ni_spnWidth->blockSignals(false);
    }
}

void ImageInfoDialog::onSizeSpinChange_ad()
{
    if(!ui->ad_chkAspectRatio->isChecked()) return;

    if(sender() == ui->ad_spnWidth){
        ui->ad_spnHeight->blockSignals(true);
        ui->ad_spnHeight->setValue(ui->ad_spnWidth->value() / aspect);
        ui->ad_spnHeight->blockSignals(false);
    }else{
        ui->ad_spnWidth->blockSignals(true);
        ui->ad_spnWidth->setValue(ui->ad_spnHeight->value() * aspect);
        ui->ad_spnWidth->blockSignals(false);
    }
}

void ImageInfoDialog::onAdjustAlignmentChanged(int id)
{
    int i = id/3, j = id%3;

    // Set the icon
    static std::function<void(int,int,int,int)> seticon = [this](int i, int j, int dx, int dy) {

        static QIcon iconmap[9] = {QIcon("://arrow-tl"), QIcon("://arrow-up"), QIcon("://arrow-tr"),
                                  QIcon("://arrow-left"), QIcon("://position"), QIcon("://arrow-right"),
                                  QIcon("://arrow-bl"), QIcon("://arrow-down"), QIcon("://arrow-br")
        };
        int x = i+dx, y=j+dy;

        if( x<0 || x>=3 || y<0 || y>=3 ) return;
        pbAlign[x*3+y]->setIcon(iconmap[dx*3+dy+4]);
    };

    for(int d=0; d<9; d++) pbAlign[d]->setIcon(QIcon());

    for(int x = -1; x <= 1; x++)
        for(int y = -1; y <= 1; y++) {
            seticon(i, j, x, y);
        }

    align = static_cast<ad_Align>(id);
}

ImageInfoDialog::Pages ImageInfoDialog::getPageIndex()
{
    return static_cast<Pages>(ui->tabWidget->currentIndex());
}

QString ImageInfoDialog::getUIElementName(UIElementName name)
{
    Pages pageid = static_cast<Pages>(ui->tabWidget->currentIndex());
    switch (pageid) {
    case PageProperty:
        switch (name) {
        case BtnApply: return "";
        case BtnExit: return "&Exit";
        }
        break;
    case PageDisplaySettings:
        switch (name) {
        case BtnApply: return "&Apply";
        case BtnExit: return "&Cancel";
        }
        break;
    case PageNewImage:
        switch (name) {
        case BtnApply: return "&Create";
        case BtnExit: return "&Cancel";
        }
        break;
    case PageAdjust:
        switch (name) {
        case BtnApply: return "&Apply";
        case BtnExit: return "&Cancel";
        }
        break;
    default:
        return "[ERROR]";
    }
    return "[ERROR]";
}
