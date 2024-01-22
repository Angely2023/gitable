#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>

#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include "server.h"

class TcpServer : public QDialog
{
    Q_OBJECT
public:
    explicit TcpServer(QWidget *parent = nullptr, Qt::WindowFlags f = 0);

private:
    QListWidget *ContentListWidget;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *CreateBtn;
    QGridLayout *mainLayout;

    int port;
    Server *server;

public slots:
    void slotCreateServer();
    void updateServer(QString, int);


signals:

};

#endif // TCPSERVER_H
