#include "server.h"

Server::Server(QWidget *parent, int port) : QTcpServer(parent)
{
    listen(QHostAddress::Any, port);
    //listen(QHostAddress::LocalHost, port);
}

void Server::updateClients(QString msg, int length)
{
    qDebug() << "emit updateServer(msg, length);";
    emit updateServer(msg, length);
    for(int i = 0; i < tcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(), length) != length)
        {
            continue;
        }
    }
}

void Server::slotDisconnected(int socketDescriptor)
{
    for(int i = 0; i < tcpClientSocketList.count(); i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor() == socketDescriptor)
        {
            tcpClientSocketList.removeAt(i);
            return;
        }
    }
    return;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    TcpClientSocket *tcpClientSocket = new TcpClientSocket;
    connect(tcpClientSocket, SIGNAL(updateClients(QString, int)), this, SLOT(updateClients(QString, int)));
    connect(tcpClientSocket, SIGNAL(disconnected(int)), this, SLOT(slotDisconnected((int))));
    tcpClientSocket->setSocketDescriptor(socketDescriptor);
    tcpClientSocketList.append(tcpClientSocket);
}

