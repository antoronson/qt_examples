#include "simplewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    simplewindow window;
    window.show();
    return app.exec();
}
