#include "mainwindow.h"

#include <QApplication>

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    QPushButton button("Hello World");
    button.show();
    return a.exec();
}
