#include "codeexportdialog.h"
#include "ui_codeexportdialog.h"

#include "interpreter.h"

#include <QClipboard>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

CodeExportDialog::CodeExportDialog(Interpreter &interpreter, QWidget *parent, Mode mode, CodeMode codemode)
    : QDialog(parent)
    , ui(new Ui::CodeExportDialog)
    , interpreter(interpreter)
{
    ui->setupUi(this);

    highlighter = new CodeHighlighter(ui->textEdit->document());
    setMode(mode);

    connect(ui->pbCopyPaste, &QPushButton::clicked, this, &CodeExportDialog::onCopyPasteClicked);
    connect(ui->pbSaveLoad, &QPushButton::clicked, this, &CodeExportDialog::onSaveLoadClicked);
    connect(ui->pbExitImport, &QPushButton::clicked, this, &CodeExportDialog::onExitImportClicked);

    connect(ui->textEdit, &QTextEdit::copyAvailable, [](bool yes){
        if(yes) {
            QApplication::clipboard()->setText(
                QApplication::clipboard()->text(),
                QClipboard::Clipboard
                );
        }
    });
}

CodeExportDialog::~CodeExportDialog()
{
    delete ui;
}

void CodeExportDialog::setMode(Mode mode)
{
    if(mode == ExportMode) {
        ui->textEdit->setPlainText(interpreter.toString());
    } else {
        ui->textEdit->clear();
    }
    m_mode = mode;

    ui->pbCopyPaste->setText(getUIElementName(BtnCopyPaste));
    ui->pbSaveLoad->setText(getUIElementName(BtnSaveLoad));
    ui->pbExitImport->setText(getUIElementName(BtnExitImport));
    this->setWindowTitle(getUIElementName(WindowTitle));
}

void CodeExportDialog::setCodeMode(CodeMode codemode)
{


    m_codeMode = codemode;
}

void CodeExportDialog::onCopyPasteClicked()
{
    if (m_mode == ExportMode) {
        // 导出模式：复制代码到剪贴板
        QString text = ui->textEdit->toPlainText();
        QApplication::clipboard()->setText(text);
    } else {
        // 导入模式：从剪贴板粘贴代码
        QString text = QApplication::clipboard()->text();
        ui->textEdit->setPlainText(text);
    }

    // 提供视觉反馈
    ui->pbCopyPaste->setText(getUIElementName(BtnCopyPasteNotify));
    QTimer::singleShot(1000, this, [this](){
        ui->pbCopyPaste->setText(getUIElementName(BtnCopyPaste));
    });
}

void CodeExportDialog::onSaveLoadClicked()
{
    if (m_mode == ExportMode) {
        // 导出模式：保存到文件
        QString fileName = QFileDialog::getSaveFileName(
            this,
            "Save Code",
            "",
            "Header Files (*.h)"
            );

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly)) {
                file.write(ui->textEdit->toPlainText().toUtf8());
                QMessageBox::information(this, "Success",
                                         QString("Saved to %1").arg(fileName));
            } else {
                QMessageBox::warning(this, "Error", "Could not save file");
            }
            file.close();
        }
    } else {
        // 导入模式：从文件加载
        QString fileName = QFileDialog::getOpenFileName(
            this,
            "Load Code",
            "",
            "Header Files (*.h)"
            );

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly)) {
                ui->textEdit->setPlainText(file.readAll());
                // QMessageBox::information(this, "Success",
                //                          QString("Loaded from %1").arg(fileName));
            } else {
                QMessageBox::warning(this, "Error", "Could not open file");
            }
            file.close();
        }
    }
}

void CodeExportDialog::onExitImportClicked()
{
    if(m_mode == ExportMode) {
        done(0);
    } else {
        QString err = interpreter.parseString(ui->textEdit->toPlainText());
        if(err.isEmpty()) {
            ui->pbExitImport->setText(getUIElementName(BtnImportNotify));
            QTimer::singleShot(250, this, [this](){
                done(0);
            });
        } else {
            QMessageBox::warning(this, "Failed to import", err);
        }
    }
}

QString CodeExportDialog::getUIElementName(ButtonName name)
{
    if(m_mode == ExportMode) {
        switch(name) {
        case BtnCopyPaste:
            return "&Copy";
        case BtnSaveLoad:
            return "&Save";
        case BtnExitImport:
        case BtnImportNotify:
            return "&Exit";
        case BtnCopyPasteNotify:
            return "Copied!";
        case WindowTitle:
            return "Export to Code / File";
        }
    } else {
        switch(name) {
        case BtnCopyPaste:
            return "&Paste";
        case BtnSaveLoad:
            return "&Load";
        case BtnExitImport:
            return "&Import";
        case BtnCopyPasteNotify:
            return "Pasted!";
        case BtnImportNotify:
            return "Success";
        case WindowTitle:
            return "Import from Code / File";
        }
    }
}

// codeexportdialog.cpp
CodeHighlighter::CodeHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    QTextCharFormat keywordFormat, typeFormat, numberFormat, commentFormat, symbolFormat, arrayNameFormat/*, rawStringFormat*/, stringFormat;

    keywordFormat.setForeground(QColor(61,87,240));
    keywordFormat.setFontWeight(QFont::Bold);

    typeFormat.setForeground(QColor(0, 139, 139));
    typeFormat.setFontWeight(QFont::Bold);

    numberFormat.setForeground(QColor(186,42,185));

    commentFormat.setForeground(Qt::gray);

    symbolFormat.setForeground(QColor(55,140,200));

    arrayNameFormat.setForeground(QColor(110,105,15));

    // rawStringFormat.setForeground(QColor(14,96,110));

    stringFormat.setForeground(QColor(125,95,9));

    QStringList keywordPatterns = {
        R"(\bconst\b)", R"(\bstatic\b)", R"(\bvolatile\b)", R"(\bthread_local\b)", R"(\bconstexpr\b)"
    };

    for (const QString &pattern : keywordPatterns) {
        HighlightingRule rule;
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    QStringList typePatterns = {
        R"(\bunsigned\b)",
        R"(\bint\b)", R"(\bchar\b)", R"(\bvoid\b)",
        R"(\bsize_t\b)",
        R"(\bint32_t\b)", R"(\buint32_t\b)", R"(\bint16_t\b)", R"(\buint16_t\b)", R"(\bint8_t\b)", R"(\buint8_t\b)"
    };

    for (const QString &pattern : typePatterns) {
        HighlightingRule rule;
        rule.pattern = QRegularExpression(pattern);
        rule.format = typeFormat;
        highlightingRules.append(rule);
    }

    // Place before number to prevent overriding "." in float/double value
    HighlightingRule symbolRule;
    symbolRule.pattern = QRegularExpression(R"([{}[\],."'=();<>*]+)");
    symbolRule.format = symbolFormat;
    highlightingRules.append(symbolRule);

    // 数字规则
    HighlightingRule numberRule;
    // \b(?:0x)?\d+(\.\d+[lf])?\b
    numberRule.pattern = QRegularExpression(R"(\b(?:0x[0-9a-fA-F]+|(?:\d+\.\d+f?)|\d+l?)\b)");
    numberRule.format = numberFormat;
    highlightingRules.append(numberRule);

    // 单行注释规则
    HighlightingRule commentRule;
    commentRule.pattern = QRegularExpression(R"(//[^\n]*)");
    commentRule.format = commentFormat;
    highlightingRules.append(commentRule);


    HighlightingRule arrayNameRule;
    arrayNameRule.pattern = QRegularExpression(R"(\b([A-Za-z_]\w*)\s*(?=\[\]))");
    arrayNameRule.format = arrayNameFormat;
    highlightingRules.append(arrayNameRule);

    // HighlightingRule rawStringRule;
    // rawStringRule.pattern = QRegularExpression(
    //     R"a(R(.*?)\(.*\)\1)a",
    //     QRegularExpression::DotMatchesEverythingOption | QRegularExpression::MultilineOption
    //     );
    // rawStringRule.format = rawStringFormat;
    // highlightingRules.append(rawStringRule);

    HighlightingRule stringRule;
    stringRule.pattern = QRegularExpression(R"(".*?")");
    stringRule.format = stringFormat;
    highlightingRules.append(stringRule);

    // 多行注释规则（需要特殊处理）
    multiLineCommentFormat.setForeground(Qt::gray);
    commentStartExpression = QRegularExpression(R"(/\*)");
    commentEndExpression = QRegularExpression(R"(\*/)");

    multiLineRawFormat.setForeground(QColor(14,96,110));
    rawContentFormat = stringFormat;
    rawStartExpression = QRegularExpression(R"(R\"([^ ()\\\r\n]*)\()");
    //R"([^/s("]*?)\(
    // R"(R"(.*)\()"
}

void CodeHighlighter::highlightBlock(const QString &text)
{
    // 保存前一块状态
    int previousState = previousBlockState();

    // 先处理多行注释（如果有）
    if (previousState == InComment || text.contains(commentStartExpression)) {
        handleMultiLineComments(text, previousState);
        return; // 注释优先，不处理其他高亮
    }

    // 然后处理原始字符串
    handleRawStrings(text, previousState);

    // 最后处理其他普通规则
    if(previousState != InRawString && currentBlockState() != InRawString)
        applyBasicHighlightingRules(text);

}

void CodeHighlighter::applyBasicHighlightingRules(const QString &text)
{
    for (const HighlightingRule &rule : highlightingRules) {

        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}

void CodeHighlighter::handleRawStrings(const QString &text, int previousState)
{
    // 如果当前在注释中，跳过原始字符串处理
    if (previousState == InComment) {
        return;
    }

    int startIndex = 0;
    QString delimiter;

    // 如果是继续行
    if (previousState == InRawString) {
        auto userData = static_cast<RawStringUserData*>(currentBlockUserData());
        delimiter = userData ? userData->delimiter : QString();

        if (!delimiter.isEmpty()) {
            QRegularExpression endRegex(QString(R"(\)%1")").arg(QRegularExpression::escape(delimiter)));
            auto endMatch = endRegex.match(text);

            if (endMatch.hasMatch()) {
                // 找到结束标记
                int endPos = endMatch.capturedStart();
                setFormat(0, endPos, rawContentFormat);
                setFormat(endPos, endMatch.capturedLength(), multiLineRawFormat);
                setCurrentBlockState(NormalState);
            } else {
                // 仍未结束
                setFormat(0, text.length(), rawContentFormat);
                setCurrentBlockState(InRawString);
                setCurrentBlockUserData(new RawStringUserData(delimiter));
            }
            return;
        }
    }

    // 查找新的原始字符串开始
    auto startMatch = rawStartExpression.match(text);
    while (startMatch.hasMatch()) {
        startIndex = startMatch.capturedStart();
        delimiter = startMatch.captured(1);

        // 构建结束正则表达式
        QRegularExpression endRegex(QString(R"(\)%1")").arg(QRegularExpression::escape(delimiter)));
        int endPos = -1;

        // 在当前行查找结束标记
        auto endMatch = endRegex.match(text, startIndex + startMatch.capturedLength());
        if (endMatch.hasMatch()) {
            endPos = endMatch.capturedStart();
        }

        // 计算各部分位置
        int prefixLen = delimiter.length() + 3; // R" 或 R"delimiter(
        int contentStart = startIndex + prefixLen;
        int contentEnd = (endPos == -1) ? text.length() : endPos;
        int contentLen = contentEnd - contentStart;

        // 设置格式
        setFormat(startIndex, prefixLen, multiLineRawFormat);
        setFormat(contentStart, contentLen, rawContentFormat);

        if (endPos != -1) {
            // 完整字符串
            int suffixLen = delimiter.length() + 2; // )" 或 )delimiter"
            setFormat(endPos, suffixLen, multiLineRawFormat);
            startIndex = endPos + suffixLen;
            setCurrentBlockState(NormalState);
        } else {
            // 跨行字符串
            setCurrentBlockState(InRawString);
            setCurrentBlockUserData(new RawStringUserData(delimiter));
            break;
        }

        // 查找下一个原始字符串
        startMatch = rawStartExpression.match(text, startIndex);
    }
}

void CodeHighlighter::handleMultiLineComments(const QString &text, int previousState)
{
    int startIndex = 0;

    // 如果不是从注释中间开始，则查找新的注释开始
    if (previousState != InComment) {
        startIndex = text.indexOf(commentStartExpression);
    }

    // 如果不在注释中且没有找到注释开始，则返回
    if (startIndex == -1 && previousState != InComment) {
        setCurrentBlockState(NormalState);
        return;
    }

    // 处理注释
    if (previousState == InComment || startIndex != -1) {
        int commentLength = 0;

        if (previousState == InComment) {
            startIndex = 0;
        }

        QRegularExpressionMatch endMatch = commentEndExpression.match(text, startIndex);
        int endIndex = endMatch.capturedStart();

        if (endIndex == -1) {
            // 注释未结束
            setCurrentBlockState(InComment);
            commentLength = text.length() - startIndex;
        } else {
            // 注释结束
            setCurrentBlockState(NormalState);
            commentLength = endIndex - startIndex + endMatch.capturedLength();
        }

        setFormat(startIndex, commentLength, multiLineCommentFormat);
    }
}
