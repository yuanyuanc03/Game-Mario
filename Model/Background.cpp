#include "Background.h"
#include <iostream>

Background::Background(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //image path
    image = QImage("D:/yuanyuan/2019-2020_semestre2/Platform C++/Projet/MarioProjet/Game-Mario/files/images/images/background.png");

    //play background music
    bgsound = new QMediaPlayer();
    bgsound->setMedia(QUrl("D:/yuanyuan/2019-2020_semestre2/Platform C++/Projet/MarioProjet/Game-Mario/files/sounds/background.mp3"));

    if(bgsound->state() == QMediaPlayer::PlayingState)
        bgsound->setPosition(0);
    else if(bgsound->state() == QMediaPlayer:: StoppedState)
        bgsound->play();
}
