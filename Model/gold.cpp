#include "gold.h"


Gold::Gold(int x, int y) : Model(x, y, ":/files/images/gold_sprites.png")
{
    //set gold size
    //this->setModel();
    this->setRect(QRect(x, y, this->getModel().width()/3,this->getModel().height()));

    //gold sound
    this->gold = new QMediaPlayer();
    this->gold->setMedia(QUrl("qrc:/files/sounds/coin.wav"));
    //this->gold->play();
}

