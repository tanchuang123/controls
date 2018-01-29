#ifndef IMAGETREE_H
#define IMAGETREE_H

#include <QMainWindow>

class QPlainTextEdit;
class QAction;
class QMenu;
class ImageTree : public QMainWindow
{
     Q_OBJECT
 public:
     explicit ImageTree(QWidget *parent=0);
     ~ImageTree();
 private slots:
     void test();
private:
     void createActions();
     void createMenus();
     //文本框
     QPlainTextEdit *textEdit;
     //file菜单
     QMenu * fileMenu;
     //定义了file的下拉菜单为 new  open  save  saveAS  exit
     QAction *newAct;
     QAction *open;
     QAction *Save;
     QAction *saveAs;
     QAction *exit;
};



#endif // IMAGETREE_H

