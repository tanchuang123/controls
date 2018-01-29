#ifndef SCBaseDialog_H
#define SCBaseDialog_H

#include <QDialog>
#include <QButtonGroup>
//#include "FramelessHelper.h"
#include <QDebug>
#include<QPainter>
namespace Ui {
class SCBaseDialog;
}

class SCBaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SCBaseDialog(QWidget *child,QWidget *parent = Q_NULLPTR);
    ~SCBaseDialog();
    enum ButtonID{
        E_MinButton = 0,
        E_MaxButton,
        E_CloseButton
    };
   QButtonGroup *pButtonGroup = Q_NULLPTR;
    void setTitleText(const QString &title, bool isWindowTitle = true);
    void setHideButton(ButtonID id);
    void changeEvent(QEvent *e);

    void clieckedMinBtn();
    void clieckedMaxBtn();
    void clieckedCloseBtn();

    void paintEvent(QPaintEvent *event);
    void setHiddenTitle(bool hidden);
    void addTitleButton(QWidget *w);
    void justShowCloseButton();
    void setShowButton(ButtonID id);
    void addTitleMenu(QWidget *w);
public slots:
    void slotButtonClicked(int);
protected:
    //    void mouseReleaseEvent(QMouseEvent *event);
    //    void mouseMoveEvent(QMouseEvent *event);
    //    void mousePressEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    //    void keyPressEvent(QKeyEvent *key);
    //    void keyReleaseEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent *key);
protected slots:
private:
    Ui::SCBaseDialog *ui;
   // FramelessHelper *pHelper = Q_NULLPTR;
    bool _isActiveWindow = false;
};

#endif // SCBaseDialog_H
