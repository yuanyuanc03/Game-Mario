#include "form.h"
#include "background.h"

Form::Form(QWidget *parent): QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);

    //configuration of view
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    view->show();
    scene->setSceneRect(0,0,800,600);
    Background * bg = new Background();
    view->setBackgroundBrush(QBrush(bg->getImage()));

    //transparent bg
    //setAttribute(Qt::WA_TranslucentBackground);

    //sprite settings
    imgPixmap = new QPixmap();
    imgPixTmp = new QPixmap();
    timer = new QTimer();
    memset(&priv_ImgData,0,sizeof(SpriteImageData));
    priv_IsTimeSet = false;
    priv_Status = STATUS_IDLE;
    count = 0;

    QPixmap *Pixmap = new QPixmap(":/files/images/mario_walk_sprites.png");
    SetImageFile(Pixmap,1,21);
    SetTime(50);
    RunSprite();
    x = 0;
    y = 0;
    //view->show();
}

//image file settings
int Sprite::SetImageFile(QPixmap *Pixmap,int UnitX,int UnitY)
{
    QTextStream out(stdout);
    imgPixmap = Pixmap;
    int hight= imgPixmap->height();
    int width = imgPixmap->width();
    int UnitH,UnitW;

    //calculate position
    UnitH = hight%UnitY;
    UnitW = width%UnitX;
    if((0!=UnitH )&& (0!=UnitW))
    {
        out <<"img error :not a standardized format!\n";
        return EXIT_FAILURE;
    }
    else
    {
        UnitH = hight/UnitY;
        UnitW = width/UnitX;
        if((0 >=UnitH )&&(0 >= UnitW))
        {
            out <<"img error:not a img file!\n";
            return EXIT_FAILURE;
        }
    }

    //save image data
    priv_ImgData.imgXY.X = width;
    priv_ImgData.imgXY.Y = hight;
    priv_ImgData.imgHW.X = UnitW;
    priv_ImgData.imgHW.Y = UnitH;
    priv_ImgData.UnitXY.X = UnitX;
    priv_ImgData.UnitXY.Y = UnitY;

    return EXIT_SUCCESS;
}

//time settings
int Sprite::SetTime(int delay)
{
    QTextStream out(stdout);
    if(0 >= delay)
    {
        out<<"set time error :not a time format!\n";
        return EXIT_FAILURE;
    }

    priv_ImgData.imgTime = delay;
    priv_IsTimeSet = true;

    return EXIT_SUCCESS;
}

//run interface
int Sprite::RunSprite(void)
{
    priv_Status = STATUS_RUN;

    timer->start(priv_ImgData.imgTime);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(SpriteUpdate()));
    show();

    return EXIT_SUCCESS;
}

//update
void Sprite::SpriteUpdate(void)
{
    int X, Y;
    count++;
    if(count >= priv_ImgData.UnitXY.X * priv_ImgData.UnitXY.Y)
    {
        count = 0;
    }
    X = priv_ImgData.imgHW.X * (count % priv_ImgData.UnitXY.X);
    Y = priv_ImgData.imgHW.Y * (count / priv_ImgData.UnitXY.X);
    *imgPixTmp = imgPixmap->copy(X,Y,priv_ImgData.imgHW.X,priv_ImgData.imgHW.Y);
    resize(imgPixTmp->size());
    setMask(QBitmap(imgPixTmp->mask()));
    update();
}

//show position
void Sprite::SetPosition(int X,int Y)
{
    setGeometry(X,Y,priv_ImgData.imgHW.X,priv_ImgData.imgHW.Y);
}

//draw sprite animation
void Sprite::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,*imgPixTmp);
}



void Form::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        KeyUpfunc(event);
        break;
    case Qt::Key_Down:
        KeyDownfunc(event);
        break;
    case Qt::Key_Left:
        KeyLeftfunc(event);
        break;
    case Qt::Key_Right:
        KeyRightfunc(event);
        break;
    default:
        break;
    }
}

void Form::KeyDownfunc(QKeyEvent *)
{
    y+=10;
    if(600 > y && 0 < y)
    {
       spimg->SetPosition(x,y);
    }
    else
    {
         y = 0;
    }
}

void Form::KeyLeftfunc(QKeyEvent *)
{
    x-=10;
    if(800 > x && 0 < x)
    {
       spimg->SetPosition(x,y);
    }
    else
    {
         x = 0;
    }
}

void Form::KeyRightfunc(QKeyEvent *)
{
    x+=10;
    if(800 > x && 0 < x)
    {
       spimg->SetPosition(x,y);
    }
    else
    {
         x = 0;
    }
}

void Form::KeyUpfunc(QKeyEvent *)
{
    y-=10;
    if(800 > x && 0 < x)
    {
       spimg->SetPosition(x,y);
    }
    else
    {
         y = 0;
    }
}
