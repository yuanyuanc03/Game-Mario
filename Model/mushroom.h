#ifndef MUSHROOM_H
#define MUSHROOM_H

#include <QMediaPlayer>
#include "model.h"

class Mushroom: public Model
{
public:
    //constructor
    Mushroom(int, int, bool);

    //setters and getters
    int getMoveCount() { return this->moveCount; }
    void setmoveCount(int moveCount) { this->moveCount = moveCount; }
    bool getUp() { return this->up; }
    void setUp(bool upDown) { this->up = upDown; }
    QMediaPlayer* getMushroomAppear() { return this->mushroomappear; }
    QMediaPlayer* getMushroomEat() { return this->mushroomeat; }
    void setMushroomAppear(QMediaPlayer* mAppear) { this->mushroomappear = mAppear; }
    void setMushroomEat(QMediaPlayer* mEat) { this->mushroomeat = mEat; }

private:
    int moveCount = 37;
    bool up = true;
    QMediaPlayer * mushroomappear;
    QMediaPlayer * mushroomeat;
};

#endif // MUSHROOM_H
