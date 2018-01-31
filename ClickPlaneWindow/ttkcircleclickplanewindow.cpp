#include "ttkcircleclickplanewindow.h"
#include "ui_ttkcircleclickplanewindow.h"
#include "ttkcircleclickplane.h"
TTKCircleClickPlaneWindow::TTKCircleClickPlaneWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TTKCircleClickPlaneWindow)
{
    ui->setupUi(this);
}

TTKCircleClickPlaneWindow::~TTKCircleClickPlaneWindow()
{
    delete ui;
}

void TTKCircleClickPlaneWindow::on_pushButton_clicked()
{
//    TTKCircleClickPlane *plane=new TTKCircleClickPlane(this);

}
