#ifndef BLOOD_H
#define BLOOD_H

#include "model.h"

class Blood: public Model
{
public:
    //constructor
    Blood(int, int);

    //setters and getters
    bool getStopBlood() { return show; }
    void setStopBlood(bool show) { this->show = show; }

private:
    bool show = false;
};

#endif // BLOOD_H
