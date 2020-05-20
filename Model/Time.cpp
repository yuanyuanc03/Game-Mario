#include "Time.h"
#include <QFont>
#include <QTimer>
#include <QMessageBox>
#include <QImage>
#include <QBrush>
#include <QPixmap>
#include <QString>
#include <QRect>
#include "View/View.h"
extern View * view;

Time::Time(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    time = 10;
    timer = new QTimer();
    setPlainText(QString("Time: ") + QString::number(time));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 12));
    setPos(500,0);
}

int Time::getTime()
{
    return time;
}

void Time::realTime()
{
    if(time != 0)
    {
        time--;
        setPlainText(QString("Time: ") + QString::number(time));
    }
    else
    {
        setPlainText(QString("Time: ") + QString::number(time));
        view->background->bgsound->stop();
        view->mario->deathsound->play();
        //view->background->setImage("D:/yuanyuan/2019-2020_semestre2/Platform C++/Projet/MarioProjet/Game-Mario/files/images/images/gameover.png");
        this->timer->stop();
        view->gold->timer->stop();
    }
}
