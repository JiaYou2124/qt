#include "tcpserver.h"
#include "./ui_tcpserver.h"
#include "mytcpserver.h"
#include <QHostAddress>
#include "opedb.h"


Tcpserver::Tcpserver(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tcpserver)
{
    ui->setupUi(this);
    loadConfig();
    Mytcpserver::getInstance().listen(QHostAddress(m_strIP),m_usPort);

}

Tcpserver::~Tcpserver()
{
    delete ui;
}

void Tcpserver::loadConfig()
{
    QFile file(":/server.config");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray baData =  file.readAll();
        QString strData = baData.toStdString().c_str();
        file.close();

        strData.replace("\r\n"," ");

        QStringList strList = strData.split(" ");

        m_strIP = strList.at(0);
        m_usPort = strList.at(1).toUShort();
        qDebug() << "ip:" << m_strIP << " port:" << m_usPort;
    }
    else
    {
        QMessageBox::critical(this,"打开配置文件","打开失败");
    }
}


