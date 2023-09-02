#include "shapedrawing.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShapeDrawing w;
    w.show();
    return a.exec();
}
