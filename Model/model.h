#ifndef MODEL_H
#define MODEL_H
#include <QString>
#include <QGraphicsItem>
#include "paint.h"

class Model
{
public:
    //constructor and destructor
    Model(int, int);
    Model(int, int, QString);
    ~Model();

    //setters and getters
    void setMoveX(bool moveX) { this->moveX = moveX; }
    void setXR(int x) { this->xR = x; }
    void setYR(int y) { this->yR = y; }
    void setStartY(int startY) { this->startY = startY; }
    bool getMoveX() { return this->moveX; }
    int getXR() { return this->xR; }
    int getYR() { return this->yR; }
    int getStartY() { return this->startY; }
    inline bool isDestroyed() { return destroyed; }
    inline void setDestroyed(bool destroyed) { this->destroyed = destroyed; }
    inline QImage getImage() { return this->image; }
    inline QPixmap getModel() { return this->model; }
    inline QRect getRect() { return this->rect; }
    inline QRect getSrcRect() { return this->srcRect; }
    inline QRect getDieRect() { return this->dieRect; }
    inline void setImage() { this->image.load(this->path); }
    inline void setImageWithPath(QString path) {this->image.load(path); }
    inline void setModelWithPath(QString path) { this->model.load(path); }
    inline void setModel() { this->model.load(this->path); }
    inline void setRect(QRect rect) { this->rect = rect; }
    inline void setSrcRect(QRect srcRect) { this->srcRect = srcRect; }
    inline void setDieRect(QRect dieRect) { this->dieRect = dieRect; }

    //public methods
    void move(int, int);
    void moveLModel();
    void moveRModel();
    bool intersectTop(QRect);
    bool intersectBottom(QRect);
    bool intersectRight(QRect);
    bool intersectLeft(QRect);
    void accept(Paint *paint) { paint->drawModel(this); }
    void convertPNG(QString path);

    //public attributes
    static int speed;

private:
    //private attributes
    bool destroyed;
    bool moveX = true;
    int xR = 0;
    int yR = 0;
    int startY;

protected:
    //protected attributes
    QString path;
    QImage image;
    QPixmap model;
    QRect rect;
    QRect dieRect;
    QRect srcRect;
};

#endif // MODEL_H
