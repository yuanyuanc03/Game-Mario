#include "darkeater.h"


DarkEater::DarkEater(int x, int y) : Model(x, y, ":/files/images/dark_eater.png")
{
    //set darkeater size
    this->rect = QRect(x, y + 5, this->getModel().width()/3, this->getModel().height());

    //darkeater music
    this->boom = new QMediaPlayer();
    this->boom->setMedia(QUrl("qrc:/files/sounds/boom.wav"));
}
