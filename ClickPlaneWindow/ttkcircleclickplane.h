#ifndef TTKCIRCLECLICKPLANE_H
#define TTKCIRCLECLICKPLANE_H


#include <QWidget>


class TTKCircleClickPlane : public QWidget
{
    Q_OBJECT
public:
    explicit TTKCircleClickPlane(QWidget *parent = 0);
    ~TTKCircleClickPlane();

protected Q_SLOTS:
    void updateValue();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;

    bool m_circleOn;
    QTimer *m_circleTimer;
    int m_crValue;
    QPoint m_pos;

};

#endif // TTKCIRCLECLICKPLANE_H
