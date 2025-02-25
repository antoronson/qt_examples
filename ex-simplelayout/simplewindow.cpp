#include "simplewindow.h"

#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>


simplewindow::simplewindow(QWidget *parent) :
    QWidget(parent)
{
    auto outer = new QVBoxLayout(this); // Adds vertical tabs line by line

    auto noteLabel = new QLabel ("Note:");
    outer -> addWidget(noteLabel);


    auto noteEdit = new QTextEdit;
    outer -> addWidget(noteEdit);

    auto inner = new QHBoxLayout;   // Adds horizontal tabs
    outer -> addLayout(inner);

    auto clearButton = new QPushButton("Clear");
    outer -> addWidget(clearButton);


    auto saveButton = new QPushButton("save");
    outer -> addWidget(saveButton);


}


