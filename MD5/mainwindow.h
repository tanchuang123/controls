#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QByteArray getFileMd5(QString filePath);
    void getMD5();
    QString filePath();
private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString filePath_;
};

#endif // MAINWINDOW_H
