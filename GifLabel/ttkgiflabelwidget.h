#ifndef TTKGifLabelWidget_H
#define TTKGifLabelWidget_H



#include <QLabel>

class QTimer;

class TTKGifLabelWidget : public QLabel
{
    Q_OBJECT
public:
    enum Type
    {
        Gif_Ballon_White,
        Gif_Cicle_Blue,
        Gif_Rice_Font_White,
        Gif_Rice_Font_Black,
        Gif_Rice_Font_Black_Big,
        Gif_Hourglass_White,
        Gif_Radio_Blue,
        Gif_Check_Blue,
        Gif_Record_red,
        Gif_Close_White
    };

    explicit TTKGifLabelWidget(QWidget *parent = 0);
    explicit TTKGifLabelWidget(Type type, QWidget *parent = 0);

    ~TTKGifLabelWidget();

    void setType(Type type);
    Type getType() const;

    void setInterval(int value);
    int getInterval() const;

    void setInfinited(bool s);
    bool getInfinited() const;

    void start();
    void stop();

    inline bool isRunning() const { return m_isRunning; }

public Q_SLOTS:
    void timeout();

protected:
    bool infinitedModeCheck();

    int m_index;
    Type m_type;
    QTimer *m_timer;
    bool m_isRunning, m_infinited;

};

#endif // TTKGifLabelWidget_H
