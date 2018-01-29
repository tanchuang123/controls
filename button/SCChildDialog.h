#ifndef  SCChildDialog_H
#define SCChildDialog_H

#include <QDialog>
#include "SCBaseDialog.h"

class SCChildDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SCChildDialog(QWidget *parent = nullptr);
    ~SCChildDialog();
   SCBaseDialog *baseDialog = Q_NULLPTR;

   void releaseThis(SCChildDialog **w);
   void setModal(bool modal);
   void hide();
   void show();
   void setTitleText(const QString &title);
   void resize(int w, int h);
   void setHiddenTitle(bool hidden);
   void close();
   void addTitleButton(QWidget *w);
   bool isHidden();
   Qt::WindowFlags windowFlags() const;
   void setWindowFlags(Qt::WindowFlags flags);
   void setWindowFlag(Qt::WindowType type, bool on = true);
   void setAttribute(Qt::WidgetAttribute bute, bool on = true);
   QRect rect() const;
   int height() const;
   int width() const;
   void init();
signals:

public slots:
    virtual void clieckedMinBtn();
    virtual void clieckedMaxBtn();
    virtual void clieckedCloseBtn();
    void slotButtonClicked(int id);
protected:
//    bool eventFilter(QObject *obj, QEvent *event);
private:

};

#endif //SCChildDialog_H
