#ifndef SHOCK_H
#define SHOCK_H

#include <QMediaPlayer>
#include "model.h"
#include "paint.h"

class Shock: public Model
{
public:
    //constructor
    Shock(int, int);

    //setters and getters
    void setShow(bool show) { this->show = show; }
    bool getShow() {return this->show; }

    //public attributes
    static int currentFrame;

    //public methods
    void accept(Paint *paint) { paint->drawModel(this); }

private:
    //private attributes
    bool show = false; //if shock shows or not
};

#endif // SHOCK_H
