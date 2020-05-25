#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <QPaintEvent>
#include <QWidget>
#include <QGraphicsItem>

class Sprite: public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //constructor and destructor
    Sprite(QGraphicsItem *parent=0);

    //public methods
    int SetImageFile(QPixmap *Pixmap,int UnitX,int UnitY);
    int RunSprite(void);
    int SetTime(int delay);
    void SetPosition(int X,int Y);

private:
    //run state
    enum
    {
        STATUS_IDLE = 0,
        STATUS_RUN,
        STATUS_STOP,
        STATUS_PAUSE,
        STATUS_RESUME,
    };

    //input struct
    typedef struct Position_XY
    {
        int X;
        int Y;
    }PositionXY;

    //image struct
    typedef struct Sprite_Image_Data
    {
        PositionXY imgXY;
        PositionXY imgHW;
        PositionXY UnitXY;
        int imgTime;
    }SpriteImageData;

    //public attributes
    SpriteImageData priv_ImgData;
    QPixmap * imgPixmap;
    QPixmap * imgPixTmp;
    QTimer * timer;

    bool priv_IsTimeSet;
    int priv_Status;
    int count;

private slots:
    void SpriteUpdate(void);

protected:
    void paintEvent(QPaintEvent *);

};

#endif // SPRITE_H
