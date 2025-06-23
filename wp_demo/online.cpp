#include "online.h"
#include "ui_online.h"
#include "tcpclient.h"
#include "styles.h"  // 更改为新的样式头文件
#include <QMessageBox>

Online::Online(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Online)
{
    ui->setupUi(this);
    
    // 应用样式
    ui->online_lw->setStyleSheet(Styles::getOnlineListStyle());
    ui->online_lw->setFocusPolicy(Qt::NoFocus);
    
    ui->add_friend_pb->setStyleSheet(Styles::getAddFriendButtonStyle());
    
    // 设置整体背景
    this->setStyleSheet(Styles::getOnlineWidgetStyle());
}

void Online::showUser(PDU *pdu)
{
    ui->online_lw->clear();
    if(NULL == pdu)
    {
        return ;
    }
    uint uiSize = pdu->uiMsgLen/32;
    char caTemp[32];
    qDebug()<<"接收uiPDUlen大小："<<pdu->uiPDULen;
    qDebug()<<"接收uiMsgLen大小："<<pdu->uiMsgLen;
    for(uint i = 0;i<uiSize;i++)
    {
        memcpy(caTemp,(char*)(pdu->caMsg)+i*32,32);
        ui->online_lw->addItem(caTemp);
        qDebug()<<caTemp;
    }
}

Online::~Online()
{
    delete ui;
}

void Online::on_add_friend_pb_clicked()
{
    QListWidgetItem *pItem = ui->online_lw->currentItem();

    if(NULL == pItem)
    {
        QMessageBox::information(this,"提示","请先选择要添加的用户！");
        return ;
    }

    //获取添加对象用户名
    QString strPerson = pItem->text();
    //通过登录按钮保存的用户名获取当前用户的用户名
    QString loginName = TcpClient::getInstance().getLoginName();
    PDU *pdu = mkPDU(0);
    pdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_REQUEST;
    // 被请求方
    memcpy(pdu->caData+32,strPerson.toStdString().c_str()
           ,32);
    // 请求方
    memcpy(pdu->caData,loginName.toStdString().c_str()
           ,32);
    TcpClient::getInstance().getTcpSocket()->write((char*)pdu,pdu->uiPDULen);
    free(pdu);
    pdu = NULL;
}

