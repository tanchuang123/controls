#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Dialog:public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent=0);
    ~Dialog();

protected:
    void paintEvent(QPaintEvent *);

    void timerEvent(QTimerEvent *);

    float usage() const;

private:
    QPixmap pixmap;
    int base;
    int columnInc; // 动态列偏移值

    int *pts; // 随机数据数组
    int mLen; // 记录数组长度
    int ptNum; // 点数目
};

#endif
