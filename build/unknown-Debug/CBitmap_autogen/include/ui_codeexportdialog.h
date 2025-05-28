/********************************************************************************
** Form generated from reading UI file 'codeexportdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEEXPORTDIALOG_H
#define UI_CODEEXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CodeExportDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbCopyPaste;
    QPushButton *pbSaveLoad;
    QPushButton *pbExitImport;

    void setupUi(QDialog *CodeExportDialog)
    {
        if (CodeExportDialog->objectName().isEmpty())
            CodeExportDialog->setObjectName("CodeExportDialog");
        CodeExportDialog->resize(572, 386);
        verticalLayout = new QVBoxLayout(CodeExportDialog);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(CodeExportDialog);
        textEdit->setObjectName("textEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Monospace")});
        textEdit->setFont(font);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        textEdit->setAcceptRichText(false);

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbCopyPaste = new QPushButton(CodeExportDialog);
        pbCopyPaste->setObjectName("pbCopyPaste");
        pbCopyPaste->setMinimumSize(QSize(80, 25));

        horizontalLayout->addWidget(pbCopyPaste);

        pbSaveLoad = new QPushButton(CodeExportDialog);
        pbSaveLoad->setObjectName("pbSaveLoad");
        pbSaveLoad->setMinimumSize(QSize(80, 25));

        horizontalLayout->addWidget(pbSaveLoad);

        pbExitImport = new QPushButton(CodeExportDialog);
        pbExitImport->setObjectName("pbExitImport");
        pbExitImport->setMinimumSize(QSize(80, 25));

        horizontalLayout->addWidget(pbExitImport);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CodeExportDialog);

        QMetaObject::connectSlotsByName(CodeExportDialog);
    } // setupUi

    void retranslateUi(QDialog *CodeExportDialog)
    {
        CodeExportDialog->setWindowTitle(QString());
        pbCopyPaste->setText(QCoreApplication::translate("CodeExportDialog", "&Copy", nullptr));
        pbSaveLoad->setText(QCoreApplication::translate("CodeExportDialog", "&Save", nullptr));
        pbExitImport->setText(QCoreApplication::translate("CodeExportDialog", "&Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CodeExportDialog: public Ui_CodeExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEEXPORTDIALOG_H
