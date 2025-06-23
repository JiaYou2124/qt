#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>
#include "protocol.h"
#include <QByteArray>
#include "opedb.h"
#include <QFile>
#include <QTimer>

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT;
public:
    MyTcpSocket();
    QString getName();

public slots:
    void recvMsg();

    void clientOfflinet();

    void sendFileToClient();
signals:
    void offline(MyTcpSocket *mysocket);

private:
    QString user_Name;

    QFile m_file;

    qint64 m_iTotal;
    qint64 m_iRecved;
    bool m_bUploadt;

    QTimer *m_pTimer;
};

#endif // MYTCPSOCKET_H
