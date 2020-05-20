#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QtWidgets>
#include "Model/Mario.h"
#include "Model/Gold.h"
#include "Model/Score.h"
#include "Model/Time.h"
#include "Model/Background.h"

class View: public QGraphicsScene, public QGraphicsView
{
    //Q_OBJECT
public:
    View(QWidget *parent=0);

    QGraphicsScene * scene;
    QGraphicsView * view;
    QLabel * label;
    QPainter painter;
    Background * background;
    Mario * mario;
    Gold * gold;
    Score * score;
    Time * time;
};

#endif // VIEW_H
