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
    inline void setIsGameOver(bool is) { this->isGameOver = is; }
    inline bool getIsGameOVer() { return this->isGameOver; }
    bool getMoveMap() { return this->moveMap; }
    inline std::tuple<> getAllObjects();
    inline ModelList *getModelList(){ return this->modelList; }
    inline qreal getOpacity() { return this->opacity; }
    inline void setOpacity(qreal opacity) { this->opacity = opacity; }
    inline int getXRelatif() { return this->xRelatif; }
    inline void setXRelatif(int x) { this->xRelatif = x; }

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
    bool gameStarted;
    int xRelatif;
    int yRelatif;
    int startJumpY;
    int iterBackground;
    int tempMove = 0;
    int marioSize;
    int tempDarkEater = 0;
    int princessTempo = 0;
    int tempGold = 0;
    int tempFlame = 0;
    int tempShock = 0;
    qreal opacity = 1;
    bool isLittle;
    bool isGameOver = false;
    bool moveMap = false;
    int showBloodCount = 0;
    int labelTime = 0;
    int timerId=0;

    //private methods
    void timerEvent(QTimerEvent *event);
};

#endif // GAMEBOARD_H
