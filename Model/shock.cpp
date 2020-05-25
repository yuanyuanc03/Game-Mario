#include "shock.h"


Shock::Shock(int x, int y): Model(x, y)
{
    this->model = QPixmap(":/files/images/shock.png");
    this->setRect(QRect(x, y, this->model.width(), this->model.height()/3));
}
