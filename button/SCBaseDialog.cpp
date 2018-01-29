#include "SCBaseDialog.h"
#include "ui_SCBaseDialog.h"
#include "SCChildDialog.h"
#include <QtMath>
#include <QMouseEvent>
SCBaseDialog::SCBaseDialog(QWidget *child,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SCBaseDialog)
{
    ui->setupUi(this);

    this->setModal(false);
    //设置窗体无边框
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    this->setAttribute(Qt::WA_SetWindowModality);
    //---------------------------------------
//    pHelper = new FramelessHelper(this);
//    pHelper->activateOn(this);  //激活当前窗体
//    pHelper->setTitleHeight(36);  //设置窗体的标题栏高度
//    pHelper->setBorderWidth(6);  //设置窗体鼠标拉伸有效宽度
//    pHelper->setWidgetMovable(true);  //设置窗体可移动
//    pHelper->setWidgetResizable(true);  //设置窗体可缩放
//    pHelper->setRubberBandOnMove(false);  //设置橡皮筋效果-可移动
//    pHelper->setRubberBandOnResize(false);  //设置橡皮筋效果-可缩放
    //------------------------------------------
    ui->pushButton_max->setProperty("windowMaxsized",false);
    ui->label_icon->clear();
    ui->label_title->clear();
    ui->verticalLayout_addWidget->addWidget(child);
    pButtonGroup = new QButtonGroup(this);
    connect(pButtonGroup,SIGNAL(buttonClicked(int)),child,SLOT(slotButtonClicked(int)));
    pButtonGroup->addButton(ui->pushButton_mini,E_MinButton);
    pButtonGroup->addButton(ui->pushButton_max,E_MaxButton);
    pButtonGroup->addButton(ui->pushButton_close,E_CloseButton);
    ui->pushButton_close->setToolTip(tr("关闭"));
    ui->pushButton_max->setToolTip(tr("最大化"));
    ui->pushButton_mini->setToolTip(tr("最小化"));
    //setHideButton(E_MinButton);//隐藏最小化按钮
}
///析构
SCBaseDialog::~SCBaseDialog()
{
   // delete pHelper;
    while(ui->verticalLayout_addWidget->count()){
        QLayoutItem*item = ui->verticalLayout_addWidget->takeAt(0);
        qDebug()<<"~"<<item->widget()->metaObject()->className();
        delete item->widget();
        delete item;
    }
    delete ui;
    qDebug()<<"~"<<this->metaObject()->className();
}
void SCBaseDialog::slotButtonClicked(int button_type)
{
    switch(button_type)
    {
    case  E_MinButton :
       ui->pushButton_mini->showMinimized();
               break;
    case  E_MaxButton:
        ui->pushButton_max->showMaximized();
        break;
    case E_CloseButton:
         ui->pushButton_close->close();
        break;
    }
}

void SCBaseDialog::addTitleMenu(QWidget *w)
{
    ui->horizontalLayout_titleMenu->addWidget(w);
}
///额外添加自定义按钮
void SCBaseDialog::addTitleButton(QWidget*w)
{
    ui->horizontalLayout_titleButton->insertWidget(0,w);
}
///绘制背景
void SCBaseDialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QColor color(0, 170, 240, 50);
    if(_isActiveWindow){
        color.setRgb(0, 170, 240, 50);
    }else{
        color.setRgb(0, 0, 0, 50);
    }
    QPainter painter(this);
    QList<int>alphaList;
    alphaList<<50<<30<<20<<10<<5<<2;
    for(int i=0; i<6; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(6-i, 6-i, this->width()-(6-i)*2, this->height()-(6-i)*2);
        int alpha = alphaList.at(i);
        //        qDebug()<<"alpha:"<<alpha<<"150"<<qSqrt(i)*50;
        color.setAlpha(alpha);
        painter.setPen(color);
        painter.drawPath(path);
    }
}
///隐藏标题栏
void SCBaseDialog::setHiddenTitle(bool hidden)
{
    ui->widget_title->setHidden(hidden);
}
///只显示关闭按钮
void SCBaseDialog::justShowCloseButton()
{
    setHideButton(E_MinButton);
    setHideButton(E_MaxButton);
}
///隐藏指定按钮
void SCBaseDialog::setHideButton(ButtonID id)
{
    pButtonGroup->button(id)->setHidden(true);
}
///显示指定按钮
void SCBaseDialog::setShowButton(ButtonID id)
{
    pButtonGroup->button(id)->setHidden(false);
}
///标题栏文字，和窗口任务链文字
void SCBaseDialog::setTitleText(const QString &title,bool isWindowTitle)
{
    ui->label_title->setText(title);
    if(isWindowTitle){
        this->setWindowTitle(title);
    }
}
///槽-最小化
void SCBaseDialog::clieckedMinBtn()
{
    this->showMinimized();
}
///槽-最大化，还原
void SCBaseDialog::clieckedMaxBtn()
{
    if(this->isMaximized()){
        this->showNormal();
    }else{
        this->showMaximized();
    }
}
///槽-关闭
void SCBaseDialog::clieckedCloseBtn()
{
    this->close();
}
//void SCBaseDialog::keyPressEvent(QKeyEvent *key)
//{
//    pChildWidget->keyPressEvent(key);
//}
//void SCBaseDialog::keyReleaseEvent(QKeyEvent *event)
//{
//     pChildWidget->keyReleaseEvent(event);
//}
//void SCBaseDialog::mouseReleaseEvent(QMouseEvent *event)
//{
//     pChildWidget->mouseReleaseEvent(event);
//}
//void SCBaseDialog::mouseMoveEvent(QMouseEvent *event)
//{
//     pChildWidget->mouseMoveEvent(event);
//}
//void SCBaseDialog::mousePressEvent(QMouseEvent *event)
//{
//     pChildWidget->mousePressEvent(event);
//}
void SCBaseDialog::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(ui->widget_title->rect().contains(event->pos())){
        //        pChildWidget->mouseDoubleClickEvent(event);
        clieckedMaxBtn();
    }
}

void SCBaseDialog::changeEvent(QEvent *e)
{
    if(e->type() == QEvent::WindowStateChange)
    {
        if(this->windowState() & Qt::WindowMinimized)
        {
            //do something after minimize

        }else{
            if(this->windowState() & Qt::WindowMaximized){
                ui->pushButton_max->setProperty("windowMaxsized",true);
               // ui->verticalLayout_2->setContentsMargins(0,0,0,0);
                ui->pushButton_max->setToolTip(tr("还原"));
            }else{
                ui->pushButton_max->setProperty("windowMaxsized",false);
              //  ui->verticalLayout_2->setContentsMargins(6,6,6,6);
                ui->pushButton_max->setToolTip(tr("最大化"));
            }
            ui->pushButton_max->style()->polish(ui->pushButton_max);
            ui->pushButton_max->update();
        }
    }else if(e->type()==QEvent::ActivationChange){
        //        qDebug()<<"------SCBaseDialog---------ActivationChange;";
        if(this->isActiveWindow()){
            _isActiveWindow = true;
            //            qDebug()<<"------SCBaseDialog---------WindowActive;";
        }else{
            _isActiveWindow = false;
            //            qDebug()<<"------SCBaseDialog---------WindowNoActive;";
        }
    }else if(e->type() == QEvent::WindowActivate){
        //        qDebug()<<"-------SCBaseDialog--------WindowActivate;";
    }else if(e->type()==QEvent::WindowDeactivate){
        //        qDebug()<<"-------SCBaseDialog--------WindowDeactivate;";
    }
    QDialog::changeEvent(e);
}
void SCBaseDialog::keyPressEvent(QKeyEvent *key)
{
    qDebug()<<"SCBaseDialog::keyPressEvent:"<<key;
    if(key->key() != Qt::Key_Escape){
        QDialog::keyPressEvent(key);
    }
}
