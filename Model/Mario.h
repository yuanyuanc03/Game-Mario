#ifndef MARIO_H
#define MARIO_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class Mario: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Mario(QGraphicsItem *parent=0);
    ~Mario();
    void keyPressEvent(QKeyEvent *event);
    void Score();
    QMediaPlayer * deathsound;
public slots:
    void Jump();
};

#endif // MARIO_H
