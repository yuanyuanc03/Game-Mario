#ifndef GOLD_H
#define GOLD_H

#include <QMediaPlayer>
#include "model.h"

class Gold: public Model
{
public:
    //constructor
    Gold(int, int);

    //public attributes
    static int currentFrame;

    //public methods
    void accept(Paint *paint) { paint->drawModel(this); }

    //setters and getters
    QMediaPlayer* getGold() { return this->gold; }
    void setGold(QMediaPlayer* gold) { this->gold = gold; }

private:
    //private attributes
    QMediaPlayer * gold;
};

#endif // GOLD_H
