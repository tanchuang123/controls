#include "maindlg.h"
#include <QPalette>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStringList>
#include <QColor>
#include <QPixmap>
#include <QSpinBox>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

MainDlg::MainDlg(QWidget *parent)
    : QDialog(parent)
{
    createCtrlFrame();
    createContentFrame();

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(ctrlFrame);
    mainLayout->addWidget(contentFrame);
    mainLayout->setMargin(10);
    mainLayout->setSpacing(5);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
}

MainDlg::~MainDlg()
{

}

void MainDlg::fillColorList(QComboBox *cbb)
{
    QStringList colorNameList = QColor::colorNames();

    QString colorName;
    foreach(colorName,colorNameList)
    {
        QPixmap pix_color(70,20);
        pix_color.fill(QColor(colorName));

        cbb->addItem(QIcon(pix_color),NULL);
        cbb->setIconSize(QSize(70,20));
        cbb->setSizeAdjustPolicy(QComboBox::AdjustToContents);   //设置下拉列表的尺寸符合内容的大小
    }
}

void MainDlg::createCtrlFrame()
{
    ctrlFrame = new QFrame;

    QLabel *labWindow = new QLabel(tr("QPalette::Window:"));
    QLabel *labWindowText = new QLabel(tr("QPalette::WindowText:"));
    QLabel *labButton = new QLabel(tr("QPalette::Button:"));
    QLabel *labButtonText = new QLabel(tr("QPalette::ButtonText:"));
    QLabel *labBase = new QLabel(tr("QPalette::Base:"));

    cbbWindow = new QComboBox;
    fillColorList(cbbWindow);
    connect(cbbWindow,SIGNAL(activated(int)),this,SLOT(sl_window()));
    cbbWindowText = new QComboBox;
    fillColorList(cbbWindowText);
    connect(cbbWindowText,SIGNAL(activated(int)),this,SLOT(sl_windowText()));
    cbbButton = new QComboBox;
    fillColorList(cbbButton);
    connect(cbbButton,SIGNAL(activated(int)),this,SLOT(sl_button()));
    cbbButtonText = new QComboBox;
    fillColorList(cbbButtonText);
    connect(cbbButtonText,SIGNAL(activated(int)),this,SLOT(sl_buttonText()));
    cbbBase = new QComboBox;
    fillColorList(cbbBase);
    connect(cbbBase,SIGNAL(activated(int)),this,SLOT(sl_base()));

    int col_lab = 0;
    int col_cbb = 1;
    QGridLayout *ctrlLayout = new QGridLayout(ctrlFrame);
    ctrlLayout->addWidget(labWindow,0,col_lab);
    ctrlLayout->addWidget(labWindowText,1,col_lab);
    ctrlLayout->addWidget(labButton,2,col_lab);
    ctrlLayout->addWidget(labButtonText,3,col_lab);
    ctrlLayout->addWidget(labBase,4,col_lab);
    ctrlLayout->addWidget(cbbWindow,0,col_cbb);
    ctrlLayout->addWidget(cbbWindowText,1,col_cbb);
    ctrlLayout->addWidget(cbbButton,2,col_cbb);
    ctrlLayout->addWidget(cbbButtonText,3,col_cbb);
    ctrlLayout->addWidget(cbbBase,4,col_cbb);
    ctrlLayout->setMargin(5);
    ctrlLayout->setSpacing(5);
}

void MainDlg::createContentFrame()
{
    contentFrame = new QFrame;

    QLabel *labValue = new QLabel(tr("Please select one of the values:"));
    QSpinBox *spbValue = new QSpinBox;
    QHBoxLayout *valueLayout = new QHBoxLayout;
    valueLayout->addWidget(labValue);
    valueLayout->addWidget(spbValue);
    valueLayout->setSpacing(5);

    QLabel *labString = new QLabel(tr("Please input a string"));
    QLineEdit *edtString = new QLineEdit;
    QHBoxLayout *stringLayout = new QHBoxLayout;
    stringLayout->addWidget(labString);
    stringLayout->addWidget(edtString);
    stringLayout->setSpacing(5);

    QTextEdit *edtHelloQt = new QTextEdit(tr("Hello Qt!"));

    QPushButton *btnOk = new QPushButton(tr("OK"));
    QPushButton *btnCancel =new QPushButton(tr("Cancel"));
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(btnOk);
    buttonLayout->addWidget(btnCancel);
    buttonLayout->setSpacing(5);

    QVBoxLayout *contentLayout = new QVBoxLayout(contentFrame);
    contentLayout->addLayout(valueLayout);
    contentLayout->addLayout(stringLayout);
    contentLayout->addWidget(edtHelloQt);
    contentLayout->addLayout(buttonLayout);
    contentLayout->setMargin(5);
    contentLayout->setSpacing(5);

    btnOk->setAutoFillBackground(true);
    btnCancel->setAutoFillBackground(true);
    contentFrame->setAutoFillBackground(true);
}

void MainDlg::sl_window()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[cbbWindow->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Window,color);
    contentFrame->setPalette(p);
}

void MainDlg::sl_windowText()
{
    QStringList colorList = QColor::colorNames();
    QColor color = QColor(colorList[cbbWindowText->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::WindowText,color);
    contentFrame->setPalette(p);
}

void MainDlg::sl_button()
{
    QStringList colorNameList = QColor::colorNames();
    QColor m_color = QColor(colorNameList[cbbButton->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Button,m_color);
    contentFrame->setPalette(p);
}

void MainDlg::sl_buttonText()
{
    QStringList colorNameList = QColor::colorNames();
    QColor m_color = QColor(colorNameList[cbbButtonText->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::ButtonText,m_color);
    contentFrame->setPalette(p);
}


void MainDlg::sl_base()
{
    QStringList colorNameList = QColor::colorNames();
    QColor m_color = QColor(colorNameList[cbbBase->currentIndex()]);
    QPalette p = contentFrame->palette();
    p.setColor(QPalette::Base,m_color);
    contentFrame->setPalette(p);
}
