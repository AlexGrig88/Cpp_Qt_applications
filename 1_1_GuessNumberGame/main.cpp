#include "widgetgame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetGame w;
    w.show();
    return a.exec();
}
