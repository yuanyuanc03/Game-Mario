#ifndef GOLD_H
#define GOLD_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Gold: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Gold(QGraphicsItem *parent=0);
    QTimer * timer;
public slots:
    void Spawn();
};

#endif // GOLD_H
