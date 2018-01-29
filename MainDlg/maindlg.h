#ifndef MAINDLG_H
#define MAINDLG_H

#include <QDialog>
#include <QFrame>
#include <QComboBox>


class MainDlg : public QDialog
{
    Q_OBJECT

public:
    MainDlg(QWidget *parent = 0);
    ~MainDlg();

    void createCtrlFrame();
    void createContentFrame();
    void fillColorList(QComboBox *);

public slots:
    void sl_window();
    void sl_windowText();
    void sl_button();
    void sl_buttonText();
    void sl_base();

private:
    QFrame *ctrlFrame;  //颜色选择面板
    QFrame *contentFrame;   //具体显示面板
    QComboBox *cbbWindow;
    QComboBox *cbbWindowText;
    QComboBox *cbbButton;
    QComboBox *cbbButtonText;
    QComboBox * cbbBase;

};

#endif // MAINDLG_H
