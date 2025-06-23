#include "mytcpserver.h"
#include <QDebug>

Mytcpserver::Mytcpserver(QObject *parent)
    : QTcpServer{parent}
{

}

Mytcpserver &Mytcpserver::getInstance()
{
    static Mytcpserver instance;
    return instance;
}

void Mytcpserver::incomingConnection(qintptr socketDescriptor)
{

    qDebug() << "新客户端连接";
    MyTcpSocket *pTcpSocket = new MyTcpSocket;
    pTcpSocket->setSocketDescriptor(socketDescriptor);
    m_tcpSocketList.append(pTcpSocket);

    connect(pTcpSocket,SIGNAL(offline(MyTcpSocket*)),this,SLOT(deleteSocket(MyTcpSocket*)));
}

void Mytcpserver::resend(const char *name, PDU *pdu)
{
    if(NULL == name || NULL == pdu)
    {
        return ;
    }
    QString strName = name;
    for(int i = 0;i<m_tcpSocketList.size();i++)
    {
        if(strName == m_tcpSocketList.at(i)->getName())
        {
            m_tcpSocketList.at(i)->write((char*)pdu,pdu->uiPDULen);
            break;
        }
    }
}

void Mytcpserver::deleteSocket(MyTcpSocket *mysocket)
{
    QList<MyTcpSocket*>::iterator iter = m_tcpSocketList.begin();
    for(;iter !=m_tcpSocketList.end();iter++)
    {
        if(mysocket == *iter)
        {
            // delete *iter;
            (*iter) -> deleteLater(); // 释放空间
            *iter = nullptr;
            m_tcpSocketList.erase(iter);
            break;
        }
    }
    if(!m_tcpSocketList.isEmpty())
    {
        qDebug()<<"当前在线用户：";
        for(int i = 0;i<m_tcpSocketList.size();i++)
        {
            qDebug()<< m_tcpSocketList.at(i)->getName();
        }
    }
    else
    {
        qDebug()<<"当前无在线用户!";
    }


    // for(;iter !=m_tcpSocketList.end();iter++)
    // {
    //     if(mysocket == *iter)
    //     {
    //         delete *iter;
    //         *iter = nullptr;
    //         m_tcpSocketList.erase(iter);
    //         break;
    //     }
    // }
    // qDebug()<<"当前在线用户：";
    // for(int i = 0;i<m_tcpSocketList.size();i++)
    // {
    //     qDebug()<< m_tcpSocketList.at(i)->getName();
    // }
}
