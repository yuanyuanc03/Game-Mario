#include "View.h"
#include <QTimer>
#include <QObject>
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>

View::View(QWidget *parent): QGraphicsScene(parent)
{
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    mario = new Mario();
    gold = new Gold();
    background = new Background();

    //configuration of view
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    view->show();
    scene->setSceneRect(0,0,800,600);
    view->setBackgroundBrush(QBrush(background->getImage()));

    //add mario in the view
    scene->addItem(mario);
    mario->setPos(view->width()/4, view->height()/2);

    //The Text of score
    score = new Score();
    scene->addItem(score);

    //The text of the timer
    time = new Time();
    scene->addItem(time);

    //Generate the gold
    QObject::connect(gold->timer,SIGNAL(timeout()),gold,SLOT(Spawn()));
    gold->timer->start(2000);

    //Timer of the game which is set 300s by default
    QObject::connect(time->timer,SIGNAL(timeout()),time,SLOT(realTime()));
    time->timer->start(1000);
}

