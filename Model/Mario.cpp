#include "Mario.h"
#include "Gold.h"
#include "View/View.h"
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
extern View * view;

Mario::Mario(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    //draw mario
    setPixmap(QPixmap("D:/yuanyuan/2019-2020_semestre2/Platform C++/Projet/MarioProjet/Game-Mario/files/images/images_backups/mario/mario.bmp"));

    //default settings
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    deathsound = new QMediaPlayer();
    deathsound->setMedia(QUrl("qrc:/yuanyuan/2019-2020_semestre2/Platform C++/Projet/MarioProjet/Game-Mario/files/sounds/death.mp3"));
}

Mario::~Mario()
{
    scene() -> removeItem(this);
    delete this;
}

void Mario::keyPressEvent(QKeyEvent * event)
{
    if (event->key() == Qt::Key_Left)
        setPos(x()-10,y());
    else if (event->key() == Qt::Key_Right)
        setPos(x()+10,y());
    else if (event->key() == Qt::Key_Space)
    {
        setPos(x(),y()-100);
        QTimer::singleShot(200,this,SLOT(Jump()));
    }
    Score();
}

void Mario::Jump()
{
    setPos(x(),y()+100);
}

void Mario::Score()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    foreach(QGraphicsItem * i, colliding_items)
    {
        Gold * gold = dynamic_cast<Gold *>(i);
        if(gold)
        {
            view->score->increase();
            scene()->removeItem(gold);
        }
    }
}
