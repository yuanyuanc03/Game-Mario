#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QObject>
#include "Model/modellist.h"
#include "View/view.h"

class ModelList;
class View;

class GameController : public QObject
{
    Q_OBJECT
public:
    //constructor
    GameController(ModelList * modelList, View * view);
    ~GameController();

    //setters and getters
    inline bool getIsMovingR() { return this->getModelList()->getMario()->getIsMovingR(); }
    inline bool getIsMovingL() { return this->getModelList()->getMario()->getIsMovingL(); }
    inline bool getIsJumping() { return this->getModelList()->getMario()->getIsJumping(); }
    inline bool getIsAttacking() { return this->getModelList()->getMario()->getIsAttacking(); }
    inline void setIsMovingR(bool is) { this->getModelList()->getMario()->setIsMovingR(is); }
    inline void setIsMovingL(bool is) { this->getModelList()->getMario()->setIsMovingL(is); }
    inline void setIsJumping(bool is) { this->getModelList()->getMario()->setIsJumping(is); }
    inline void setIsAttacking(bool is) { this->getModelList()->getMario()->setIsAttacking(is); }
    inline ModelList *getModelList(){ return this->modelList; }
    inline int getXRelatif() { return this->xRelatif; }
    inline void setXRelatif(int x) { this->xRelatif = x; }
    inline void setTimerId(int id) { this->timerId = id; }
    inline int getTimerId() { return this->timerId; }
    bool getMoveMap() { return this->moveMap; }

    //public methods
    void Princess();
    void fantom();
    void Label();
    void splashScreen();
    void stopGame();
    void startBgMusic();
    void stopBgMusic();
    void pauseBgMusic();
    void marioDeath();
    bool GameOver();
    bool Completed();
    void hurted();
    void goldAnimation();
    void shockAnimation();
    void flameAnimation();
    void darkeaterAnimation(int);
    void backgroundAnimation(int);
    void movementMario();
    void moveXMario(int);
    void movementBackground();
    void movementMushroom(int);
    void movementPrincess();
    void moveModel(int, Model *);
    void movementTree(int);
    void movementLabel();
    void movementMap(int);
    void attackTree(int i);
    bool intersectBottomMario(int);
    bool intersectTopMario(int);
    bool intersectRightMario(int);
    bool intersectLeftMario(int);
    void intersectGoldMario(int);
    void intersectMushroomMario(int);
    void intersectYDarkEaterMario(int);
    void intersectXDarkEaterMario(int);
    void intersectFlameMario(int);
    bool intersectBottomModel(Model *);
    bool intersectRightModel(Model *);
    bool intersectLeftModel(Model *);
    void intersectTreeMario(int i);
    void intersectPrincessMario();

private:
    //private attributes
    ModelList *modelList;
    View *view;
    bool gameStarted; //if game is started
    int xRelatif; //x relatif position
    int yRelatif; //y relatif position
    int startJumpY; //mario start jump Y position
    int iterBackground; //init iterBackground = 2
    int tempMove = 0; //movement interval time
    int tempDarkEater = 0; //darkeater movement interval time
    int tempGold = 0; //fold movement interval time
    int tempFlame = 0; //flame movement interval time
    int tempShock = 0; //shock movement interval time
    int princessTempo = 0; //princess movement interval time
    int showBloodCount = 0; //show blood time
    int labelTime = 0; //show label time
    int timerId = 0; //timer id
    bool moveMap = false; //move map or not

    //private methods
    void timerEvent(QTimerEvent *event);
};

#endif // GAMEBOARD_H
