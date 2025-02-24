#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>

class ChatWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);

private slots:
    void processMessage();

private:
    QTextEdit *chatDisplay;
    QLineEdit *inputField;
};

#endif // CHATWINDOW_H
