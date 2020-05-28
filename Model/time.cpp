#include "time.h"
#include <QTimer>


Time::Time(int x, int y): Model(x, y)
{
    this->time = 100;
    timer = new QTimer();
    QObject::connect(this->timer, SIGNAL(timeout()), this, SLOT(realTime()));
    this->timer->start(1000);
}

void Time::realTime()
{
    if(time != 0)
        time--;
}
