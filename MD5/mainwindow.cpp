#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtDebug>
#include <QCryptographicHash>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    getMD5();
}

MainWindow::~MainWindow()
{
    delete ui;
}
QByteArray MainWindow::getFileMd5(QString filePath)
{
    filePath=filePath_;
    qDebug()<<filePath<<"filepath";
    QFile localFile(filePath);

    if (!localFile.open(QFile::ReadOnly))
    {
        qDebug() << "file open error.";
        return 0;
    }

    QCryptographicHash ch(QCryptographicHash::Md5);

    quint64 totalBytes = 0;
    quint64 bytesWritten = 0;
    quint64 bytesToWrite = 0;
    quint64 loadSize = 1024 * 4;
    QByteArray buf;

    totalBytes = localFile.size();
    bytesToWrite = totalBytes;

    while (1)
    {
        if(bytesToWrite > 0)
        {
            buf = localFile.read(qMin(bytesToWrite, loadSize));
            ch.addData(buf);
            bytesWritten += buf.length();
            bytesToWrite -= buf.length();
            buf.resize(0);
        }
        else
        {
            break;
        }

        if(bytesWritten == totalBytes)
        {
            break;
        }
    }

    localFile.close();
    QByteArray md5 = ch.result();
    qDebug()<<md5<<"md5";
    return md5;
}
void MainWindow::getMD5()
{
//    ui->textEdit->append(getFileMd5(filePath_));
    QByteArray baData=getFileMd5(filePath_);
    QString str = QString(baData);
    // 反过来转换
    ui->textEdit->setText(tr("nnnnnn"));
}
QString MainWindow::filePath()
{
    filePath_=QFileDialog::getOpenFileName(this);
    qDebug()<<filePath_<<"xxxxx";
    return filePath_;
}

void MainWindow::on_pushButton_clicked()
{
    filePath();
    getFileMd5(filePath_);
}
