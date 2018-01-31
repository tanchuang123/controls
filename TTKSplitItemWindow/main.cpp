#include "ttksplititemwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TTKSplitItemWindow w;
    w.show();

    return a.exec();
}
