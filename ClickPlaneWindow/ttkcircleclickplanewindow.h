#ifndef TTKCIRCLECLICKPLANEWINDOW_H
#define TTKCIRCLECLICKPLANEWINDOW_H


#include <QMainWindow>

namespace Ui {
class TTKCircleClickPlaneWindow;
}

class  TTKCircleClickPlaneWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TTKCircleClickPlaneWindow(QWidget *parent = 0);
    ~TTKCircleClickPlaneWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TTKCircleClickPlaneWindow *ui;

};

#endif // TTKCIRCLECLICKPLANEWINDOW_H
