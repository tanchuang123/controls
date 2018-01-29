#include "SCChildDialog.h"


SCChildDialog::SCChildDialog(QWidget *parent) : QDialog(parent),
    baseDialog(new SCBaseDialog(this,parent))
{
   baseDialog=new SCBaseDialog(this);
  // init();
}
SCChildDialog::~SCChildDialog()
{
}
//void SCChildDialog::init()
//{
//    width();
//    height();
//    rect();
//    windowFlags();
//   // setWindowFlags(Qt:: WindowNoState);
//    setWindowFlag(Qt::Dialog,true);
//    setAttribute(Qt:: WA_Disabled, true);
//}
//bool SCChildDialog::eventFilter(QObject *obj, QEvent *event)
//{
//    return SCChildDialog::eventFilter(obj, event);
//}
int SCChildDialog::width()const
{
    return baseDialog->width();//对话框宽度
}
int SCChildDialog::height()const
{
    return baseDialog->height();//对话框高度
}
QRect SCChildDialog::rect()const//生成矩形对话框
{
    return baseDialog->rect();
}
Qt::WindowFlags SCChildDialog::windowFlags()const//风格
{
    return baseDialog->windowFlags();
}
void SCChildDialog::setWindowFlags(Qt::WindowFlags flags)//建立窗口状态
{
    baseDialog->setWindowFlags(flags);
}
void SCChildDialog::setWindowFlag(Qt::WindowType type,bool on)//窗口类型
{
    baseDialog->setWindowFlag(type,on);
}
void SCChildDialog::setAttribute(Qt::WidgetAttribute bute, bool on)//创建窗体属性
{
    baseDialog->setAttribute(bute,on);
}
bool SCChildDialog::isHidden()//隐藏
{
    return baseDialog->isHidden();
}
void SCChildDialog::show()
{
    baseDialog->show();
}
void SCChildDialog::hide()
{
    baseDialog->hide();
}
void SCChildDialog::close()
{
    baseDialog->close();
}
void SCChildDialog::addTitleButton(QWidget*w)
{
    baseDialog->addTitleButton(w);//添加自定义按钮
}
void SCChildDialog::setHiddenTitle(bool hidden)
{
    baseDialog->setHiddenTitle(hidden);//隐藏标题栏
}
void SCChildDialog::resize(int w,int h)
{
    baseDialog->resize(w,h);//调整对话框大小
}
void SCChildDialog::setModal(bool modal)
{
    baseDialog->setModal(modal);//对话框的模态性
}
void SCChildDialog::setTitleText(const QString& title)
{
    baseDialog->setTitleText(title);//标题栏文字，和窗口任务链文字
    this->setWindowTitle(title);//窗口标题
}
//释放
void SCChildDialog::releaseThis(SCChildDialog **w)
{
    if(this && w){
        if(baseDialog){
            delete baseDialog;//释放baseDialog指向的内存地址（包括*w的内存）
        }
        *w = Q_NULLPTR;//w指向的内存地址
        w = Q_NULLPTR;//w本身的内存地址
    }
}
void SCChildDialog::slotButtonClicked(int id)
{
    switch (id) {
    case SCBaseDialog::E_MinButton:
        clieckedMinBtn();
        break;
    case SCBaseDialog::E_MaxButton:
        clieckedMaxBtn();
        break;
    case SCBaseDialog::E_CloseButton:
        clieckedCloseBtn();
        break;
    default:
        break;
    }
}

void SCChildDialog::clieckedMinBtn()
{
    baseDialog->clieckedMinBtn();
}
void SCChildDialog::clieckedMaxBtn()
{
    baseDialog->clieckedMaxBtn();
}
void SCChildDialog::clieckedCloseBtn()
{
    baseDialog->clieckedCloseBtn();
}
