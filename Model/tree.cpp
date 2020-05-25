#include "tree.h"


Tree::Tree(int x, int y): Player(x, y)
{
    this->moveL_Player = QPixmap(":/files/images/mysticTree.png");
    this->stop_player = QPixmap(":/files/images/mysticTree_die.png");
    this->rect = QRect(x, y, this->moveL_Player.width(), this->moveL_Player.height());
    this->isMovingL = true;

    //tree sound
    treesound = new QMediaPlayer();
    treesound->setMedia(QUrl(":/files/sounds/boom.war"));
}
