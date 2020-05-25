#include "brick.h"


Brick::Brick(int x, int y) : Model(x, y, ":/files/images/safegold.png")
{
    //brick music
    brickhit = new QMediaPlayer();
    brickhit->setMedia(QUrl("qrc:/files/sounds/blockhit.war"));

    brickbreak = new QMediaPlayer();
    brickbreak->setMedia(QUrl("qrc:/files/sounds/blockbreak.war"));
}
