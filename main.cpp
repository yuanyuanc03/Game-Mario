#include <QApplication>
#include "View/View.h"

/*
 Mario Game
*/
View * view;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    view = new View();
    return a.exec();
}
