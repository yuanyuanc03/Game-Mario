#include "player.h"


Player::Player(int x, int y)
{
    this->rect.translate(x, y);
    this->isDead = false;
    this->isMovingR = false;
    this->isMovingL = false;
    this->isJumping = false;
}

Player::~Player()
{

}

void Player::move(int x, int y)
{
    this->rect.moveTo(x, y);
}

void Player::moveDie(int x, int y)
{
    this->dieRect.moveTo(x, y);
}

bool Player::intersect(QRect rect)
{
    if(rect.intersects(this->rect))
        return true;
    else
        return false;
}
