#include "imagetree.h"
#include "ui_imagetree.h"
#include <QContextMenuEvent>
#include <QPlainTextEdit>
ImageTree::ImageTree(QWidget *parent) :
    QMainWindow(parent)
//    ui(new Ui::ImageTree)
{
   // ui->setupUi(this);
    //创建一个文本编辑器
    textEdit = new QPlainTextEdit;
    //设置文本编辑器为中心位置
    setCentralWidget(textEdit);
    //首先创建file下拉的菜单栏
    createActions();
    //再来创建菜单目录，把下拉菜单的内容addaction加入到menu中
    createMenus();
}

ImageTree::~ImageTree()
{
//    delete ui;
}

void ImageTree::test()
{
//    textEdit->setTextCursor(QTextCursor::atEnd());
//    textEdit->setTextCursor(QTextCursor::block());
//    QPalette p=textEdit->palette();
//    p.setColor(QPalette::Active, QPalette::Base, Qt::red);
//    p.setColor(QPalette::Inactive, QPalette::Base, Qt::red);
      textEdit->setStyleSheet("background-color:lightYellow;");
//    textEdit=
}
 //file下拉菜单 名字为 new  open  Save  saveAs exit new.png为图标 添加了快捷键  以及添加点击这个下拉菜单所条用的槽函数，这里使用test作为测试使用
void ImageTree::createActions()
{
     newAct = new QAction(QIcon(":/image/new.png"), tr("&New"), this);
//     newAct->setShortcuts(QKeySequence::New);
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(test())); //New点击事件调用test

     open = new QAction(QIcon(":/image/open.png"), tr("&Open"), this);
     open->setShortcuts(QKeySequence::Open);
     open->setStatusTip(tr("open a new file"));
     connect(open, SIGNAL(triggered()), this, SLOT(test())); //点击Open事件调用test

     Save = new QAction(QIcon(":/image/save.png"), tr("&Save"), this);
     Save->setShortcuts(QKeySequence::Save);
     Save->setStatusTip(tr("Save a new file"));
     connect(Save, SIGNAL(triggered()), this, SLOT(test())); //点击Save事件调用test

     saveAs = new QAction( tr("&SaveAs"), this);
     saveAs->setShortcuts(QKeySequence::SaveAs);
     newAct->setStatusTip(tr("SaveAs a new file"));
     connect(saveAs, SIGNAL(triggered()), this, SLOT(test())); //saveAS点击事件调用test

     exit = new QAction( tr("&exit"), this);
     exit->setShortcuts(QKeySequence::Close);
     exit->setStatusTip(tr("exit a new file"));
     connect(exit, SIGNAL(triggered()), this, SLOT(close()));   //点击exit事件调用test
}
void ImageTree::createMenus()
{
     //创建一个name为file的菜单栏
     fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *menu=menuBar()->addMenu(tr("&保存"));
    menu->addAction(open);
     //在这个菜单栏添加action即下拉菜单
     fileMenu->addAction(newAct);
     fileMenu->addAction(open);
     fileMenu->addAction(Save);
     fileMenu->addAction(saveAs);
     //添加一个分割器
     fileMenu->addSeparator();
     //推出下拉菜单
     fileMenu->addAction(exit);
}
