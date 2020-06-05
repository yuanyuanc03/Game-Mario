#ifndef BRICK_H
#define BRICK_H

#include <QMediaPlayer>
#include "model.h"

class Brick: public Model
{
public:
    //constructor
    Brick(int, int);

    //setters and getters
    QMediaPlayer* getBrikHit() { return this->brickhit; }
    QMediaPlayer* getBrickBreak() { return this->brickbreak; }
    void setBreakHit(QMediaPlayer* brickhit) { this->brickhit = brickhit; }
    void setBreakBreak(QMediaPlayer* brickbreak) { this->brickbreak = brickbreak; }
    int getCapacity() { return this->capacity; }
    void setCapacity( int cap) { this->capacity = cap; }

private:
    //private attributes
    int capacity = 0; //the capacity of brick indicate the number of times to break a brick
    QMediaPlayer * brickhit;
    QMediaPlayer * brickbreak;
};

#endif // BRICK_H
