
#include"restaurant.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Restaurant w;
    w.show();

    return a.exec();
}
