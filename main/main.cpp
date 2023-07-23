#include "game2048.h"
#include<controller.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Game2048 w;
//    w.show();
    Controller* c = new Controller();
    return a.exec();
}
