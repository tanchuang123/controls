#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    NBaseSwitchButton *switchBtn = new NBaseSwitchButton;
    switchBtn->setWindowModality(Qt::ApplicationModal);
    switchBtn->show ();

//    QTimer::singleShot (8000,switchBtn,SLOT(deleteLater()));
//    ui->textEdit->append ("switch切换开关已经启动，8秒后即将关闭!");
}

MainWindow::~MainWindow()
{
    delete ui;
}
