#ifndef MODEL_H
#define MODEL_H
#include <QMap>
#include <QMutableMapIterator>
#include <QFile>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QChar>
#include "Mario.h"
#include "Gold.h"
#include "Mushroom.h"
#include "Brick.h"

class ModelList
{
public:
    ModelList();
    ~ModelList();
    inline QList<Mushroom*> *getMushrooms(){ return mushrooms; }
    inline QList<Gold*> *getGolds(){ return golds; }
    inline QList<Brick*> *getBricks(){ return bricks; }

private:
    Mario * mario;
    QList<Gold*> * golds;
    QList<Mushroom*> * mushrooms;
    QList<Brick*> * bricks;
};

#endif // MODEL_H
