#ifndef PEACHPRINCESS_H
#define PEACHPRINCESS_H

#include <QMediaPlayer>
#include "player.h"

class Princess: public Player
{
public:
    //constructor
    Princess(int, int);

    //setters and getters
    QMediaPlayer* getPrincessSound() { return this->princesssound; }
    void setPrincessSound(QMediaPlayer* pSound) { this->princesssound = pSound; }

private:
    //private attributes
    QMediaPlayer * princesssound;
};

#endif // PEACHPRINCESS_H
