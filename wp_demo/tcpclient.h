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
#include <QMouseEvent>

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

    void on_hide_pb_clicked();

    void on_close_pb_clicked();

protected:
    //鼠标事件处理函数
    void mousePressEvent(QMouseEvent *event) override;          //鼠标点击
    void mouseMoveEvent(QMouseEvent *event) override;           //鼠标移动
    void mouseReleaseEvent(QMouseEvent *event) override;        //鼠标释放

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

    // 添加窗口拖拽相关变量
    bool m_bDragging;
    QPoint m_dragPosition;
    bool m_bMaximized;
    QRect m_normalGeometry;

};
#endif // TCPCLIENT_H
