#include "ModelList.h"
#include <QFile>

ModelList::ModelList()
{
    this->background = new QList<Background *>;
    this->floors = new QList<Floor *>;
    this->bricks = new QList<Brick*>;
    this->mushrooms = new QList<Mushroom *>;
    this->golds = new QList<Gold *>;
    this->flames = new QList<Flame *>;
    this->splashscreen = new SplashScreen(330, 170, ":/files/images/go2.png");
    this->darkeaters = new QList<DarkEater *>;
    this->background = new QList<Background *>;
    this->score = new Score();
    this->models = new QList<Model*> ;
    this->trees = new QList<Tree *>;
    this->mario = new Mario(200, 340);
    this->blood = new Blood(0, 0);
    this->shock = new Shock(0, 0);
    this->label = new Label(0, 0, "");
    this->getLabel()->setType(LabelType::NONE);
    this->time = new Time(0, 0);

    QFile fichier(":/files/ModelMap.txt");

    if(fichier.open(QIODevice::ReadOnly))
    {
        QTextStream in (&fichier);
        while(!in.atEnd())
        {
            QString stock = in.readLine();
            if (stock.left(6)=="LIGNEa")
            {
                for(int i = 0; i < stock.size(); ++i)
                {
                    if(stock.at(i).isDigit() || stock.at(i).isLetter())
                    {
                        this->list1.append(stock.at(i));
                    }
                }
            }

            else if (stock.left(6)=="LIGNEb")
            {
                for(int i=0;i<stock.size();++i)
                {
                    if(stock.at(i).isDigit() || stock.at(i).isLetter())
                    {
                        this->list2.append(stock.at(i));
                    }
                }
            }

            else if (stock.left(6)=="LIGNEc")
            {
                for(int i=0;i<stock.size();++i)
                {
                    if(stock.at(i).isDigit() || stock.at(i).isLetter())
                    {
                        this->list3.append(stock.at(i));
                    }
                }
            }

            else if (stock.left(6)=="LIGNEd")
            {
                for(int i=0;i<stock.size();++i)
                {
                    if(stock.at(i).isDigit() || stock.at(i).isLetter())
                    {
                        this->list4.append(stock.at(i));
                    }
                }
            }

            else if (stock.left(6)=="LIGNEe")
            {
                for(int i=0;i<stock.size();++i)
                {
                    if(stock.at(i).isDigit() || stock.at(i).isLetter())
                    {
                        this->list5.append(stock.at(i));
                    }
                }
            }

            else if (stock.left(6)=="LIGNEf")
            {
                for(int i=0;i<stock.size();++i)
                {
                    if(stock.at(i).isDigit() || stock.at(i).isLetter())
                    {
                        this->list6.append(stock.at(i));
                    }
                }
            }
        }

        fichier.close();
    }

    for (int i = 0; i < this->NbModelVisible; i++)
    {
        Floor *k = new Floor(i*this->modelSize, this->Height - this->modelSize, QString(":/files/images/floor_bottom.jpg"));
        this->floors->append(k);
        Floor *k2 = new Floor(i*this->modelSize, this->Height - 2*this->modelSize, QString(":/files/images/floor_grass.png"));
        this->floors->append(k2);
    }

    for (int i = 0; i < this->NbModelVisible; i++)
    {
        Model *model = new Model(i*this->modelSize, this->Height + this->modelSize);
        this->models->append(model);
    }

    for (int i = 0; i < 2; i++)
    {
        Background* bg = new Background(i*ModelList::Width, 0);
        this->background->append(bg);
    }
}

ModelList::~ModelList()
{
    this->floors->clear();
    delete this->floors;
    this->golds->clear();
    delete this->golds;
    this->models->clear();
    delete this->models;
    this->background->clear();
    delete this->background;
    this->mushrooms->clear();
    delete this->mushrooms;
    this->darkeaters->clear();
    delete this->darkeaters;
    this->flames->clear();
    delete this->flames;
    this->trees->clear();
    delete this->trees;
    delete this->mario;
    delete this->splashscreen;
}

void ModelList::createModel(QList<QChar> c, int num, int x)
{
    QChar myChar = c.at(this->mapPosition);

    if(myChar == '0')
        return;

    else if(myChar == '1')
    {
        Floor *k= new Floor(x + this->modelSize, this->Height - num*this->modelSize, QString(":/files/images/floor_bottom.jpg"));
        this->floors->append(k);
        return;
    }

    else if(myChar == '2')
    {
        Brick* t= new Brick(x + this->modelSize, this->Height - num*this->modelSize);
        this->bricks->append(t);
        return;
    }

    else if(myChar == '3')
    {
        Gold* g= new Gold(x + this->modelSize, this->Height - num*this->modelSize);
        this->golds->append(g);
        return;
    }

    else if(myChar == '4')
    {
        DarkEater* d = new DarkEater(x + this->modelSize, this->Height - num*this->modelSize);
        d->setMoveX(false);
        this->darkeaters->append(d);
        return;
    }

    else if(myChar == '5')
    {
        Flame* f = new Flame(x + this->modelSize, this->Height - num*this->modelSize);
        f->setMoveX(false);
        this->flames->append(f);
        return;
    }

    else if(myChar == '6')
    {
        Brick* t= new Brick(x + this->modelSize, this->Height - num*this->modelSize);
        t->setCapacity(2);
        this->bricks->append(t);
        return;
    }

    else if(myChar == '7')
    {
        Floor *k= new Floor(x + this->modelSize, this->Height - num*this->modelSize, QString(":/files/images/floor_grass.png"));
        floors->append(k);
        return;
    }

    else if(myChar == '8')
    {
        Floor *k= new Floor(x + this->modelSize, this->Height - num*this->modelSize, QString(":/files/images/floor_right.png"));
        floors->append(k);
        return;
    }

    else if(myChar == '9')
    {
        Floor *k= new Floor(x + this->modelSize, this->Height - num*this->modelSize, QString(":/files/images/floor_left.png"));
        floors->append(k);
        return;
    }

    else if(myChar == 'a'){
        Tree *k= new Tree(x + this->modelSize, this->Height - num*this->modelSize);
        this->trees->append(k);
        return;
    }
}

void ModelList::modelOrganisation()
{
    for(int i = 0; i < this->background->size(); i++)
    {
        if(this->background->at(i)->getRect().x() < -this->background->at(i)->getRect().width() + 2)
        {
            this->background->removeAt(i);
            Background* b = new Background(1000,0);
            this->background->append(b);
        }
    }

    if(this->models->last()->getRect().x() < ((this->NbModelVisible)*this->modelSize))
    {
        Model *m = new Model(this->models->last()->getRect().x() + this->modelSize, this->Height + this->modelSize);
        this->createModel(this->list1, 1, this->models->last()->getRect().x());
        this->createModel(this->list2, 2, this->models->last()->getRect().x());
        this->createModel(this->list3, 3, this->models->last()->getRect().x());
        this->createModel(this->list4, 4, this->models->last()->getRect().x());
        this->createModel(this->list5, 5, this->models->last()->getRect().x());
        this->createModel(this->list6, 6, this->models->last()->getRect().x());
        this->models->append(m);
        this->mapPosition++;
    }

    if (this->models->first()->getRect().x() <= -this->modelSize)
    {
        this->models->removeAt(this->models->indexOf(this->models->first()));
    }

    for(int i = 0; i < this->floors->size(); i++)
    {
        if (this->floors->at(i)->getRect().x() <= -this->modelSize || this->floors->at(i)->isDestroyed())
            this->floors->removeAt(i);
    }

    for(int i = 0; i < this->bricks->size(); i++)
    {
        if (this->bricks->at(i)->getRect().x() <= -this->modelSize || this->bricks->at(i)->isDestroyed())
        {
            this->bricks->removeAt(i);
        }
    }

    for(int i = 0; i < this->golds->size(); i++)
    {
        if (this->golds->at(i)->getRect().x() <= -this->modelSize || golds->at(i)->isDestroyed())
        {
            golds->removeAt(i);
        }
    }

    for(int i = 0; i < this->mushrooms->size(); i++){
        if (this->mushrooms->at(i)->getRect().x() <= -this->modelSize || this->mushrooms->at(i)->isDestroyed())
        {
            this->mushrooms->removeAt(i);
        }
    }

    for(int i = 0; i < this->flames->size(); i++)
    {
        if (this->flames->at(i)->getRect().x() <= -this->modelSize || this->flames->at(i)->isDestroyed())
        {
            this->flames->removeAt(i);
        }
    }

    for(int i = 0; i < this->darkeaters->size(); i++)
    {
        if (this->darkeaters->at(i)->getRect().x() <= -this->modelSize )
        {
            this->darkeaters->removeAt(i);
        }
    }
}

void ModelList::createMushroom(int x, int y, bool up)
{
    Mushroom *m = new Mushroom(x + 9, y + 10, up);
    m->setYR(0);
    m->setXR(0);
    m->setStartY(m->getRect().y() + 50);
    this->mushrooms->append(m);
}

void ModelList::createGameOver(int x, int y)
{
    this->splashscreen = new SplashScreen(x, y, ":/files/images/gameover.png");
}

void ModelList::createCompleted(int x, int y)
{
    this->splashscreen = new SplashScreen(x, y, ":/files/images/level_complete.png");
}

void ModelList::createPrincess(int x, int y)
{
    this->princess = new Princess(x, y);
    this->princess->setIsMovingL(true);
}

void ModelList::createLabel(int x, int y, QString path)
{
    this->label = new Label(x, y, path);
}
