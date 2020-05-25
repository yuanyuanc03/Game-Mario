#include "flame.h"


Flame::Flame(int x, int y) : Model(x, y, ":/files/images/fire.png")
{
    //set flame size
    this->setModel();
    this->rect = QRect(x, y - 10, this->getModel().width()/9, this->getModel().height());

    //fire music
    this->fire = new QMediaPlayer();
    this->fire->setMedia(QUrl("qrc:/files/sounds/fire.war"));
}
