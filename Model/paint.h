#ifndef PAINT_H
#define PAINT_H

#include <QPainter>
#include <QPaintDevice>
#include <QPaintEngine>
class Model;
class Player;

class Paint
{
public:
    //constructor and destructor
    Paint(QPainter *painter);
    ~Paint();

    //setters and getters
    QPainter *getPainter(){ return painter; }

    //public methods
    void drawModel(Model *model);
    void drawPlayer(Player *player);

private:
    QPainter *painter;
};

#endif // PAINT_H
