#include "imagetree.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    //初始化qrc资源
//     Q_INIT_RESOURCE(application);
     QApplication a(argc, argv);
     a.setOrganizationName("Qtporject");
     //给窗口添加app name
     a.setApplicationName("Application  hello Example");
     ImageTree w;
     w.show();
     return a.exec();

}
