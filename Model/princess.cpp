#include "princess.h"


Princess::Princess(int x, int y): Player(x, y)
{
    this->moveL_Player = QPixmap(":/files/images/peach_sprite.png");
    this->rect = QRect(x, y, this->moveL_Player.width(), this->moveL_Player.height() );

    //princess music
    this->princesssound = new QMediaPlayer();
    this->princesssound->setMedia(QUrl(":/files/sounds/princessmusic.wav"));
    this->princesssound->play();
}
