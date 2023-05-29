#include "vibor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vibor w;
    w.show();
    return a.exec();
}
