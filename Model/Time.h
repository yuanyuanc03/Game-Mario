#ifndef TIME_H
#define TIME_H
#include <QGraphicsTextItem>
#include <QObject>

class Time: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Time(QGraphicsItem * parent = 0);
    int getTime();
    QTimer * timer;
public slots:
    void realTime();
private:
    int time;
};


#endif // TIME_H
