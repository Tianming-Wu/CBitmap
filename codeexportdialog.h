#pragma once

#include <QDialog>
#include <QVector>
#include <QSyntaxHighlighter>
#include <QRegularExpression>

class Interpreter;

namespace Ui {
class CodeExportDialog;
}

class CodeHighlighter : public QSyntaxHighlighter {
    Q_OBJECT
public:
    CodeHighlighter(QTextDocument *parent = nullptr);
protected:
    void highlightBlock(const QString &text) override;
private:
    struct HighlightingRule {
        QRegularExpression pattern;
        QTextCharFormat format;
    };

    enum BlockState {
        NormalState = -1,
        InComment = 1,
        InRawString = 2
    };

    void applyBasicHighlightingRules(const QString &text);
    void handleRawStrings(const QString &text, int previousState);
    void handleMultiLineComments(const QString &text, int previousState);

    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat multiLineCommentFormat;
    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat multiLineRawFormat;
    QTextCharFormat rawContentFormat;
    QRegularExpression rawStartExpression;

    class RawStringUserData : public QTextBlockUserData {
    public:
        RawStringUserData(const QString& delim) : delimiter(delim) {}
        QString delimiter;
    };
};

class CodeExportDialog : public QDialog
{
    Q_OBJECT
    Q_DISABLE_COPY(CodeExportDialog)

public:
    enum Mode { ExportMode, ImportMode };
    Q_ENUM(Mode)
    enum CodeMode { ContinuousCodeMode, PaddedCodeMode, PaddedVerticalCodeMode };
    Q_ENUM(CodeMode)
    enum ButtonName { BtnCopyPaste, BtnSaveLoad, BtnExitImport, BtnCopyPasteNotify, BtnImportNotify, WindowTitle };

    explicit CodeExportDialog(Interpreter& interpreter, QWidget *parent = nullptr, Mode mode = ExportMode, CodeMode codemode = PaddedCodeMode);
    ~CodeExportDialog();

    Mode mode() const { return m_mode; }

public:
    void setMode(Mode mode);
    void setCodeMode(CodeMode codemode);

private slots:
    void onCopyPasteClicked();
    void onSaveLoadClicked();
    void onExitImportClicked();

private:
    QString getUIElementName(ButtonName name);

private:
    Ui::CodeExportDialog *ui;
    Interpreter &interpreter;
    Mode m_mode;
    CodeMode m_codeMode;
    CodeHighlighter *highlighter;
};
