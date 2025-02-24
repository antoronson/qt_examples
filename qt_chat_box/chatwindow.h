// chatwindow.h
#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QtSql/QSqlDatabase>

class ChatWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);

private slots:
    void processMessage();

private:
    QTextEdit *chatDisplay;
    QLineEdit *inputField;
    QSqlDatabase db;
    QString documentText;

    void setupDatabase();
    void saveMessage(const QString &sender, const QString &message);
    void loadChatHistory();
    void loadDocument();
    QString searchDocument(const QString &query);
};

#endif // CHATWINDOW_H
