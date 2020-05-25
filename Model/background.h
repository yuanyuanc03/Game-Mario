#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QMediaPlayer>
#include "model.h"

class Background: public Model
{
public:
    //constructor
    Background(int,int);

    //setters and getters
    QMediaPlayer* getBgMusic() { return this->bgmusic; }
    void setBgSound(QMediaPlayer* bgmusic) { this->bgmusic = bgmusic; }

    //public methods
    void moveBg();
    void playBgMusic();

private:
    //private attributes
    QMediaPlayer * bgmusic;
};

#endif // BACKGROUND_H
