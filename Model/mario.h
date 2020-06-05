#ifndef MARIO_H
#define MARIO_H

#include <QMediaPlayer>
#include "player.h"

class Mario: public Player
{
public:
    //constructor and destructor
    Mario(int, int);

    //setters and getters
    int getGoldNumber() { return this->goldNumber; }
    void setGoldNumber(int goldNumber) { this->goldNumber = goldNumber; }
    bool getIsLittle() { return this->isLittle; }
    void setIsLittle(bool little) { this->isLittle = little; }
    inline bool getIsHurted() { return this->isHurted; }
    inline void setIsHurted(bool hurt) { this->isHurted = hurt; }
    int getGoldNumberWhenMushroom() { return this->goldNumberWhenMushroom; }
    void setGoldNumberWhenMushroom(int goldNumber) { this->goldNumberWhenMushroom = goldNumber; }
    QMediaPlayer* getDeathSound() { return this->deathsound; }
    void setDeathSound(QMediaPlayer* deathsound) { this->deathsound = deathsound; }
    QMediaPlayer* getJumpSound() { return this->jumpsound; }
    void setJumpSound(QMediaPlayer* jumpsound) { this->jumpsound = jumpsound; }

    //public methods
    bool intersectTop(QRect);
    bool intersectBottom(QRect);
    bool intersectRight(QRect);
    bool intersectLeft(QRect);

private:
    //private attributes
    int goldNumber; //gold number
    int goldNumberWhenMushroom; //when mario eats a mushroom, save the current gold number
    bool isLittle = false; //mario is little or not
    bool isHurted = false; //mario is hurted or not
    //bool hurt = false;
    QMediaPlayer * deathsound;
    QMediaPlayer * jumpsound;
};

#endif // MARIO_H
