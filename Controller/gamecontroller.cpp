#include "Model/modellist.h"
#include "Model/model.h"
#include "View/view.h"
#include "Model/gold.h"
#include "Model/shock.h"
#include "Model/flame.h"
#include "Model/darkeater.h"
#include "Model/label.h"
#include "Model/splashscreen.h"
#include "gamecontroller.h"

class ModelList;
class Model;
class View;

//current frame position of sprite images
int Gold::currentFrame = 0;
int Shock::currentFrame = 0;
int Flame::currentFrame = 0;
int DarkEater::currentFrame = 0;
//the moving range of each movement
int Model::speed = 4;

GameController::GameController(ModelList *model, View *view): QObject()
{
    this->modelList = model;
    this->view = view;
    this->view->setController(this);
    this->gameStarted = true;
    this->xRelatif = -100;
    this->yRelatif = 0;
    this->iterBackground = 0;
    this->timerId = this->startTimer(15);
}

GameController::~GameController()
{
    //kill timer
    this->killTimer(timerId);
}

//timeEvent which run each 15ms
void GameController::timerEvent(QTimerEvent *)
{
    this->modelList->modelOrganisation();
    this->splashScreen();
    this->movementMario();
    this->movementPrincess();
    this->movementLabel();
    this->goldAnimation();
    this->flameAnimation();
    this->shockAnimation();
    this->hurted();
    this->Princess();
    this->Label();
    this->GameOver();
    this->Completed();
    this->intersectPrincessMario();
    //repaint the screen
    this->view->repaint();
}

//stop game
void GameController::stopGame()
{
    this->gameStarted = false;
}

//start background music
void GameController::startBgMusic()
{
    for(int i =0; i < 2; i++)
    {
        this->getModelList()->getBackground()->at(i)->playBgMusic();
    }
}

//stop background music
void GameController::stopBgMusic()
{
    for(int i =0; i < 2; i++)
    {
        this->getModelList()->getBackground()->at(i)->getBgMusic()->stop();
    }
}

//pause background music
void GameController::pauseBgMusic()
{
    for(int i =0; i < 2; i++)
    {
        this->getModelList()->getBackground()->at(i)->getBgMusic()->pause();
    }
}

//when mario is dead, play death music
void GameController::marioDeath()
{
    this->stopBgMusic();
    this->getModelList()->getMario()->getDeathSound()->play();
}

//the move action of mario
void GameController::movementMario()
{
    int y = this->modelList->getMario()->getRect().y();

    if(this->modelList->getMario()->getIsLittle() && (this->modelList->getMario()->getGoldNumber() > this->modelList->getMario()->getGoldNumberWhenMushroom() + 30))
        this->modelList->getMario()->setIsLittle(false);

    if(this->getIsJumping())
    {
        if(this->getIsAttacking())
        {
            for(int i = 0; i < 7; ++i)
                this->xRelatif += 1;
        }
        else
        {
            for(int i = 0; i < 4; ++i)
                this->xRelatif += 1;
        }

        this->yRelatif = (-0.02 * (this->xRelatif * this->xRelatif) + 200);
        y = this->startJumpY - this->yRelatif;
        this->moveXMario(y);
        this->modelList->getMario()->setCurrentFrame(0);

        if(intersectTopMario(0))
        {
            this->xRelatif=0;
            this->yRelatif=0;
            this->startJumpY = this->modelList->getMario()->getRect().y();
            this->setIsJumping(false);
        }

        this->getModelList()->getMario()->getJumpSound()->play();
    }

    if(this->intersectBottomMario(0))
    {
        this->xRelatif = 0;
        this->yRelatif = 0;
        this->startJumpY = this->modelList->getMario()->getRect().y();
        this->setIsJumping(false);
        this->moveXMario(y);

        if(this->getIsAttacking())
        {
            if(this->modelList->getMario()->getIsLittle())
                this->modelList->getShock()->move(this->modelList->getMario()->getRect().x() - 60, this->modelList->getMario()->getRect().y() - 25);
            else
                this->modelList->getShock()->move(this->modelList->getMario()->getRect().x() - 50, this->modelList->getMario()->getRect().y());

            this->modelList->getShock()->setShow(true);
            Shock::currentFrame = 0;
            this->setIsAttacking(false);
        }

        if(this->getIsMovingR() && this->tempMove == 1)
        {
            for(int i = 0; i < 57; i++)
                this->modelList->getMario()->setCurrentFrame(this->modelList->getMario()->getCurrentFrame() + 1);
            if (this->modelList->getMario()->getCurrentFrame() >= 1190 )
                this->modelList->getMario()->setCurrentFrame(0);
            this->tempMove = 0;
        }

        else if(this->getIsMovingR())
            tempMove++;

        else if(this->getIsMovingL() && tempMove == 1)
        {
            for(int i = 0; i < 57; i++)
                this->modelList->getMario()->setCurrentFrame(this->modelList->getMario()->getCurrentFrame() - 1);
            if (this->modelList->getMario()->getCurrentFrame() <= 0 )
                this->modelList->getMario()->setCurrentFrame(1191);
            this->tempMove = 0;
        }

        else if(this->getIsMovingL())
            this->tempMove++;

        else
            this->modelList->getMario()->setCurrentFrame(0);
    }

    if((!this->intersectBottomMario(0) && !this->getIsJumping()))
    {
        this->yRelatif = (-0.02*(this->xRelatif*this->xRelatif));
        for(int i = 0; i < 4; ++i)
            xRelatif += 1;

        if(this->getIsAttacking())
        {
            for(int i = 0; i < 7; ++i)
                xRelatif += 1;
        }

        y = this->startJumpY - this->yRelatif;
        this->moveXMario(y);
        this->modelList->getMario()->setCurrentFrame(0);
    }
}

//the move action of princess
void GameController::movementPrincess()
{
    if(this->modelList->getIsPrincessBool())
    {
        if(this->modelList->getPrincess()->getIsMovingL())
        {
            if(this->princessTempo == 30)
            {
                this->modelList->getPrincess()->setCurrentFrame(this->modelList->getPrincess()->getCurrentFrame() + 50);
                if (this->modelList->getPrincess()->getCurrentFrame() >= 200 )
                    this->modelList->getPrincess()->setCurrentFrame(0);
                this->princessTempo = 0;
            }
            else
                this->princessTempo++;
        }
    }
}

//the position of label
void GameController::movementLabel()
{
    if(this->modelList->getLabel()->getShow())
        this->modelList->getLabel()->move(this->modelList->getMario()->getRect().x(), this->modelList->getMario()->getRect().y() - 100);
}

//the move action of mushroom
void GameController::movementMushroom(int i)
{
    int x = this->modelList->getMushrooms()->at(i)->getRect().x();
    //init moveCount = 37
    if(this->modelList->getMushrooms()->at(i)->getMoveCount() > 0)
    {
        this->modelList->getMushrooms()->at(i)->setmoveCount(this->modelList->getMushrooms()->at(i)->getMoveCount() - 1);
        if(this->moveMap)
        {
            if(this->modelList->getMushrooms()->at(i)->getUp())
                this->modelList->getMushrooms()->at(i)->move(x - Model::speed, this->modelList->getMushrooms()->at(i)->getRect().y() - 1);
            else
                this->modelList->getMushrooms()->at(i)->move(x - Model::speed, this->modelList->getMushrooms()->at(i)->getRect().y() + 1);
        }
        else
        {
            if(this->modelList->getMushrooms()->at(i)->getUp())
                this->modelList->getMushrooms()->at(i)->move(x, this->modelList->getMushrooms()->at(i)->getRect().y() - 1);
            else
                this->modelList->getMushrooms()->at(i)->move(x, this->modelList->getMushrooms()->at(i)->getRect().y() + 1);
        }
    }

    else
        this->moveModel(x, this->modelList->getMushrooms()->at(i));
}

//the move action of tree
void GameController::movementTree(int i)
{
    if(this->modelList->getTrees()->at(i)->getIsMovingL())
    {
        if(this->modelList->getTrees()->at(i)->getMoveCount() > 0)
        {
            this->modelList->getTrees()->at(i)->setmoveCount(this->modelList->getTrees()->at(i)->getMoveCount() - 2);
            this->modelList->getTrees()->at(i)->move(this->modelList->getTrees()->at(i)->getRect().x(), this->modelList->getTrees()->at(i)->getRect().y() - 2);
        }

        else if(this->modelList->getTrees()->at(i)->getMoveCount() > - 120)
        {
            this->modelList->getTrees()->at(i)->setmoveCount(this->modelList->getTrees()->at(i)->getMoveCount() - 2);
            this->modelList->getTrees()->at(i)->move(this->modelList->getTrees()->at(i)->getRect().x(), this->modelList->getTrees()->at(i)->getRect().y() + 2);
        }

        else
            this->modelList->getTrees()->at(i)->setmoveCount(120);
    }
}

//the move acction of model
void GameController::moveModel(int x, Model *model)
{
    int speed;
    if(moveMap)
        speed = Model::speed;
    else
        speed = 0;

    if(this->intersectBottomModel(model))
    {
        if(model->getMoveX())
        {
            model->move(x - speed + 2, model->getRect().y());
            if(this->intersectRightModel(model))
                model->setMoveX(false);
        }

        else if(!model->getMoveX())
        {
            model->move(x - speed - 2, model->getRect().y());
            if( this->intersectLeftModel(model) || model->getRect().x() < 3)
                model->setMoveX(true);
        }

        model->setYR(0);
        model->setXR(0);
        model->setStartY(model->getRect().y());
    }

    else
    {
        model->setYR(-0.02*(model->getXR()*model->getXR()));
        model->setXR(model->getXR()+3);
        int y = model->getStartY() - model->getYR();

        if(model->getMoveX())
        {
            model->move(x-speed+2, y);
            if(this->intersectRightModel(model))
                model->setMoveX(false);
        }
        else if(!model->getMoveX())
        {
            model->move(x-speed-2,y);
            if(this->intersectLeftModel(model))
                model->setMoveX(true);
        }
    }
}

//move mario in the x axis
void GameController::moveXMario(int y)
{
    int x = this->modelList->getMario()->getRect().x();

    if(!this->intersectLeftMario(0) && this->modelList->getMario()->getRect().x()>=2 && this->getIsMovingL() )
        x -= Model::speed;

    else if( !this->intersectRightMario(0) && this->modelList->getMario()->getRect().x()<=350  && this->getIsMovingR())
        x += Model::speed;

    if( !this->intersectRightMario(0) && this->modelList->getMario()->getRect().x()>=350  && this->getIsMovingR() )
        this->moveMap=true;
    else
        this->moveMap=false;

    this->modelList->getMario()->move(x, y);
}

//collision of princess and mario
void GameController::intersectPrincessMario()
{
    if(this->modelList->getIsPrincessBool())
    {
        if(this->modelList->getMario()->intersect(this->modelList->getPrincess()->getRect()))
        {
            this->modelList->getLabel()->setShow(true);
            this->labelTime = 0;
            if(this->modelList->getLabel()->getType() != LabelType::LOVE)
            {
                this->modelList->createLabel(this->modelList->getMario()->getRect().x(), this->modelList->getMario()->getRect().y() - 100, ":/files/images/speech.png");
                this->modelList->getLabel()->setType(LabelType::LOVE);
            }
        }
    }
}

//when mario intersect with floor or brick over the mario
bool GameController::intersectTopMario(int i)
{
    if(i < this->modelList->getFloors()->size() || i < this->modelList->getBricks()->size())
    {
        if(!this->modelList->getFloors()->empty() && i < this->modelList->getFloors()->size())
        {
            if(this->modelList->getMario()->intersectTop(this->modelList->getFloors()->at(i)->getRect()))
                return true;
        }
        if(!this->modelList->getBricks()->empty() && i < this->modelList->getBricks()->size())
        {
            if(this->modelList->getMario()->intersectTop(this->modelList->getBricks()->at(i)->getRect()))
            {
                //the maximum capacity of a brick = 2
                if(this->modelList->getBricks()->at(i)->getCapacity())
                {
                    if(this->modelList->getBricks()->at(i)->getCapacity() == 2)
                    {
                        this->modelList->createMushroom(this->modelList->getBricks()->at(i)->getRect().x(), this->modelList->getBricks()->at(i)->getRect().y(), true);
                        this->modelList->getBricks()->at(i)->setCapacity(1);
                    }
                }
                else
                {
                    this->modelList->getBricks()->at(i)->setDestroyed(true);   
                    this->getModelList()->getBricks()->at(i)->getBrickBreak()->play();
                }

                return true;
            }
        }

        this->intersectTopMario(i+1);
    }

    else
        return false;
}

//when mario intersect with floor, brick, tree or darkeater under the mario
bool GameController::intersectBottomMario(int i)
{
    if(i < this->modelList->getFloors()->size()|| i < this->modelList->getBricks()->size()
            || i < this->modelList->getTrees()->size()|| i < this->modelList->getDarkEaters()->size())
    {
        if(!this->modelList->getFloors()->empty() && i < this->modelList->getFloors()->size())
        {
            if(this->modelList->getMario()->intersectBottom(this->modelList->getFloors()->at(i)->getRect()))
                return true;
        }

        if(!this->modelList->getBricks()->empty() && i < this->modelList->getBricks()->size())
        {
            if(this->modelList->getMario()->intersectBottom(this->modelList->getBricks()->at(i)->getRect()))
            {
                if(this->getIsAttacking())
                {
                    if(this->modelList->getBricks()->at(i)->getCapacity())
                    {
                        if(this->modelList->getBricks()->at(i)->getCapacity() == 2)
                        {
                            this->modelList->createMushroom(this->modelList->getBricks()->at(i)->getRect().x(), this->modelList->getBricks()->at(i)->getRect().y(), false);
                            this->modelList->getBricks()->at(i)->setCapacity(1);
                        }
                    }
                    else
                        this->modelList->getBricks()->at(i)->setDestroyed(true);
                }
                return true;
            }
        }

        if(!this->modelList->getTrees()->empty() && i < this->modelList->getTrees()->size())
        {
            if(this->modelList->getMario()->intersectBottom(this->modelList->getTrees()->at(i)->getRect()))
            {
                this->attackTree(i);
                return true;
            }
        }

        if(!this->modelList->getDarkEaters()->empty() && i < this->modelList->getDarkEaters()->size())
        {
            if(this->modelList->getMario()->intersectBottom(this->modelList->getDarkEaters()->at(i)->getRect()))
            {
                intersectYDarkEaterMario(i);
                return true;
            }
        }

        this->intersectBottomMario(i+1);
    }

    else
        return false;
}

//when mario intersect with floor, brick, tree or darkeater which is left of the mario
bool GameController::intersectLeftMario(int i)
{
    if(i < this->modelList->getFloors()->size()|| i < this->modelList->getBricks()->size()
            || i < this->modelList->getTrees()->size() || i < this->modelList->getDarkEaters()->size())
    {
        if(!this->modelList->getFloors()->empty() && i < this->modelList->getFloors()->size())
        {
            if(this->modelList->getMario()->intersectLeft(this->modelList->getFloors()->at(i)->getRect()))
                return true;
        }

        if(!this->modelList->getBricks()->empty() && i < this->modelList->getBricks()->size())
        {
            if(this->modelList->getMario()->intersectLeft(this->modelList->getBricks()->at(i)->getRect()))
                return true;
        }

        if(!this->modelList->getTrees()->empty() && i < this->modelList->getTrees()->size())
        {
            if(this->modelList->getMario()->intersectLeft(this->modelList->getTrees()->at(i)->getRect()))
            {
                this->intersectTreeMario(i);
                return true;
            }
        }

        if(!this->modelList->getDarkEaters()->empty() && i < this->modelList->getDarkEaters()->size())
        {
            if(this->modelList->getMario()->intersectLeft(this->modelList->getDarkEaters()->at(i)->getRect()))
               return true;
        }

        intersectLeftMario(i+1);
    }

    else
        return false;
}

//when mario intersect with floor, brick, tree or darkeater which is right of the mario
bool GameController::intersectRightMario(int i)
{
    if(i < this->modelList->getFloors()->size() || i < this->modelList->getBricks()->size()
            || i < this->modelList->getTrees()->size() || i < this->modelList->getDarkEaters()->size())
    {
        if(!this->modelList->getFloors()->empty() && i < this->modelList->getFloors()->size())
        {
            if(this->modelList->getMario()->intersectRight(this->modelList->getFloors()->at(i)->getRect()))
                return true;
        }

        if(!this->modelList->getBricks()->empty() && i < this->modelList->getBricks()->size())
        {
            if(this->modelList->getMario()->intersectRight(this->modelList->getBricks()->at(i)->getRect()))
                return true;
        }

        if(!this->modelList->getTrees()->empty() && i < this->modelList->getTrees()->size())
        {
            if(this->modelList->getMario()->intersectRight(this->modelList->getTrees()->at(i)->getRect()))
            {
                this->intersectTreeMario(i);
                return true;
            }
        }

        if(!this->modelList->getDarkEaters()->empty() && i < this->modelList->getDarkEaters()->size())
        {
            if(this->modelList->getMario()->intersectRight(this->modelList->getDarkEaters()->at(i)->getRect()))
                return true;
        }

        this->intersectRightMario(i+1);
    }

    else
        return false;
}

//collision of gold and mario
void GameController::intersectGoldMario(int i)
{
    if(this->modelList->getMario()->intersect(this->modelList->getGolds()->at(i)->getRect()))
    {
        this->modelList->getGolds()->at(i)->setDestroyed(true);
        this->modelList->getMario()->setGoldNumber(this->modelList->getMario()->getGoldNumber() + 1);

        this->getModelList()->getGolds()->at(i)->getGold()->play();
    }
}

//collision of flame and mario
void GameController::intersectFlameMario(int i)
{
    if(this->modelList->getMario()->intersect(this->modelList->getFlames()->at(i)->getRect()) && !this->modelList->getMario()->getUntouchable())
    {
        this->showBloodCount = 0;
        this->modelList->getMario()->setIsHurted(true);
        this->modelList->getFlames()->at(i)->getFire()->play();
        if(this->getModelList()->getTime()->getTime() == -1 || this->getModelList()->getMario()->getLife() == -1)
            this->modelList->getFlames()->at(i)->getFire()->stop();
    }
}

//collision of darkeater and mario in X axis
void GameController::intersectXDarkEaterMario(int i)
{
    if(!this->modelList->getMario()->getUntouchable() && !getIsAttacking()
            && !this->modelList->getDarkEaters()->at(i)->isDestroyed()
            && (this->modelList->getDarkEaters()->at(i)->intersectRight(this->modelList->getMario()->getRect())
            || this->modelList->getDarkEaters()->at(i)->intersectLeft(this->modelList->getMario()->getRect())))
    {
        if(!this->modelList->getMario()->getIsMovingR() && !this->modelList->getMario()->getIsMovingL())
            this->modelList->getDarkEaters()->at(i)->setMoveX(!this->modelList->getDarkEaters()->at(i)->getMoveX());

        if(this->modelList->getMario()->getIsMovingR() && !this->modelList->getDarkEaters()->at(i)->getMoveX())
            this->modelList->getDarkEaters()->at(i)->setMoveX(!this->modelList->getDarkEaters()->at(i)->getMoveX());

        else if(this->modelList->getMario()->getIsMovingL() && this->modelList->getDarkEaters()->at(i)->getMoveX())
            this->modelList->getDarkEaters()->at(i)->setMoveX(!this->modelList->getDarkEaters()->at(i)->getMoveX());

        this->showBloodCount = 0;
        this->modelList->getMario()->setIsHurted(true);

        this->getModelList()->getDarkEaters()->at(i)->getBoom()->play();
        if(this->getModelList()->getTime()->getTime() == -1 || this->getModelList()->getMario()->getLife() == -1)
            this->getModelList()->getDarkEaters()->at(i)->getBoom()->stop();
    }
}

//collision of darkeater and mario in Y axis
void GameController::intersectYDarkEaterMario(int i)
{
    if(!this->modelList->getMario()->getIsMovingL() && !this->modelList->getMario()->getIsMovingR() && !this->modelList->getDarkEaters()->at(i)->isDestroyed())
        this->modelList->getMario()->move(this->modelList->getDarkEaters()->at(i)->getRect().x(), this->modelList->getMario()->getRect().y());

    if(!this->modelList->getDarkEaters()->at(i)->isDestroyed() && getIsAttacking())
    {
        this->modelList->getShock()->move(this->modelList->getDarkEaters()->at(i)->getRect().x() - 50, this->modelList->getDarkEaters()->at(i)->getRect().y() - 50);
        this->modelList->getShock()->setShow(true);
        Shock::currentFrame = 0;
        this->modelList->getDarkEaters()->at(i)->setModelWithPath(QString(":/files/images/dark_eater_die.png"));
        this->modelList->getDarkEaters()->at(i)->setDestroyed(true);

        this->getModelList()->getDarkEaters()->at(i)->getBoom()->play();
        if(this->getModelList()->getTime()->getTime() == -1 || this->getModelList()->getMario()->getLife() == -1)
            this->getModelList()->getDarkEaters()->at(i)->getBoom()->stop();
    }
}

//when eat a mushroom, we can get little and speed up
void GameController::intersectMushroomMario(int i)
{
    if(this->modelList->getMario()->intersect(this->modelList->getMushrooms()->at(i)->getRect()))
    {
        this->modelList->getMushrooms()->at(i)->setDestroyed(true);
        this->modelList->getMario()->setIsLittle(true);
        this->modelList->getMario()->setGoldNumberWhenMushroom(this->modelList->getMario()->getGoldNumber());
        //this->modelList->getMario()->setLife(this->modelList->getMario()->getLife() + 1);
        Model::speed = 6;

        this->getModelList()->getMushrooms()->at(i)->getMushroomEat()->play();
    }
}

//collision of tree and mario
void GameController::intersectTreeMario(int i)
{
    if(!this->modelList->getMario()->getUntouchable() && !this->modelList->getTrees()->at(i)->getIsDead())
    {
        this->showBloodCount = 0;
        this->modelList->getMario()->setIsHurted(true);

        this->getModelList()->getTrees()->at(i)->getTreeSound()->play();
        if(this->getModelList()->getTime()->getTime() == -1 || this->getModelList()->getMario()->getLife() == -1)
            this->getModelList()->getTrees()->at(i)->getTreeSound()->stop();
    }
}

//when model intersect with floor or brick under the model
bool GameController::intersectBottomModel(Model * m)
{
    for(int i = 0; i < this->modelList->getFloors()->size(); i++)
    {
        if(m->intersectBottom(this->modelList->getFloors()->at(i)->getRect()))
            return true;
    }

    for(int i = 0; i < this->modelList->getBricks()->size(); i++)
    {
        if(m->intersectBottom(this->modelList->getBricks()->at(i)->getRect()))
            return true;
    }
    return false;
}

//when model intersect with floor or brick which is left of the mario
bool GameController::intersectLeftModel(Model * m)
{
    for(int i = 0; i < this->modelList->getFloors()->size(); i++)
    {
        if(m->intersectLeft(this->modelList->getFloors()->at(i)->getRect()))
            return true;
    }
    for(int i = 0; i < this->modelList->getBricks()->size(); i++)
    {
        if(m->intersectLeft(this->modelList->getBricks()->at(i)->getRect()))
            return true;
    }
    return false;
}

//when model intersect with floor or brick which is right of the mario
bool GameController::intersectRightModel(Model * m)
{
    for(int i = 0; i < this->modelList->getFloors()->size(); i++)
    {
        if(m->intersectRight(this->modelList->getFloors()->at(i)->getRect()))
            return true;
    }

    for(int i = 0; i < this->modelList->getBricks()->size(); i++)
    {
        if(m->intersectRight(this->modelList->getBricks()->at(i)->getRect()))
            return true;
    }

    return false;
}

//when mario is attacking tree, show shock
void GameController::attackTree(int i)
{
    if(!this->modelList->getTrees()->at(i)->getIsDead() && this->modelList->getMario()->getIsAttacking())
    {
        this->modelList->getTrees()->at(i)->setDead(true);
        this->modelList->getTrees()->at(i)->setIsMovingL(false);
        this->modelList->getShock()->move(this->modelList->getTrees()->at(i)->getRect().x() - 50, this->modelList->getTrees()->at(i)->getRect().y() - 50);
        this->modelList->getShock()->setShow(true);
        Shock::currentFrame = 0;
    }
}

//show gold
void GameController::goldAnimation()
{
    if(tempGold == 20)
    {
        Gold::currentFrame += 40;
        if (Gold::currentFrame >= 120)
            Gold::currentFrame = 0;
        tempGold = 0;
    }
    else
        tempGold++;
}

//show shock
void GameController::shockAnimation()
{
    if(tempShock == 3)
    {
        Shock::currentFrame += 66;
        if (Shock::currentFrame >= 200)
        {
            Shock::currentFrame = 0;
            this->modelList->getShock()->setShow(false);
        }
        tempShock = 0;
    }
    else
        tempShock++;
}

//show flame
void GameController::flameAnimation()
{
    if(tempFlame == 10)
    {
        Flame::currentFrame += 58;
        if (Flame::currentFrame >= 520)
            Flame::currentFrame = 3;
        tempFlame = 0;
    }
    else
        tempFlame++;

    for(int i = 0; i < this->modelList->getFlames()->size(); i++)
    {
        int x = this->modelList->getFlames()->at(i)->getRect().x();
        this->moveModel(x, this->modelList->getFlames()->at(i));
        this->modelList->getFlames()->at(i)->setSrcRect(QRect(Flame::currentFrame, 0, this->modelList->getFlames()->at(i)->getRect().width(), this->modelList->getFlames()->at(i)->getRect().height()));
        view->update(this->modelList->getFlames()->at(i)->getSrcRect());
    }
}

//show darkeater
void GameController::darkeaterAnimation(int i)
{
    if(tempDarkEater == 15)
    {
        DarkEater::currentFrame += 52;
        if (DarkEater::currentFrame >= 156)
            DarkEater::currentFrame = 1;
        tempDarkEater = 0;
    }
    else
        tempDarkEater++;

    int x = this->modelList->getDarkEaters()->at(i)->getRect().x();
    if(!this->modelList->getDarkEaters()->at(i)->isDestroyed())
    {
        this->moveModel(x, this->modelList->getDarkEaters()->at(i));
        this->intersectXDarkEaterMario(i);
        if(this->modelList->getDarkEaters()->at(i)->getMoveX())
            this->modelList->getDarkEaters()->at(i)->setModelWithPath(QString(":/files/images/dark_eater_right.png"));
        else
            this->modelList->getDarkEaters()->at(i)->setModelWithPath(QString(":/files/images/dark_eater.png"));
        this->modelList->getDarkEaters()->at(i)->setSrcRect(QRect(DarkEater::currentFrame, 0, this->modelList->getDarkEaters()->at(i)->getRect().width(), this->modelList->getDarkEaters()->at(i)->getRect().height()));
    }
    else
        this->modelList->getDarkEaters()->at(i)->setSrcRect(QRect(0, 0, this->modelList->getDarkEaters()->at(i)->getRect().width(), this->modelList->getDarkEaters()->at(i)->getRect().height()));
}

//move bg when iterBg == 2
void GameController::backgroundAnimation(int i)
{
    if(this->iterBackground == 2)
    {
        this->modelList->getBackground()->at(i)->moveBg();
        this->iterBackground=0;
    }
    else
    {
        this->iterBackground++;
    }
}

//when mario get hurted
void GameController::hurted()
{
    if(this->modelList->getMario()->getIsHurted())
    {
        this->modelList->getMario()->setUntouchable(true);

        if(this->showBloodCount >= 15)
        {
            this->modelList->getBlood()->setStopBlood(true);
            this->showBloodCount = 0;
        }
        else
            this->showBloodCount++;

        this->modelList->getBlood()->move(this->modelList->getMario()->getRect().x() - 20, this->modelList->getMario()->getRect().y() - 5);

        if(this->modelList->getMario()->getInvicible() == 0)
        {
            this->modelList->getLabel()->setShow(true);
            this->labelTime = 0;
            if(this->modelList->getLabel()->getType() != LabelType::HURT)
            {
                this->modelList->createLabel(this->modelList->getMario()->getRect().x(), this->modelList->getMario()->getRect().y() - 100, ":/files/images/speech_hell.png");
                this->modelList->getLabel()->setType(LabelType::HURT);
            }
            this->modelList->getMario()->setLife(this->modelList->getMario()->getLife() - 1);
        }

        if(this->modelList->getMario()->getInvicible() > 100)
        {
            this->modelList->getMario()->setUntouchable(false);
            this->modelList->getMario()->setIsHurted(false);
            this->modelList->getBlood()->setStopBlood(false);
            this->modelList->getMario()->setInvicible(0);
            this->modelList->getLabel()->setShow(false);
        }
        else
            this->modelList->getMario()->setInvicible(this->modelList->getMario()->getInvicible() + 1);
    }
}

//show GO
void GameController::splashScreen()
{
    if(this->modelList->getSplashScreen()->getType() == SplashScreenType::GO)
    {
        int x= this->modelList->getSplashScreen()->getRect().x();
        int y= this->modelList->getSplashScreen()->getRect().y();
        y--;
        if(this->modelList->getSplashScreen()->getRect().bottom() > 0 && this->modelList->getSplashScreen()->getIsSplashScreen())
            this->modelList->getSplashScreen()->move(x, y);
        else
            this->modelList->getSplashScreen()->setIsSplashScreen(false);
    }
}

//when life < 0 || time our || mario drop, game over
bool GameController::GameOver()
{
    if(this->modelList->getMario()->getLife() < 0 || this->modelList->getMario()->getRect().y() > 500
            || this->modelList->getTime()->getTime() <= 0)
    {
        this->modelList->getLabel()->setShow(true);
        this->labelTime = 0;
        if(this->modelList->getSplashScreen()->getType() != SplashScreenType::GAME_OVER)
        {
            this->modelList->createGameOver(220, 100);
            this->modelList->getSplashScreen()->setType(SplashScreenType::GAME_OVER);
        }
        this->modelList->getSplashScreen()->setIsSplashScreen(true);

        return true;
    }
    else
        return false;
}

//when goldnumber > 150, complete the game
bool GameController::Completed()
{
    if(this->modelList->getMario()->getGoldNumber() >= 150)
    {
        if(this->modelList->getSplashScreen()->getType() != SplashScreenType::COMPLETED)
        {
            this->modelList->createCompleted(360, 120);
            this->modelList->getSplashScreen()->setType(SplashScreenType::COMPLETED);
        }
        this->modelList->getSplashScreen()->setIsSplashScreen(true);
        return true;
    }
    else
        return false;
}

//show princess when goldnumber > 100
void GameController::Princess()
{
    if(this->modelList->getMario()->getGoldNumber() > 100 && !this->modelList->getIsPrincessBool())
    {
        this->modelList->createPrincess(this->modelList->getMario()->getRect().x() + 200, 340);
        this->modelList->setIsPrincessBool(true);
    }
}

//show label
void GameController::Label()
{
    if(this->modelList->getMario()->getGoldNumber() == 1)
    {
        if(this->modelList->getLabel()->getType() != LabelType::GOLD)
        {
            this->modelList->createLabel(this->modelList->getMario()->getRect().x(), this->modelList->getMario()->getRect().y() - 100, ":/files/images/speech_gold.png");
            this->modelList->getLabel()->setType(LabelType::GOLD);
        }
        this->labelTime = 0;
        this->modelList->getLabel()->setShow(true);
    }

    if(this->modelList->getLabel()->getType() == LabelType::GOLD)
    {
        if(this->labelTime > 100)
        {
            this->modelList->getLabel()->setShow(false);
            this->modelList->getLabel()->setType(LabelType::NONE);
        }
        else
            this->labelTime++;
    }
    else if(this->modelList->getLabel()->getType() == LabelType::FUCK || this->modelList->getLabel()->getType() == LabelType::LOVE)
    {
        if(this->labelTime > 30)
        {
            this->modelList->getLabel()->setShow(false);
            this->modelList->getLabel()->setType(LabelType::NONE);
        }
        else
            this->labelTime++;
    }
}
