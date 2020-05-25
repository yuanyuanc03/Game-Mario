#ifndef DARKEATER_H
#define DARKEATER_H

#include <QMediaPlayer>
#include "model.h"

class DarkEater: public Model
{
public:
    //construcctor
    DarkEater(int, int);

    //public attributes
    static int currentFrame;

    //setters and getters
    QMediaPlayer* getBoom() { return this->boom; }
    void setBoom(QMediaPlayer* boom) { this->boom = boom; }

private:
    //private attributes
    QMediaPlayer * boom;
};

#endif // DARKEATER_H
