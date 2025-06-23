#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QFile>
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include <QTcpSocket>
#include <qhostaddress>
#include "protocol.h"
#include "opewidget.h"
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TcpClient;
}
QT_END_NAMESPACE

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    void loadConfig();
    QTcpSocket* getTcpSocket();
    QString getm_strIP();
    quint16 getm_usPort();

    static TcpClient &getInstance();
    QTcpSocket &getQTcpSocket();
    QString &getLoginName();
    QString getcurPath();
    void setcurPath(QString curPath);

public slots:
    void showConnect();
    void recvMsg();

private slots:
    // void on_send_pb_clicked();

    void on_login_pb_clicked();

    void on_regist_pb_clicked();

    void on_go_regist_pb_clicked();

    void on_back_pb_clicked();



private:
    Ui::TcpClient *ui;
    QString m_strIP;
    quint16 m_usPort;
    QStackedWidget *m_pSW;

    //连接服务器，和服务器数据交互
    QTcpSocket m_tcpsocket;
    QString m_loginUserName;
    QString m_strCurPath;
    QFile m_file;
};
#endif // TCPCLIENT_H
