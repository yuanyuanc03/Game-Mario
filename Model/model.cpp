#include "model.h"
#include <QtDebug>


Model::Model(int x, int y)
{
    this->destroyed = false;
    this->rect.translate(x, y);
    this->rect.setSize(QSize(50,50));
}

Model::Model(int x, int y, QString path)
{
    //this->model = QPixmap(path);
    this->path = path;
    convertPNG(this->path);
    this->destroyed = false;
    this->setImage();
    this->setModel();
    this->rect = this->getImage().rect();
    this->rect.translate(x, y);
}

Model::~Model()
{

}

//move the origin to (x, y)
void Model::move(int x, int y)
{
    this->rect.moveTo(x, y);
}

//move left the model
void Model::moveLModel()
{
    this->rect.moveTo(this->rect.left() - Model::speed, this->rect.top());
}

//move right the model
void Model::moveRModel()
{
    this->rect.moveTo(this->rect.left() + Model::speed, this->rect.top());
}

//top collision of modelrect
bool Model::intersectTop(QRect rect)
{
    if(rect.intersected(this->getRect()).width() > 7 && this->getRect().y() > rect.y())
    {
        this->move(this->getRect().x(), rect.y() + 49);
        return true;
    }
    return false;
}

//bottom collision of modelrect
bool Model::intersectBottom(QRect rect)
{
    if(rect.intersected(this->rect).width() > 5 && this->rect.y() < rect.y())
    {
        this->move(this->rect.x(), rect.y() - this->rect.height() + 1);
        return true;
    }
    return false;
}

//right collision of modelrect
bool Model::intersectRight(QRect rect)
{
    if(rect.intersected(this->rect).height() > 5 && this->rect.x() < rect.x() )
        return true;
    return false;
}

//left collision of modelrect
bool Model::intersectLeft(QRect rect)
{
    if(rect.intersected(this->rect).height() > 5 && this->rect.x() > rect.x())
        return true;
    return false;
}

//save the ressources as PNG
void Model::convertPNG(QString path)
{
    QImage image(path);
    if(image.isNull())
    {
        qDebug()<<"No such image";
    }
    else
    {
        image.save(path, "PNG");
    }
}
