#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsItem>

class Score
{
public:
    //constructor
    Score();

    //setters and getters
    QRect getRect() { return this->rect; }
    QColor getColor() { return this->color; }
    QString getText() { return this->text; }
    QImage getHeart() { return this->heart; }
    QRect getHeartSize() { return this->heartSize; }
    QImage getGold() { return this->gold; }
    QRect getGoldSize() { return this->goldSize; }
    QPoint getGoldPosition() { return this->goldPosition; }
    QImage getClock() { return this->clock; }
    QString getTime() { return this->time; }
    QPoint getClockPosition() { return this->clockPosition; }

private:
    //private attributes
    QRect rect;
    QColor color;
    QString text;
    QImage heart;
    QImage gold;
    QRect heartSize;
    QRect goldSize;
    QPoint goldPosition;
    QImage clock;
    QString time;
    QPoint clockPosition;
};

#endif // SCORE_H
