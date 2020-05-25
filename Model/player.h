#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include "paint.h"

class Player
{
public:
    //constructor and destructor
    Player(int, int);
    ~Player();

    //setters and getters
    inline QPixmap getMoveRPlayer() { return this->moveR_player; }
    inline QPixmap getMoveLPlayer() { return this->moveL_Player; }
    inline QPixmap getStopPlayer() { return this->stop_player; }
    inline QPixmap getJumpPlayer() { return this->jump_player; }
    inline void setMoveRPlayer(QString path) { this->moveR_player.load(path); }
    inline void setMoveLPlayer(QString path) { this->moveL_Player.load(path); }
    inline void setStopPlayer(QString path) { this->stop_player.load(path); }
    inline void setJumpPlayer(QString path) { this->jump_player.load(path); }
    inline bool getIsMovingR() { return this->isMovingR; }
    inline bool getIsMovingL() { return this->isMovingL; }
    inline bool getIsJumping() { return this->isJumping; }
    inline bool getIsAttacking() { return this->isAttacking; }
    inline bool getIsDead() { return this->isDead; }
    inline void setIsMovingR(bool isMovingR) { this->isMovingR = isMovingR; }
    inline void setIsMovingL(bool isMovingL) { this->isMovingL = isMovingL; }
    inline void setIsJumping(bool isJumping) { this->isJumping = isJumping; }
    inline void setIsAttacking(bool isAttacking) { this->isAttacking = isAttacking; }
    inline void setDead(bool isDead) { this->isDead = isDead; }
    inline void setSrcRect(QRect srcRect) { this->srcRect = srcRect; }
    inline void setRect(QRect rect) { this->rect = rect; }
    inline void setDieRect(QRect dieRect) { this->dieRect = dieRect; }
    inline QRect getSrcRect() { return srcRect; }
    inline QRect getRect() { return rect; }
    inline QRect getDieRect() { return dieRect; }
    inline int getLife() { return life; }
    inline int getInvicible() { return invicible; }
    inline bool getUntouchable() { return this->unTouchable; }
    inline int getCurrentFrame() { return this->currentFrame; }
    inline void setLife(int life) { this->life = life; }
    inline void setInvicible(int invicible) { this->invicible = invicible; }
    inline void setUntouchable(bool touch) { this->unTouchable = touch; }
    inline void setCurrentFrame(int currentFrame) { this->currentFrame = currentFrame; }

    //public methods
    void move(int, int);
    void moveDie(int, int);
    bool intersect(QRect);
    void accept(Paint *paint){ paint->drawPlayer(this); }

protected:
    //protected attributes
    QPixmap moveR_player;
    QPixmap moveL_Player;
    QPixmap stop_player;
    QPixmap jump_player;
    bool isMovingR;
    bool isMovingL;
    bool isJumping;
    bool isAttacking = false;
    bool isDead = false;
    QRect rect;
    QRect dieRect;
    QRect srcRect;
    int currentFrame = 0;

private:
    //private attributes
    bool unTouchable = false;
    int life = 5;
    int invicible = 0;
};

#endif // PLAYER_H
