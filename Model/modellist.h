#ifndef MODELLIST_H
#define MODELLIST_H
#include "Model/background.h"
#include "Model/blood.h"
#include "Model/brick.h"
#include "Model/darkeater.h"
#include "Model/flame.h"
#include "Model/floor.h"
#include "Model/gold.h"
#include "Model/label.h"
#include "Model/mario.h"
#include "Model/mushroom.h"
#include "Model/princess.h"
#include "Model/score.h"
#include "Model/shock.h"
#include "Model/splashscreen.h"
#include "Model/tree.h"
#include "Model/model.h"
#include "Model/time.h"
#include <QList>
class Background;
class Blood;
class Brick;
class DarkEater;
class Flame;
class Floor;
class Gold;
class Label;
class Mario;
class Mushroom;
class Princess;
class Score;
class Shock;
class SplashScreen;
class Tree;
class Model;
class Time;

class ModelList
{
public:
    //constructor and destructor
    ModelList();
    ~ModelList();

    //setters and getters
    inline Mario *getMario() { return this->mario; }
    inline Princess *getPrincess() { return this->princess; }
    inline Blood *getBlood() { return this->blood; }
    inline Score *getScore() { return this->score; }
    inline Shock *getShock() { return this->shock; }
    inline Label *getLabel() { return this->label; }
    inline Time *getTime() { return this->time; }
    inline SplashScreen *getSplashScreen() {return this->splashscreen; }
    inline QList<Gold*> *getGolds() { return this->golds; }
    inline QList<Mushroom*> *getMushrooms() { return this->mushrooms; }
    inline QList<Brick*> *getBricks() { return this->bricks; }
    inline QList<Floor*> *getFloors() { return this->floors; }
    inline QList<Background*> *getBackground() { return this->background; }
    inline QList<Flame*> *getFlames() { return this->flames; }
    inline QList<Tree*> *getTrees() { return this->trees; }
    inline QList<DarkEater*> *getDarkEaters() { return this->darkeaters; }
    inline QList<Model*> *getModels() { return this->models; }
    //inline int getSpeed() { return this->speed; }
    //inline void setSpeed(int speed) { this->speed = speed; }
    bool getDarkEaterBool() { return this->darkEaterBool; }
    void setDarkEaterBool(bool darkEaterBool) { this->darkEaterBool = darkEaterBool; }
    bool getIsPrincessBool() { return this->isPrincessBool; }
    void setIsPrincessBool(bool isPrincessBool){ this->isPrincessBool = isPrincessBool; }

    //public methods
    void createModel(QList<QChar>, int, int);
    void modelOrganisation();
    void createMushroom(int, int, bool);
    void createGameOver(int, int);
    void createPrincess(int, int);
    void createLabel(int, int, QString path);
    void createCompleted(int, int);

    //public attributes
    static int const modelSize = 50;
    static int const Height = 500;
    static int const Width = 1000;
    static int const NbModelVisible = 20;

private:
    //private attributes
    Mario * mario;
    Princess * princess;
    Blood *blood;
    Score *score;
    Shock *shock;
    Label *label;
    Time *time;
    SplashScreen *splashscreen;
    QList<Gold*> * golds;
    QList<Mushroom*> * mushrooms;
    QList<Brick*> * bricks;
    QList<Floor*> *floors;
    QList<Background*> *background;
    QList<Flame*> *flames;
    QList<Tree*> *trees;
    QList<DarkEater*> *darkeaters;
    QList<Model*> *models;

    QList<QChar> list1;
    QList<QChar> list2;
    QList<QChar> list3;
    QList<QChar> list4;
    QList<QChar> list5;
    QList<QChar> list6;
    int backgroundCount=0;
    int mapPosition = 7;
    //int speed = 4;
    bool darkEaterBool;
    bool isPrincessBool = false;
};

#endif // MODEL_H
