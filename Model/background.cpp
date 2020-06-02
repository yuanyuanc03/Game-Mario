#include "background.h"


Background::Background(int x, int y) : Model(x, y, ":/files/images/background.png")
{
    //set background size
    this->rect.setSize(QSize(this->getImage().width() + 4, this->getImage().height()));

    //play background music
    this->bgmusic = new QMediaPlayer();
    this->bgmusic->setMedia(QUrl("qrc:/files/sounds/background.mp3"));
    this->playBgMusic();
}

void Background::moveBg()
{
    this->rect.moveTo(this->rect.left() - Model::speed/2, this->rect.top());
}

void Background::playBgMusic()
{
    //replay the music if timeout
    if(this->bgmusic->state() == QMediaPlayer::PlayingState)
        this->bgmusic->setPosition(0);
    else if(this->bgmusic->state() == QMediaPlayer:: StoppedState)
        this->bgmusic->play();
}
