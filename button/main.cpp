#include "SCChildDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SCChildDialog w;
    //SCBaseDialog w;
    w.show();

    return a.exec();
}
