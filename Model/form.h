#ifndef FORM_H
#define FORM_H
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "sprite.h"

class Form : public QGraphicsView
{
    //Q_OBJECT
public:
    //constructor
    Form(QWidget *parent=0);

    //public attributes
    QGraphicsScene * scene;
    QGraphicsView * view;

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

    //private attributes
    SpriteImageData priv_ImgData;
    QPixmap * imgPixmap;
    QPixmap * imgPixTmp;
    QTimer * timer;

    bool priv_IsTimeSet;
    int priv_Status;
    int count;
    int x;
    int y;

    //private methods
    void KeyUpfunc(QKeyEvent *);
    void KeyDownfunc(QKeyEvent *);
    void KeyLeftfunc(QKeyEvent *);
    void KeyRightfunc(QKeyEvent *);

private slots:
    //private slots
    void SpriteUpdate(void);

protected:
    //protected methods
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
};

#endif // FORM_H
