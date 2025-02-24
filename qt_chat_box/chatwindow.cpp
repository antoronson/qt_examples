#include "chatwindow.h"
#include <QVBoxLayout>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QFile>
#include <QTextStream>

ChatWindow::ChatWindow(QWidget *parent) : QMainWindow(parent) {
    setupDatabase();
    loadDocument();
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    chatDisplay = new QTextEdit(this);
    chatDisplay->setReadOnly(true);
    loadChatHistory();

    inputField = new QLineEdit(this);
    connect(inputField, &QLineEdit::returnPressed, this, &ChatWindow::processMessage);

    layout->addWidget(chatDisplay);
    layout->addWidget(inputField);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    setWindowTitle("Interactive LLM Chat Bot");
    resize(500, 400);
}

void ChatWindow::processMessage() {
    QString userMessage = inputField->text().trimmed();
    if (!userMessage.isEmpty()) {
        chatDisplay->append("User: " + userMessage);
        QString botResponse = searchDocument(userMessage);
        chatDisplay->append("Bot: " + botResponse);
        saveMessage("User", userMessage);
        saveMessage("Bot", botResponse);
        inputField->clear();
    }
}

void ChatWindow::setupDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("chat_history.db");

    if (!db.open()) {
        qDebug() << "Database Error:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS chat (id INTEGER PRIMARY KEY AUTOINCREMENT, sender TEXT, message TEXT)");
}

void ChatWindow::saveMessage(const QString &sender, const QString &message) {
    QSqlQuery query;
    query.prepare("INSERT INTO chat (sender, message) VALUES (:sender, :message)");
    query.bindValue(":sender", sender);
    query.bindValue(":message", message);
    if (!query.exec()) {
        qDebug() << "Error saving message:" << query.lastError().text();
    }
}

void ChatWindow::loadChatHistory() {
    QSqlQuery query("SELECT sender, message FROM chat");
    while (query.next()) {
        QString sender = query.value(0).toString();
        QString message = query.value(1).toString();
        chatDisplay->append(sender + ": " + message);
    }
}

void ChatWindow::loadDocument() {
    QFile file("document.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        documentText = in.readAll();
        file.close();
    } else {
        qDebug() << "Failed to load document.";
    }
}

QString ChatWindow::searchDocument(const QString &query) {
    if (documentText.contains(query, Qt::CaseInsensitive)) {
        int index = documentText.indexOf(query, 0, Qt::CaseInsensitive);
        int start = qMax(0, index - 50);
        int end = qMin(documentText.length(), index + query.length() + 50);
        return documentText.mid(start, end - start) + "...";
    }
    return "No relevant information found.";
}
