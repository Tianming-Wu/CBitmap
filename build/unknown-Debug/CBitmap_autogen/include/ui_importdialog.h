/********************************************************************************
** Form generated from reading UI file 'importdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTDIALOG_H
#define UI_IMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include "indicatorbutton.h"
#include "mygrar.h"

QT_BEGIN_NAMESPACE

class Ui_ImportDialog
{
public:
    QPushButton *btnImport;
    QComboBox *cmbMode;
    QSpinBox *spnWidth;
    QSpinBox *spnHeight;
    QPushButton *btnOpen;
    MyGraphicsArea *graphicsView;
    IndicatorButton *chkAspectRatio;

    void setupUi(QDialog *ImportDialog)
    {
        if (ImportDialog->objectName().isEmpty())
            ImportDialog->setObjectName("ImportDialog");
        ImportDialog->resize(491, 243);
        btnImport = new QPushButton(ImportDialog);
        btnImport->setObjectName("btnImport");
        btnImport->setGeometry(QRect(380, 210, 91, 25));
        cmbMode = new QComboBox(ImportDialog);
        cmbMode->addItem(QString());
        cmbMode->addItem(QString());
        cmbMode->addItem(QString());
        cmbMode->addItem(QString());
        cmbMode->setObjectName("cmbMode");
        cmbMode->setGeometry(QRect(280, 21, 191, 25));
        spnWidth = new QSpinBox(ImportDialog);
        spnWidth->setObjectName("spnWidth");
        spnWidth->setGeometry(QRect(290, 61, 71, 26));
        spnWidth->setMinimum(1);
        spnWidth->setMaximum(1024);
        spnHeight = new QSpinBox(ImportDialog);
        spnHeight->setObjectName("spnHeight");
        spnHeight->setGeometry(QRect(290, 91, 71, 26));
        spnHeight->setMinimum(1);
        spnHeight->setMaximum(1024);
        btnOpen = new QPushButton(ImportDialog);
        btnOpen->setObjectName("btnOpen");
        btnOpen->setGeometry(QRect(380, 170, 91, 25));
        graphicsView = new MyGraphicsArea(ImportDialog);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 20, 241, 201));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        chkAspectRatio = new IndicatorButton(ImportDialog);
        chkAspectRatio->setObjectName("chkAspectRatio");
        chkAspectRatio->setGeometry(QRect(368, 75, 31, 31));
        chkAspectRatio->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/link"), QSize(), QIcon::Normal, QIcon::Off);
        chkAspectRatio->setIcon(icon);
        chkAspectRatio->setIconSize(QSize(25, 25));
        chkAspectRatio->setCheckable(true);
        chkAspectRatio->setChecked(true);
        graphicsView->raise();
        btnImport->raise();
        cmbMode->raise();
        spnWidth->raise();
        spnHeight->raise();
        btnOpen->raise();
        chkAspectRatio->raise();

        retranslateUi(ImportDialog);

        QMetaObject::connectSlotsByName(ImportDialog);
    } // setupUi

    void retranslateUi(QDialog *ImportDialog)
    {
        ImportDialog->setWindowTitle(QCoreApplication::translate("ImportDialog", "Import from Image", nullptr));
        btnImport->setText(QCoreApplication::translate("ImportDialog", "&Import", nullptr));
        cmbMode->setItemText(0, QCoreApplication::translate("ImportDialog", "ByTransparency", nullptr));
        cmbMode->setItemText(1, QCoreApplication::translate("ImportDialog", "ByTransparency (50%)", nullptr));
        cmbMode->setItemText(2, QCoreApplication::translate("ImportDialog", "ByColor", nullptr));
        cmbMode->setItemText(3, QCoreApplication::translate("ImportDialog", "ByColor (Reverse)", nullptr));

        btnOpen->setText(QCoreApplication::translate("ImportDialog", "&Open", nullptr));
        chkAspectRatio->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImportDialog: public Ui_ImportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTDIALOG_H
