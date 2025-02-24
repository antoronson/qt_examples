#include "chatwindow.h"
#include <QVBoxLayout>

ChatWindow::ChatWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    chatDisplay = new QTextEdit(this);
    chatDisplay->setReadOnly(true);

    inputField = new QLineEdit(this);
    connect(inputField, &QLineEdit::returnPressed, this, &ChatWindow::processMessage);

    layout->addWidget(chatDisplay);
    layout->addWidget(inputField);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    setWindowTitle("Simple Chat Bot");
    resize(400, 300);
}

void ChatWindow::processMessage() {
    QString userMessage = inputField->text().trimmed();
    if (!userMessage.isEmpty()) {
        chatDisplay->append("User: " + userMessage);
        chatDisplay->append("Bot: " + userMessage);
        inputField->clear();
    }
}

