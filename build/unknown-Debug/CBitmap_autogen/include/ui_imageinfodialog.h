/********************************************************************************
** Form generated from reading UI file 'imageinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEINFODIALOG_H
#define UI_IMAGEINFODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "indicatorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_ImageInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabProperty;
    QLabel *pr_sizeLabel;
    QLabel *pr_bytesLabel;
    QWidget *tabDisplaySettings;
    QLabel *ds_lb_0;
    QLabel *ds_lb_1;
    QCheckBox *ds_cbxShowGrid;
    QWidget *tabNewImage;
    QSpinBox *ni_spnWidth;
    QSpinBox *ni_spnHeight;
    IndicatorButton *ni_chkAspectRatio;
    QWidget *tabAdjust;
    QSpinBox *ad_spnWidth;
    QSpinBox *ad_spnHeight;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    IndicatorButton *ad_pbAlignTR;
    IndicatorButton *ad_pbAlignL;
    IndicatorButton *ad_pbAlignTL;
    IndicatorButton *ad_pbAlignT;
    IndicatorButton *ad_pbAlignC;
    IndicatorButton *ad_pbAlignBL;
    IndicatorButton *ad_pbAlignR;
    IndicatorButton *ad_pbAlignB;
    IndicatorButton *ad_pbAlignBR;
    IndicatorButton *ad_chkAspectRatio;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbApply;
    QPushButton *pbExit;

    void setupUi(QDialog *ImageInfoDialog)
    {
        if (ImageInfoDialog->objectName().isEmpty())
            ImageInfoDialog->setObjectName("ImageInfoDialog");
        ImageInfoDialog->resize(603, 436);
        verticalLayout = new QVBoxLayout(ImageInfoDialog);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(ImageInfoDialog);
        tabWidget->setObjectName("tabWidget");
        tabProperty = new QWidget();
        tabProperty->setObjectName("tabProperty");
        pr_sizeLabel = new QLabel(tabProperty);
        pr_sizeLabel->setObjectName("pr_sizeLabel");
        pr_sizeLabel->setGeometry(QRect(20, 10, 131, 21));
        pr_bytesLabel = new QLabel(tabProperty);
        pr_bytesLabel->setObjectName("pr_bytesLabel");
        pr_bytesLabel->setGeometry(QRect(20, 40, 131, 21));
        tabWidget->addTab(tabProperty, QString());
        tabDisplaySettings = new QWidget();
        tabDisplaySettings->setObjectName("tabDisplaySettings");
        ds_lb_0 = new QLabel(tabDisplaySettings);
        ds_lb_0->setObjectName("ds_lb_0");
        ds_lb_0->setGeometry(QRect(20, 10, 66, 21));
        ds_lb_1 = new QLabel(tabDisplaySettings);
        ds_lb_1->setObjectName("ds_lb_1");
        ds_lb_1->setGeometry(QRect(20, 40, 66, 21));
        ds_cbxShowGrid = new QCheckBox(tabDisplaySettings);
        ds_cbxShowGrid->setObjectName("ds_cbxShowGrid");
        ds_cbxShowGrid->setGeometry(QRect(20, 70, 111, 23));
        tabWidget->addTab(tabDisplaySettings, QString());
        tabNewImage = new QWidget();
        tabNewImage->setObjectName("tabNewImage");
        ni_spnWidth = new QSpinBox(tabNewImage);
        ni_spnWidth->setObjectName("ni_spnWidth");
        ni_spnWidth->setGeometry(QRect(20, 11, 71, 26));
        ni_spnWidth->setMinimum(1);
        ni_spnWidth->setMaximum(1024);
        ni_spnHeight = new QSpinBox(tabNewImage);
        ni_spnHeight->setObjectName("ni_spnHeight");
        ni_spnHeight->setGeometry(QRect(20, 41, 71, 26));
        ni_spnHeight->setMinimum(1);
        ni_spnHeight->setMaximum(1024);
        ni_chkAspectRatio = new IndicatorButton(tabNewImage);
        ni_chkAspectRatio->setObjectName("ni_chkAspectRatio");
        ni_chkAspectRatio->setGeometry(QRect(97, 24, 31, 31));
        ni_chkAspectRatio->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/link"), QSize(), QIcon::Normal, QIcon::Off);
        ni_chkAspectRatio->setIcon(icon);
        ni_chkAspectRatio->setIconSize(QSize(25, 25));
        ni_chkAspectRatio->setCheckable(true);
        ni_chkAspectRatio->setChecked(true);
        tabWidget->addTab(tabNewImage, QString());
        tabAdjust = new QWidget();
        tabAdjust->setObjectName("tabAdjust");
        ad_spnWidth = new QSpinBox(tabAdjust);
        ad_spnWidth->setObjectName("ad_spnWidth");
        ad_spnWidth->setGeometry(QRect(20, 11, 71, 26));
        ad_spnWidth->setMinimum(1);
        ad_spnWidth->setMaximum(1024);
        ad_spnHeight = new QSpinBox(tabAdjust);
        ad_spnHeight->setObjectName("ad_spnHeight");
        ad_spnHeight->setGeometry(QRect(20, 41, 71, 26));
        ad_spnHeight->setMinimum(1);
        ad_spnHeight->setMaximum(1024);
        groupBox = new QGroupBox(tabAdjust);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 70, 99, 115));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	border: 1px solid gray;\n"
"	margin-top: 2ex;\n"
"}\n"
"QGroupBox::title {\n"
"	subcontrol-origin: margin;\n"
"	margin-left: 2px;\n"
"}"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        ad_pbAlignTR = new IndicatorButton(groupBox);
        ad_pbAlignTR->setObjectName("ad_pbAlignTR");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ad_pbAlignTR->sizePolicy().hasHeightForWidth());
        ad_pbAlignTR->setSizePolicy(sizePolicy);
        ad_pbAlignTR->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/arrow-tr"), QSize(), QIcon::Normal, QIcon::Off);
        ad_pbAlignTR->setIcon(icon1);
        ad_pbAlignTR->setIconSize(QSize(25, 25));
        ad_pbAlignTR->setCheckable(true);

        gridLayout_2->addWidget(ad_pbAlignTR, 0, 2, 1, 1);

        ad_pbAlignL = new IndicatorButton(groupBox);
        ad_pbAlignL->setObjectName("ad_pbAlignL");
        sizePolicy.setHeightForWidth(ad_pbAlignL->sizePolicy().hasHeightForWidth());
        ad_pbAlignL->setSizePolicy(sizePolicy);
        ad_pbAlignL->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/arrow-left"), QSize(), QIcon::Normal, QIcon::Off);
        ad_pbAlignL->setIcon(icon2);
        ad_pbAlignL->setIconSize(QSize(25, 25));
        ad_pbAlignL->setCheckable(true);

        gridLayout_2->addWidget(ad_pbAlignL, 1, 0, 1, 1);

        ad_pbAlignTL = new IndicatorButton(groupBox);
        ad_pbAlignTL->setObjectName("ad_pbAlignTL");
        sizePolicy.setHeightForWidth(ad_pbAlignTL->sizePolicy().hasHeightForWidth());
        ad_pbAlignTL->setSizePolicy(sizePolicy);
        ad_pbAlignTL->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/arrow-tl"), QSize(), QIcon::Normal, QIcon::Off);
        ad_pbAlignTL->setIcon(icon3);
        ad_pbAlignTL->setIconSize(QSize(25, 25));
        ad_pbAlignTL->setCheckable(true);

        gridLayout_2->addWidget(ad_pbAlignTL, 0, 0, 1, 1);

        ad_pbAlignT = new IndicatorButton(groupBox);
        ad_pbAlignT->setObjectName("ad_pbAlignT");
        sizePolicy.setHeightForWidth(ad_pbAlignT->sizePolicy().hasHeightForWidth());
        ad_pbAlignT->setSizePolicy(sizePolicy);
        ad_pbAlignT->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/arrow-up"), QSize(), QIcon::Normal, QIcon::Off);
        ad_pbAlignT->setIcon(icon4);
        ad_pbAlignT->setIconSize(QSize(25, 25));
        ad_pbAlignT->setCheckable(true);

        gridLayout_2->addWidget(ad_pbAlignT, 0, 1, 1, 1);

        ad_pbAlignC = new IndicatorButton(groupBox);
        ad_pbAlignC->setObjectName("ad_pbAlignC");
        sizePolicy.setHeightForWidth(ad_pbAlignC->sizePolicy().hasHeightForWidth());
        ad_pbAlignC->setSizePolicy(sizePolicy);
        ad_pbAlignC->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/position"), QSize(), QIcon::Normal, QIcon::Off);
        ad_pbAlignC->setIcon(icon5);
        ad_pbAlignC->setIconSize(QSize(25, 25));
        ad_pbAlignC->setCheckable(true);
        ad_pbAlignC->setChecked(true);

        gridLayout_2->addWidget(ad_pbAlignC, 1, 1, 1, 1);

        ad_pbAlignBL = new IndicatorButton(groupBox);
        ad_pbAlignBL->setObjectName("ad_pbAlignBL");
        sizePolicy.setHeightForWidth(ad_pbAlignBL->sizePolicy().hasHeightForWidth());
        ad_pbAlignBL->setSizePolicy(sizePolicy);
        ad_pbAlignBL->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/arrow-bl"), QSize(), QIcon::Normal, QIcon::Off);
        ad_pbAlignBL->setIcon(icon6);
        ad_pbAlignBL->setIconSize(QSize(25, 25));
        ad_pbAlignBL->setCheckable(true);

        gridLayout_2->addWidget(ad_pbAlignBL, 2, 0, 1, 1);

        ad_pbAlignR = new IndicatorButton(groupBox);
        ad_pbAlignR->setObjectName("ad_pbAlignR");
        sizePolicy.setHeightForWidth(ad_pbAlignR->sizePolicy().hasHeightForWidth());
        ad_pbAlignR->setSizePolicy(sizePolicy);
        ad_pbAlignR->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/arrow-right"), QSize(), QIcon::Normal, QIcon::Off);
        ad_pbAlignR->setIcon(icon7);
        ad_pbAlignR->setIconSize(QSize(25, 25));
        ad_pbAlignR->setCheckable(true);

        gridLayout_2->addWidget(ad_pbAlignR, 1, 2, 1, 1);

        ad_pbAlignB = new IndicatorButton(groupBox);
        ad_pbAlignB->setObjectName("ad_pbAlignB");
        sizePolicy.setHeightForWidth(ad_pbAlignB->sizePolicy().hasHeightForWidth());
        ad_pbAlignB->setSizePolicy(sizePolicy);
        ad_pbAlignB->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/arrow-down"), QSize(), QIcon::Normal, QIcon::Off);
        ad_pbAlignB->setIcon(icon8);
        ad_pbAlignB->setIconSize(QSize(25, 25));
        ad_pbAlignB->setCheckable(true);

        gridLayout_2->addWidget(ad_pbAlignB, 2, 1, 1, 1);

        ad_pbAlignBR = new IndicatorButton(groupBox);
        ad_pbAlignBR->setObjectName("ad_pbAlignBR");
        sizePolicy.setHeightForWidth(ad_pbAlignBR->sizePolicy().hasHeightForWidth());
        ad_pbAlignBR->setSizePolicy(sizePolicy);
        ad_pbAlignBR->setFocusPolicy(Qt::NoFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/arrow-br"), QSize(), QIcon::Normal, QIcon::Off);
        ad_pbAlignBR->setIcon(icon9);
        ad_pbAlignBR->setIconSize(QSize(25, 25));
        ad_pbAlignBR->setCheckable(true);

        gridLayout_2->addWidget(ad_pbAlignBR, 2, 2, 1, 1);

        ad_chkAspectRatio = new IndicatorButton(tabAdjust);
        ad_chkAspectRatio->setObjectName("ad_chkAspectRatio");
        ad_chkAspectRatio->setGeometry(QRect(96, 24, 31, 31));
        ad_chkAspectRatio->setFocusPolicy(Qt::NoFocus);
        ad_chkAspectRatio->setIcon(icon);
        ad_chkAspectRatio->setIconSize(QSize(25, 25));
        ad_chkAspectRatio->setCheckable(true);
        ad_chkAspectRatio->setChecked(true);
        tabWidget->addTab(tabAdjust, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbApply = new QPushButton(ImageInfoDialog);
        pbApply->setObjectName("pbApply");
        pbApply->setMinimumSize(QSize(91, 25));

        horizontalLayout->addWidget(pbApply);

        pbExit = new QPushButton(ImageInfoDialog);
        pbExit->setObjectName("pbExit");
        pbExit->setMinimumSize(QSize(91, 25));

        horizontalLayout->addWidget(pbExit);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ImageInfoDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ImageInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *ImageInfoDialog)
    {
        ImageInfoDialog->setWindowTitle(QCoreApplication::translate("ImageInfoDialog", "Dialog", nullptr));
        pr_sizeLabel->setText(QCoreApplication::translate("ImageInfoDialog", "Size: ", nullptr));
        pr_bytesLabel->setText(QCoreApplication::translate("ImageInfoDialog", "Length: ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProperty), QCoreApplication::translate("ImageInfoDialog", "Properties", nullptr));
        ds_lb_0->setText(QCoreApplication::translate("ImageInfoDialog", "onColor", nullptr));
        ds_lb_1->setText(QCoreApplication::translate("ImageInfoDialog", "offColor", nullptr));
        ds_cbxShowGrid->setText(QCoreApplication::translate("ImageInfoDialog", "Show Grid", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDisplaySettings), QCoreApplication::translate("ImageInfoDialog", "Display Settings", nullptr));
        ni_chkAspectRatio->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabNewImage), QCoreApplication::translate("ImageInfoDialog", "New Image", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ImageInfoDialog", "Alignment", nullptr));
        ad_pbAlignTR->setText(QString());
        ad_pbAlignL->setText(QString());
        ad_pbAlignTL->setText(QString());
        ad_pbAlignT->setText(QString());
        ad_pbAlignC->setText(QString());
        ad_pbAlignBL->setText(QString());
        ad_pbAlignR->setText(QString());
        ad_pbAlignB->setText(QString());
        ad_pbAlignBR->setText(QString());
        ad_chkAspectRatio->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabAdjust), QCoreApplication::translate("ImageInfoDialog", "Adjust", nullptr));
        pbApply->setText(QCoreApplication::translate("ImageInfoDialog", "&Apply", nullptr));
        pbExit->setText(QCoreApplication::translate("ImageInfoDialog", "&Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageInfoDialog: public Ui_ImageInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEINFODIALOG_H
