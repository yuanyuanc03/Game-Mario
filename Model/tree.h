#ifndef TREE_H
#define TREE_H

#include <QMediaPlayer>
#include "player.h"

class Tree: public Player
{
public:
    //constructor
    Tree(int, int);

    //setters and getters
    int getMoveCount() { return moveCount; }
    void setmoveCount(int moveCount) { this->moveCount = moveCount; }
    QMediaPlayer* getTreeSound() { return this->treesound; }
    void setTreeSound(QMediaPlayer* treeSound) { this->treesound = treeSound; }

private:
    int moveCount = 50;
    QMediaPlayer * treesound;
};

#endif // TREE_H
