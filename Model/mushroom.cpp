#include "mushroom.h"


Mushroom::Mushroom(int x, int y , bool up) : Model(x, y, ":/files/images/champ.png")
{
    this->up = up;

    //mushroom music
    this->mushroomappear = new QMediaPlayer();
    this->mushroomappear->setMedia(QUrl(":/files/sounds/mushroomappear.war"));
    this->mushroomappear->play();
    this->mushroomeat = new QMediaPlayer();
    this->mushroomeat->setMedia(QUrl(":/files/sounds/mushroomeat.war"));
}

