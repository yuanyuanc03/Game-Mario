#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <QObject>
class ModelList;
class View;

class Game : public QObject
{
    Q_OBJECT
public:
    Game(ModelList * modelList, View * view);
    ~Game();
};

#endif // GAMEBOARD_H
