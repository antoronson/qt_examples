#include "simplewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    simplewindow window;
    window.show();

    simplewindow window1;
    window1.show();
    return app.exec();
}
