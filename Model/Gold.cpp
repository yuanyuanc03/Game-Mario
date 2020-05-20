#include "Gold.h"
#include "Mario.h"
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "View/View.h"

extern View * view;

Gold::Gold(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //draw mario
    setPixmap(QPixmap("D:/yuanyuan/2019-2020_semestre2/Platform C++/Projet/MarioProjet/Game-Mario/files/images/images/gold_big.png"));

    //default settings
    int random_number = rand() % 700;
    setPos(random_number,300);
    timer = new QTimer();
}

void Gold::Spawn()
{
    view->scene->addItem(new Gold());
}
