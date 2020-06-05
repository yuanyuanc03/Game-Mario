#ifndef TIME_H
#define TIME_H

#include <QObject>
#include "Model/model.h"

class Time: public QObject, public Model
{
    Q_OBJECT
public:
    //constructor
    Time(int, int);

    //setters and getters
    int getTime() { return time; }
    void setTime(int i) { this->time = i; }

    //public attributes
    QTimer * timer;

public slots:
    //public slots
    void realTime();

private:
    //private attributes
    int time; //time count
};


#endif // TIME_H
