#include "paint.h"
#include "Model/model.h"
#include "Model/player.h"

Paint::Paint(QPainter *painter)
{
    this->painter = painter;
}

void Paint::drawModel(Model *model)
{
    this->painter->drawPixmap(model->getRect(), model->getModel(), model->getSrcRect());
}

void Paint::drawPlayer(Player *player)
{
    if(player->getIsMovingR())
        this->painter->drawPixmap(player->getRect(), player->getMoveRPlayer(), player->getSrcRect());

    else if(player->getIsMovingL())
        getPainter()->drawPixmap(player->getRect(), player->getMoveLPlayer(), player->getSrcRect());

    else
        getPainter()->drawPixmap(player->getRect(), player->getStopPlayer(), player->getSrcRect());
}
