#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QImage>

class Background: public QGraphicsPixmapItem
{
public:
    Background(QGraphicsItem *parent=0);
    QMediaPlayer * bgsound;
    QImage getImage(){ return image; }
    void setImage(QString path) {image = QImage(path);}
private:
    QImage image;
};

#endif // BACKGROUND_H
