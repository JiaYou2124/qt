#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <QList>
#include "mytcpsocket.h"

class Mytcpserver : public QTcpServer
{
    Q_OBJECT
public:
    explicit Mytcpserver(QObject *parent = nullptr);

    static Mytcpserver &getInstance();

    void incomingConnection(qintptr socketDescriptor);

    void resend(const char *name,PDU *pdu);

    QList<MyTcpSocket*> getMyTcpSockets();

public slots:
    void deleteSocket(MyTcpSocket *mysocket);

private:
    QList<MyTcpSocket*> m_tcpSocketList;
};

#endif // MYTCPSERVER_H
