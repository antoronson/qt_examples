#include "chatwindow.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //MainWindow w;
    //w.show();
    ChatWindow window;
    window.show();
    return app.exec();
}
