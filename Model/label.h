#ifndef LABEL_H
#define LABEL_H

#include "model.h"

enum struct LabelType {GOLD, LOVE, HURT, FUCK, NONE};

class Label: public Model
{
public:
    //constructor
    Label(int, int, QString);

    //setters and getters
    void setShow(bool show) { this->show = show; }
    bool getShow() { return this->show; }
    inline void setType(LabelType type) { this->type = type; }
    inline LabelType getType() { return this->type; }

private:
    //private attributes
    bool show = false;
    LabelType type;
};

#endif // LABEL_H
