#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QWidget>
#include <QTcpSocket>
#include <QObject>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QWidget *parent = nullptr);

signals:
    void updateClients(QString, int);
    void disconnected(int);
protected slots:
    void dataReceived();
    void slotDisconnected();

};

#endif // TCPCLIENTSOCKET_H
