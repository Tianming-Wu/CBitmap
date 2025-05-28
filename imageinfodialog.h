#pragma once

#include <QDialog>
#include <QButtonGroup>

class CBitmap;
class IndicatorButton;

namespace Ui {
class ImageInfoDialog;
}

class ImageInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageInfoDialog(CBitmap *cbitmap, QWidget *parent = nullptr);
    ~ImageInfoDialog();

    enum UIElementName {
        BtnApply, BtnExit
    };

    enum Pages {
        PageProperty, PageDisplaySettings, PageNewImage, PageAdjust
    };

private slots:
    void updateUIElememts();

    void onApply();
    void onExit();

    void onSizeSpinChange_ni();
    void onSizeSpinChange_ad();

    void onAdjustAlignmentChanged(int id);

private:
    Pages getPageIndex();
    QString getUIElementName(UIElementName name);

private:
    Ui::ImageInfoDialog *ui;

    CBitmap *m_cbitmap;
    QButtonGroup *btnAlignGroup;

    enum ad_Align { bTL, bT, bTR, bL, bC, bR, bBL, bB, bBR };
    IndicatorButton *pbAlign[9];
    ad_Align align = bC;

    double aspect; // For keep aspect ratio
};
