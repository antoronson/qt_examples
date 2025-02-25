#include "mainwindow.h"
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
   // MainWindow w;
   // w.show();
    QPushButton button("Hello World");
    button.show();
    return app.exec();
}
