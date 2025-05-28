/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "indicatorbutton.h"
#include "mygrar.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    MyGraphicsArea *graphicsView;
    IndicatorButton *pbPen;
    IndicatorButton *pbEraser;
    IndicatorButton *pbImageInfo;
    IndicatorButton *pbExport;
    QPushButton *pb_5;
    IndicatorButton *pbResetView;
    IndicatorButton *pbRedo;
    IndicatorButton *pbUndo;
    QComboBox *cbxPenMode;
    QLabel *lbResolution;
    QLabel *lbZoom;
    QComboBox *cbxFillMode;
    QLabel *lbCBitmapStatus;
    IndicatorButton *pbImport;
    IndicatorButton *pbImportImage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(788, 585);
        MainWindow->setStyleSheet(QString::fromUtf8("#graphicsView {\n"
"	border: 1px solid grey;\n"
"}\n"
"\n"
"QComboBox {\n"
"	padding-right: 0px; margin-right: 0px;\n"
"	padding-left: 2.5px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: none; width: 0; height: 0;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    width: 0; border: none; background: transparent;\n"
"	subcontrol-origin: padding;\n"
"    subcontrol-position: center right;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    min-width: 120px;\n"
"    padding: 4px;\n"
"	text-align: left;\n"
"}\n"
"\n"
".QPushButton {\n"
"	padding: 2px;	\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new MyGraphicsArea(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(50, 20, 721, 531));
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::SmoothPixmapTransform);
        graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        pbPen = new IndicatorButton(centralwidget);
        pbPen->setObjectName("pbPen");
        pbPen->setGeometry(QRect(10, 20, 31, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/pen"), QSize(), QIcon::Normal, QIcon::Off);
        pbPen->setIcon(icon);
        pbPen->setIconSize(QSize(25, 25));
        pbPen->setCheckable(true);
        pbPen->setChecked(true);
        pbEraser = new IndicatorButton(centralwidget);
        pbEraser->setObjectName("pbEraser");
        pbEraser->setGeometry(QRect(10, 60, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/eraser"), QSize(), QIcon::Normal, QIcon::Off);
        pbEraser->setIcon(icon1);
        pbEraser->setIconSize(QSize(25, 25));
        pbEraser->setCheckable(true);
        pbImageInfo = new IndicatorButton(centralwidget);
        pbImageInfo->setObjectName("pbImageInfo");
        pbImageInfo->setGeometry(QRect(10, 280, 31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/info"), QSize(), QIcon::Normal, QIcon::Off);
        pbImageInfo->setIcon(icon2);
        pbImageInfo->setIconSize(QSize(25, 25));
        pbExport = new IndicatorButton(centralwidget);
        pbExport->setObjectName("pbExport");
        pbExport->setGeometry(QRect(10, 400, 31, 31));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/export"), QSize(), QIcon::Normal, QIcon::Off);
        pbExport->setIcon(icon3);
        pbExport->setIconSize(QSize(25, 25));
        pb_5 = new QPushButton(centralwidget);
        pb_5->setObjectName("pb_5");
        pb_5->setEnabled(false);
        pb_5->setGeometry(QRect(10, 180, 31, 31));
        pbResetView = new IndicatorButton(centralwidget);
        pbResetView->setObjectName("pbResetView");
        pbResetView->setGeometry(QRect(10, 520, 31, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/home"), QSize(), QIcon::Normal, QIcon::Off);
        pbResetView->setIcon(icon4);
        pbResetView->setIconSize(QSize(25, 25));
        pbRedo = new IndicatorButton(centralwidget);
        pbRedo->setObjectName("pbRedo");
        pbRedo->setGeometry(QRect(10, 480, 31, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/redo"), QSize(), QIcon::Normal, QIcon::Off);
        pbRedo->setIcon(icon5);
        pbRedo->setIconSize(QSize(25, 25));
        pbUndo = new IndicatorButton(centralwidget);
        pbUndo->setObjectName("pbUndo");
        pbUndo->setGeometry(QRect(10, 440, 31, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/undo"), QSize(), QIcon::Normal, QIcon::Off);
        pbUndo->setIcon(icon6);
        pbUndo->setIconSize(QSize(25, 25));
        cbxPenMode = new QComboBox(centralwidget);
        cbxPenMode->setObjectName("cbxPenMode");
        cbxPenMode->setGeometry(QRect(10, 100, 31, 31));
        cbxPenMode->setIconSize(QSize(25, 25));
        cbxPenMode->setFrame(false);
        lbResolution = new QLabel(centralwidget);
        lbResolution->setObjectName("lbResolution");
        lbResolution->setGeometry(QRect(10, 560, 61, 17));
        lbZoom = new QLabel(centralwidget);
        lbZoom->setObjectName("lbZoom");
        lbZoom->setGeometry(QRect(80, 560, 51, 17));
        cbxFillMode = new QComboBox(centralwidget);
        cbxFillMode->setObjectName("cbxFillMode");
        cbxFillMode->setGeometry(QRect(10, 140, 31, 31));
        cbxFillMode->setIconSize(QSize(25, 25));
        cbxFillMode->setFrame(false);
        lbCBitmapStatus = new QLabel(centralwidget);
        lbCBitmapStatus->setObjectName("lbCBitmapStatus");
        lbCBitmapStatus->setGeometry(QRect(140, 560, 181, 17));
        pbImport = new IndicatorButton(centralwidget);
        pbImport->setObjectName("pbImport");
        pbImport->setGeometry(QRect(10, 360, 31, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/import"), QSize(), QIcon::Normal, QIcon::Off);
        pbImport->setIcon(icon7);
        pbImport->setIconSize(QSize(25, 25));
        pbImportImage = new IndicatorButton(centralwidget);
        pbImportImage->setObjectName("pbImportImage");
        pbImportImage->setGeometry(QRect(10, 320, 31, 31));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/addimage"), QSize(), QIcon::Normal, QIcon::Off);
        pbImportImage->setIcon(icon8);
        pbImportImage->setIconSize(QSize(25, 25));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CBitmap Editor", nullptr));
#if QT_CONFIG(tooltip)
        pbPen->setToolTip(QCoreApplication::translate("MainWindow", "Pen", nullptr));
#endif // QT_CONFIG(tooltip)
        pbPen->setText(QString());
#if QT_CONFIG(tooltip)
        pbEraser->setToolTip(QCoreApplication::translate("MainWindow", "Eraser", nullptr));
#endif // QT_CONFIG(tooltip)
        pbEraser->setText(QString());
#if QT_CONFIG(tooltip)
        pbImageInfo->setToolTip(QCoreApplication::translate("MainWindow", "Image Info & Operations", nullptr));
#endif // QT_CONFIG(tooltip)
        pbImageInfo->setText(QString());
#if QT_CONFIG(tooltip)
        pbExport->setToolTip(QCoreApplication::translate("MainWindow", "Export to code", nullptr));
#endif // QT_CONFIG(tooltip)
        pbExport->setText(QString());
        pb_5->setText(QString());
#if QT_CONFIG(tooltip)
        pbResetView->setToolTip(QCoreApplication::translate("MainWindow", "Reset View", nullptr));
#endif // QT_CONFIG(tooltip)
        pbResetView->setText(QString());
#if QT_CONFIG(tooltip)
        pbRedo->setToolTip(QCoreApplication::translate("MainWindow", "Redo", nullptr));
#endif // QT_CONFIG(tooltip)
        pbRedo->setText(QString());
#if QT_CONFIG(tooltip)
        pbUndo->setToolTip(QCoreApplication::translate("MainWindow", "Undo", nullptr));
#endif // QT_CONFIG(tooltip)
        pbUndo->setText(QString());
#if QT_CONFIG(tooltip)
        cbxPenMode->setToolTip(QCoreApplication::translate("MainWindow", "Shape", nullptr));
#endif // QT_CONFIG(tooltip)
        lbResolution->setText(QCoreApplication::translate("MainWindow", "128*64", nullptr));
        lbZoom->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
#if QT_CONFIG(tooltip)
        cbxFillMode->setToolTip(QCoreApplication::translate("MainWindow", "Fill Mode", nullptr));
#endif // QT_CONFIG(tooltip)
        lbCBitmapStatus->setText(QString());
#if QT_CONFIG(tooltip)
        pbImport->setToolTip(QCoreApplication::translate("MainWindow", "Import from code", nullptr));
#endif // QT_CONFIG(tooltip)
        pbImport->setText(QString());
#if QT_CONFIG(tooltip)
        pbImportImage->setToolTip(QCoreApplication::translate("MainWindow", "Import from Image", nullptr));
#endif // QT_CONFIG(tooltip)
        pbImportImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
