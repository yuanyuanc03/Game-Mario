#ifndef FLAME_H
#define FLAME_H

#include <QMediaPlayer>
#include "model.h"

class Flame: public Model
{
public:
    //constructor
    Flame(int, int);

    //public attributes
    static int currentFrame;

    //public methods
    void accept(Paint *paint) { paint->drawModel(this); }

    //setters and getters
    QMediaPlayer* getFire() { return this->fire; }
    void setFire(QMediaPlayer* fire) { this->fire = fire; }

private:
    //private attributes
    QMediaPlayer * fire;
};

#endif // FLAME_H
