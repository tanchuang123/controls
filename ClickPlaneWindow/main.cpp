#include "ttkcircleclickplanewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TTKCircleClickPlaneWindow w;
    w.show();

    return a.exec();
}
