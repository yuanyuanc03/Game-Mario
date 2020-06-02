#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QObject>
#include <QtWidgets>
#include "Model/mario.h"
#include "Model/gold.h"
#include "Model/score.h"
#include "Model/time.h"
#include "Model/background.h"
#include "Controller/gamecontroller.h"

class GameController;

class View: public QWidget
{
    //Q_OBJECT
//public:
//    View(QWidget *parent=0);

//    QGraphicsScene * scene;
//    QGraphicsView * view;
//    QLabel * label;
//    QPainter painter;
//    Background * background;
//    Mario * mario;
//    Gold * gold;
//    Score * score;
//    Time * time;

    Q_OBJECT
public:
    //constructor and destructor
    View(QWidget *parent = 0);
     ~View();

    //setters and getters
    GameController *getController() { return this->controller; }
    void setController(GameController *controller) { this->controller = controller; }

private:
    //private methods
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    //private attributes
    GameController *controller;
    bool pauseFlag = false;
    //int marioSize;
    //QTimer *autoMoveTimer;
};

#endif // VIEW_H
