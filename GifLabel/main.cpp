#include "ttkgiflabelwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TTKGifLabelWindow w;
    w.show();

    return a.exec();
}
