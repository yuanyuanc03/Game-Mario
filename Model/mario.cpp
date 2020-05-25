#include "mario.h"


Mario::Mario(int x, int y): Player(x,y)
{
    this->moveR_player = QPixmap(":/files/images/mario_walk_sprites.png");
    this->moveL_Player = QPixmap(":/files/images/mario_walk_sprites_left.png");
    this->stop_player = QPixmap(":/files/images/mario_stop.png");
    this->goldNumber = 0;
    this->rect = QRect(x, y, 45, this->moveR_player.height() - 7);
    this->dieRect = QRect(x, y, 50, this->stop_player.height()-7);

    this->deathsound = new QMediaPlayer();
    this->deathsound->setMedia(QUrl("qrc:/files/sounds/death.wav"));
}

bool Mario::intersectTop(QRect rect)
{
    if(rect.intersected(this->getRect()).width() > 7 && this->getRect().y() > rect.y())
    {
        this->move(this->getRect().x(), rect.y() + 49);
        return true;
    }
    return false;
}

bool Mario::intersectBottom(QRect rect)
{
    if(rect.intersected(this->getRect()).width() > 5 && this->getRect().y() < rect.y())
    {
        this->move(this->getRect().x(), rect.y() - this->getRect().height() + 1);
        return true;
    }
    return false;
}

bool Mario::intersectRight(QRect rect)
{
    if(rect.intersected(this->getRect()).height() > 5 && this->getRect().x() < rect.x() )
        return true;
    return false;
}

bool Mario::intersectLeft(QRect rect)
{
    if(rect.intersected(this->getRect()).height() > 5 && this->getRect().x() > rect.x())
        return true;
    return false;
}

