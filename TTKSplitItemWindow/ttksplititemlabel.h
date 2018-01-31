#ifndef TTKSPLITITEMLABEL_H
#define TTKSPLITITEMLABEL_H


#include <QLabel>

class TTKSplitItemLabel : public QLabel
{
    Q_OBJECT
public:
    explicit TTKSplitItemLabel(QWidget *parent = 0);

Q_SIGNALS:
    void changed(const QString &value);

private:
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    QRectF m_lineGeometry;
    QString m_currentString;

};

#endif // TTKSPLITITEMLABEL_H
