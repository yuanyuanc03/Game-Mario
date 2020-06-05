#include "score.h"
#include <QFont>


Score::Score()
{
    //the position of the score and time
    this->rect = QRect(0, 0, 900, 40);
    this->color = QColor(Qt::white);
    this->text = QString("life");

    //load the heart image
    this->heart = QImage();
    this->heart.load(":/files/images/heart.png");
    this->heartSize = heart.rect();
    this->gold.load(":/files/images/gold_small.png");
    this->goldSize = gold.rect();
    this->goldPosition = QPoint(this->getRect().width() + 40 - 400 , this->getRect().height() - 10);
    this->clock.load(":/files/images/clock.png");
    this->clock = this->clock.scaled(30, 30);
    this->clockPosition = QPoint(this->getRect().width() + 30 , this->getRect().height() - 10);
}



