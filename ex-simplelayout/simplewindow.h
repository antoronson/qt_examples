#ifndef SIMPLEWINDOW_H
#define SIMPLEWINDOW_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class simplewindow;
}
QT_END_NAMESPACE

class simplewindow : public QWidget
{
    Q_OBJECT

public:
    explicit simplewindow(QWidget *parent = nullptr);

};
#endif // SIMPLEWINDOW_H
