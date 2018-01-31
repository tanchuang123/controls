#ifndef TTKSPLITITEMWINDOW_H
#define TTKSPLITITEMWINDOW_H

#include <QMainWindow>

namespace Ui {
class TTKSplitItemWindow;
}

class TTKSplitItemWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TTKSplitItemWindow(QWidget *parent = 0);
    ~TTKSplitItemWindow();

private Q_SLOTS:
    void changed(const QString &value);

private:
    Ui::TTKSplitItemWindow *ui;

};

#endif // TTKSPLITITEMWINDOW_H
