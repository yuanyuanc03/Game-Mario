#include "Controller/gamecontroller.h"
#include <QDesktopWidget>
#include <QApplication>
#include "Model/modellist.h"
#include "View/view.h"
class View;

void center(QWidget &widget)
{
    int x, y;
    int screenWidth;
    int screenHeight;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - ModelList::Width) / 2;
    y = (screenHeight - ModelList::Height) / 2;

    widget.setGeometry(x, y, ModelList::Width, ModelList::Height);
    widget.setFixedSize(ModelList::Width, ModelList::Height);
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ModelList model;
    View view;
    GameController window(&model, &view);
    view.setWindowTitle("Mario Game");
    view.show();
    center(view);
    return app.exec();
}
