#pragma once

#include <QWidget>
#include <QIcon>

class IconHandler : public QWidget
{
    Q_OBJECT
public:
    explicit IconHandler(QWidget *parent = nullptr);

    struct HandlerObject {
        QWidget *ref;
        QIcon baseIcon;
    };

    QIcon generateIcon(const QIcon &base, QSize size);
    QIcon generateIcon(const QString &respath, int width, int height);

public slots:
    void bindItem(const HandlerObject &obj);
    void bindItem(QWidget* ref, QIcon baseIcon);

protected:
    bool event(QEvent *e);

private:
    void updateIcons();

private:
    QVector<HandlerObject> objlist;

};
