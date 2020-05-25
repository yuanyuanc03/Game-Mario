#include "sprite.h"
#include <QTextStream>
#include <QPainter>
#include <QBitmap>
#include <View/view.h>

using namespace std;

Sprite::Sprite(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    //transparent bg
    //setAttribute(Qt::WA_TranslucentBackground);

    imgPixmap = new QPixmap();
    imgPixTmp = new QPixmap();
    timer = new QTimer();
    memset(&priv_ImgData,0,sizeof(SpriteImageData));
    priv_IsTimeSet = false;
    priv_Status = STATUS_IDLE;
    count = 0;
}
