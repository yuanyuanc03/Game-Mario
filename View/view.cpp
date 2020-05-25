#include "view.h"
#include <QPainter>
#include <iostream>
#include <QApplication>
#include <QDebug>
#include <QRect>
#include <tuple>
#include <QTimer>
#include <QObject>
#include "Model/modellist.h"
#include "Model/paint.h"


View::View(QWidget *parent): QWidget(parent)
{

}

View::~View()
{

}

void View::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    Paint *paint = new Paint(&painter);

    for(int i = this->controller->getModelList()->getModels()->indexOf(this->controller->getModelList()->getModels()->first()); i<this->controller->getModelList()->getModels()->size(); i++)
    {
        if(this->controller->getMoveMap())
        {
            this->controller->getModelList()->getModels()->at(i)->moveLModel();
        }
    }

    for(int i = this->controller->getModelList()->getBackground()->indexOf(this->controller->getModelList()->getBackground()->first()); i<this->controller->getModelList()->getBackground()->size(); i++)
    {
        if(this->controller->getMoveMap())
            this->controller->backgroundAnimation(i);
        this->controller->getModelList()->getBackground()->at(i)->accept(paint);
    }

    for(int i = 0; i<this->controller->getModelList()->getMushrooms()->size(); i++)
    {
        this->controller->intersectMushroomMario(i);
        this->controller->movementMushroom(i);
        this->controller->getModelList()->getMushrooms()->at(i)->accept(paint);
    }

    for(int i = 0; i<this->controller->getModelList()->getTrees()->size(); i++)
    {
        if(this->controller->getMoveMap())
            this->controller->getModelList()->getTrees()->at(i)->move(this->controller->getModelList()->getTrees()->at(i)->getRect().x() - Brick::speed, this->controller->getModelList()->getTrees()->at(i)->getRect().y());
        this->controller->movementTree(i);
        this->controller->getModelList()->getTrees()->at(i)->accept(paint);
    }

    for(int i = 0; i<this->controller->getModelList()->getFloors()->size(); i++)
    {
        if(this->controller->getMoveMap())
            this->controller->getModelList()->getFloors()->at(i)->moveLModel();
        this->controller->getModelList()->getFloors()->at(i)->accept(paint);
    }

    for(int i = 0; i<this->controller->getModelList()->getBricks()->size(); i++)
    {
        if(this->controller->getMoveMap())
            this->controller->getModelList()->getBricks()->at(i)->moveLModel();
        this->controller->getModelList()->getBricks()->at(i)->accept(paint);
    }

    for(int i = 0; i<this->controller->getModelList()->getGolds()->size(); i++)
    {
        this->controller->intersectGoldMario(i);
        if(this->controller->getMoveMap())
           this->controller->getModelList()->getGolds()->at(i)->moveLModel();
        this->controller->getModelList()->getGolds()->at(i)->setSrcRect(QRect(Gold::currentFrame, 0, this->controller->getModelList()->getGolds()->at(i)->getRect().width(), this->controller->getModelList()->getGolds()->at(i)->getRect().height()));
        this->controller->getModelList()->getGolds()->at(i)->accept(paint);
    }

    for(int i = 0; i<this->controller->getModelList()->getFlames()->size(); i++)
    {
        this->controller->intersectFlameMario(i);
        this->controller->getModelList()->getFlames()->at(i)->accept(paint);
    }

    for(int i = 0; i<this->controller->getModelList()->getDarkEaters()->size(); i++)
    {
        if(this->controller->getModelList()->getDarkEaters()->at(i)->isDestroyed() && this->controller->getMoveMap())
            this->controller->getModelList()->getDarkEaters()->at(i)->moveLModel();
        this->controller->darkeaterAnimation(i);
        this->controller->getModelList()->getDarkEaters()->at(i)->accept(paint);
    }

    if(this->controller->getModelList()->getShock()->getShow())
    {
        this->controller->getModelList()->getShock()->setSrcRect(QRect(0, Shock::currentFrame, this->controller->getModelList()->getShock()->getRect().width(), this->controller->getModelList()->getShock()->getRect().height()));
        this->controller->getModelList()->getShock()->accept(paint);
    }

    if(this->controller->getModelList()->getMario()->getIsLittle())
    {
        this->controller->getModelList()->getMario()->setRect(QRect(this->controller->getModelList()->getMario()->getRect().x(), this->controller->getModelList()->getMario()->getRect().y(), 25, this->controller->getModelList()->getMario()->getMoveRPlayer().height() - 30));
        this->controller->getModelList()->getMario()->setSrcRect(QRect(this->controller->getModelList()->getMario()->getCurrentFrame()+6, 0, this->controller->getModelList()->getMario()->getRect().width()+25, this->controller->getModelList()->getMario()->getRect().height()+27));
    }
    else
    {
        this->controller->getModelList()->getMario()->setRect(QRect(this->controller->getModelList()->getMario()->getRect().x(), this->controller->getModelList()->getMario()->getRect().y(), 45, this->controller->getModelList()->getMario()->getMoveRPlayer().height() - 7));
        this->controller->getModelList()->getMario()->setSrcRect(QRect(this->controller->getModelList()->getMario()->getCurrentFrame()+6, 1, this->controller->getModelList()->getMario()->getRect().width(), this->controller->getModelList()->getMario()->getRect().height()));
    }

    if(this->controller->getModelList()->getIsPrincessBool())
    {
        if(this->controller->getModelList()->getIsPrincessBool() && this->controller->getMoveMap())
            this->controller->getModelList()->getPrincess()->move(this->controller->getModelList()->getPrincess()->getRect().x() - Brick::speed, this->controller->getModelList()->getPrincess()->getRect().y());
        this->controller->getModelList()->getPrincess()->setRect(QRect(this->controller->getModelList()->getPrincess()->getRect().x(), this->controller->getModelList()->getPrincess()->getRect().y(), this->controller->getModelList()->getPrincess()->getMoveLPlayer().width() / 4, this->controller->getModelList()->getPrincess()->getMoveLPlayer().height()));
        this->controller->getModelList()->getPrincess()->setSrcRect(QRect(this->controller->getModelList()->getPrincess()->getCurrentFrame(), 0, this->controller->getModelList()->getPrincess()->getRect().width(), this->controller->getModelList()->getPrincess()->getRect().height() + 4));
        this->controller->getModelList()->getPrincess()->accept(paint);
    }

    this->controller->getModelList()->getMario()->accept(paint);

    if(this->controller->getModelList()->getLabel()->getShow())
        this->controller->getModelList()->getLabel()->accept(paint);

    painter.drawImage(this->controller->getModelList()->getScore()->getRect().width() - 0, this->controller->getModelList()->getScore()->getRect().height()/8, this->controller->getModelList()->getScore()->getClock());
    painter.drawImage(this->controller->getModelList()->getScore()->getRect().width() - 400, this->controller->getModelList()->getScore()->getRect().height()/8, this->controller->getModelList()->getScore()->getGold());
    painter.setFont(QFont("Tahoma", 17, 0, true));

    QString goldText = QString::number(this->controller->getModelList()->getMario()->getGoldNumber());
    painter.drawText(this->controller->getModelList()->getScore()->getGoldPosition(), goldText);

//    QObject::connect(this->controller->getModelList()->getTime()->timer, SIGNAL(timeout()), this->controller->getModelList()->getTime(), SLOT(realTime()));
//    this->controller->getModelList()->getTime()->timer->start(1000);

    QString timeText = QString::number(this->controller->getModelList()->getTime()->getTime());
    painter.drawText(this->controller->getModelList()->getScore()->getClockPosition(), timeText);

    painter.save();

    if(this->controller->getModelList()->getMario()->getUntouchable())
        painter.setOpacity(0.4);
    else
        painter.setOpacity(1);

    for(int i = 0 ; i < this->controller->getModelList()->getMario()->getLife() ; i++)
        painter.drawImage(this->controller->getModelList()->getScore()->getHeart().size().height() * i, 0, this->controller->getModelList()->getScore()->getHeart());

    painter.restore();

    if(!this->controller->getModelList()->getBlood()->getStopBlood() && this->controller->getModelList()->getMario()->getIsHurted())// Paint Blood when hurted
        this->controller->getModelList()->getBlood()->accept(paint);

    if(this->controller->GameOver()){
        painter.fillRect(QRect(0, 0, ModelList::Width, ModelList::Height), QBrush(QColor(128, 128, 255, 230)));
    }
    else if(this->controller->Completed())
        painter.fillRect(QRect(0, 0, ModelList::Width, ModelList::Height), QBrush(QColor(29, 153, 215, 230)));

    if(this->controller->getModelList()->getSplashScreen()->getIsSplashScreen())
    {
        this->controller->getModelList()->getSplashScreen()->accept(paint);
    }

    if(this->getController()->getModelList()->getMario()->getLife() < 0 ||this->getController()->getModelList()->getTime()->getTime() == 0)
    {
        this->getController()->getModelList()->getMario()->setLife(5);
        this->controller->marioDeath();
        this->controller->getModelList()->getTime()->setTime(-1);
        this->controller->getModelList()->getTime()->timer->stop();
    }
}

void View::keyPressEvent(QKeyEvent *event)
{
    if(!this->controller->GameOver())
    {
        if(event->key() == Qt::Key_Right)
            this->controller->setIsMovingR(true);

        else if(event->key() == Qt::Key_Left)
            this->controller->setIsMovingL(true);

        else if(event->key() == Qt::Key_Down && this->controller->getIsJumping())
            this->controller->setIsAttacking(true);

        else if(event->key() == Qt::Key_Space && this->controller->intersectBottomMario(0))
        {
            this->controller->setIsJumping(true);
            this->controller->setXRelatif(-100);
        }

        else
            event->ignore();
    }

    else if(event->key() == Qt::Key_Enter){

    }

    if (event->key() == Qt::Key_Escape)
    {
        this->controller->stopGame();
        qApp->exit();
    }

}

void View::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Right )
        this->controller->setIsMovingR(false);

    else if(event->key() == Qt::Key_Left )
        this->controller->setIsMovingL(false);

    else
        event->ignore();
}

