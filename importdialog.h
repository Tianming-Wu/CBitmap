#pragma once

#include <QDialog>
#include <QLabel>

#include "cbitmap.h"
#include "mygrar.h"

namespace Ui {
class ImportDialog;
}

class ImportDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        ByTransparency,
        ByTransparency50p,
        ByColor,
        ByColorReverse
    };
    Q_ENUM(Mode)

    explicit ImportDialog(CBitmap* cbitmap, QWidget *parent = nullptr);
    ~ImportDialog();

private slots:
    void onSizeChanged();
    void onOpenClicked();
    void onImportClicked();
    void updatePreview();
    void generatePreview();

private:
    void showFormatWarning(const QString& format);
    CBitmap::Frame convertImageToFrame(const QImage& img) const;
    void updateScene();

private:
    Ui::ImportDialog *ui;

    CBitmap* m_cbitmap;

    Mode m_mode;

    CBitmap::Frame m_frame;
    QImage m_sourceImage;
    QImage m_previewImage;

    QLabel *lbPreview;
    QGraphicsScene *scene;
    QGraphicsProxyWidget *proxy;
    MyGraphicsArea *view;
};
