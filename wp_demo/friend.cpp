#include "friend.h"
#include "styles.h"  // 更改为新的样式头文件
#include "protocol.h"
#include "tcpclient.h"
#include <QInputDialog>
#include "privatechat.h"
Friend::Friend(QWidget *parent)
    : QWidget{parent}
{
    m_pShowMsgTE = new QTextEdit;
    m_pFriendListWidget = new QListWidget;
    m_pInputMsgLE = new QLineEdit;

    m_pDelFriendPB = new QPushButton("删除好友");
    m_pFlushFriendPB = new QPushButton("刷新好友");
    m_pShowOnlineUserPB = new QPushButton("查看在线用户");
    m_pSearchUserPB = new QPushButton("查找用户");
    pMsgSendPB = new QPushButton("发送");
    m_pPrivateChatPB = new QPushButton("私聊");

    m_pShowMsgTE->setFocusPolicy(Qt::NoFocus);

    // 应用样式
    m_pFriendListWidget->setFixedWidth(150);
    m_pFriendListWidget->setStyleSheet(Styles::getFriendListStyle());
    m_pFriendListWidget->setFocusPolicy(Qt::NoFocus);
    
    m_pShowMsgTE->setStyleSheet(Styles::getMessageDisplayStyle());
    m_pInputMsgLE->setStyleSheet(Styles::getInputLineStyle());
    
    // 应用按钮样式
    QString buttonStyle = Styles::getButtonStyle();
    m_pDelFriendPB->setStyleSheet(buttonStyle);
    m_pFlushFriendPB->setStyleSheet(buttonStyle);
    m_pShowOnlineUserPB->setStyleSheet(buttonStyle);
    m_pSearchUserPB->setStyleSheet(buttonStyle);
    m_pPrivateChatPB->setStyleSheet(buttonStyle);
    
    // 发送按钮使用特殊样式
    pMsgSendPB->setStyleSheet(Styles::getSendButtonStyle());
    
    // 设置整体背景
    this->setStyleSheet(Styles::getWidgetBackgroundStyle());

    //垂直布局
    QVBoxLayout *pRightPBVBL = new QVBoxLayout;
    pRightPBVBL->setSpacing(8);  // 设置按钮间距
    pRightPBVBL->addWidget(m_pDelFriendPB);
    pRightPBVBL->addWidget(m_pFlushFriendPB);
    pRightPBVBL->addWidget(m_pShowOnlineUserPB);
    pRightPBVBL->addWidget(m_pSearchUserPB);
    pRightPBVBL->addWidget(m_pPrivateChatPB);

    //水平布局
    QHBoxLayout * pTopHBL = new QHBoxLayout;
    pTopHBL->setSpacing(10);  // 设置组件间距
    pTopHBL->addWidget(m_pShowMsgTE);
    pTopHBL->addWidget(m_pFriendListWidget);
    pTopHBL->addLayout(pRightPBVBL);

    QHBoxLayout *pMsgHBL = new QHBoxLayout;
    pMsgHBL->setSpacing(8);
    pMsgHBL->addWidget(m_pInputMsgLE);
    pMsgHBL->addWidget(pMsgSendPB);

    m_pOnline = new Online;

    QVBoxLayout *pMain = new QVBoxLayout;
    pMain->setSpacing(10);  // 设置主布局间距
    pMain->setContentsMargins(15, 15, 15, 15);  // 设置外边距
    pMain->addLayout(pTopHBL);
    pMain->addLayout(pMsgHBL);
    pMain->addWidget(m_pOnline);
    m_pOnline->hide();

    setLayout(pMain);

    connect(m_pShowOnlineUserPB,SIGNAL(clicked(bool))
            ,this,SLOT(showOnline()));

    connect(m_pSearchUserPB,SIGNAL(clicked(bool))
            ,this,SLOT(searchUser()));

    connect(m_pFlushFriendPB,SIGNAL(clicked(bool))
            ,this,SLOT(flushFriend()));

    connect(m_pDelFriendPB,SIGNAL(clicked(bool))
            ,this,SLOT(delFriend()));

    connect(m_pPrivateChatPB,SIGNAL(clicked(bool))
            ,this,SLOT(privateChat()));

    connect(pMsgSendPB,SIGNAL(clicked(bool))
            ,this,SLOT(groupChat()));

    m_pFriendListWidget->setFocusPolicy(Qt::NoFocus);
}

void Friend::showAllOnlineUser(PDU *pdu)
{
    if(NULL == pdu)
    {
        return;
    }
    m_pOnline->showUser(pdu);
    qDebug()<<"接收查看在线用户请求";
}

void Friend::updataFriendList(PDU *pdu)
{
    if(NULL == pdu)
    {
        return;
    }
    m_pFriendListWidget->clear();
    qDebug()<<"----调用updataFriendList";
    uint uiSize = pdu->uiMsgLen/32;
    char caName[32];
    for(int i = 0;i<uiSize;i++)
    {
        memcpy(caName,(char*)(pdu->caMsg)+i*32,32);
        m_pFriendListWidget->addItem(caName);
        qDebug()<<caName;
    }
}

void Friend::updataGroupMsg(PDU *pdu)
{
    if(NULL == pdu)
    {
        return;
    }
    char sendName[32];
    memcpy(sendName,pdu->caData,32);
    QString strMsg = QString((char*)pdu->caMsg);
    m_pShowMsgTE->append(QString("%1 ：%2").arg(sendName).arg(strMsg));
}

void Friend::showOnline()
{
    if(m_pOnline->isHidden())
    {
        m_pOnline->show();
        PDU *pdu = mkPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_LIST_ONLINEUSER_REQUEST;
        TcpClient::getInstance().getQTcpSocket().write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = NULL;
        qDebug()<<"调用showOnline（）";
    }
    else
    {
        m_pOnline->hide();
    }
}

void Friend::searchUser()
{
    m_strSearchName = QInputDialog::getText(this,"搜索","用户名");
    if(!m_strSearchName.isEmpty())
    {
        qDebug() <<m_strSearchName;
        PDU *pdu = mkPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_SEARCH_USER_REQUEST;
        strncpy(pdu->caData,m_strSearchName.toStdString().c_str(),m_strSearchName.size());
        qDebug() <<pdu->caData;
        TcpClient::getInstance().getQTcpSocket().write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = NULL;
    }
    // else
    // {
    //     // QMessageBox::information(this,"用户名为空","用户名不能为空");
    // }

}

void Friend::flushFriend()
{
    qDebug()<<"调用flushFriend（）";
    QString loginUser = TcpClient::getInstance().getLoginName();
    PDU *pdu = mkPDU(0);
    pdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST;
    memcpy(pdu->caData,loginUser.toStdString().c_str(),loginUser.size());
    TcpClient::getInstance().getQTcpSocket().write((char*)pdu,pdu->uiPDULen);
    free(pdu);
    pdu = NULL;
}

void Friend::delFriend()
{
    qDebug()<<"调用delFriend（）";
    if(NULL != m_pFriendListWidget->currentItem())
    {
        QString delName = m_pFriendListWidget->currentItem()->text();
        qDebug()<<"删除对象用户名字："<<delName;
        int ref = QMessageBox::information(this,"删除好友","确认删除好友吗？"
                                           ,QMessageBox::Yes,QMessageBox::No);
        if(ref==QMessageBox::Yes)
        {
            PDU *pdu = mkPDU(0);
            QString LoginUserName = TcpClient::getInstance().getLoginName();
            pdu->uiMsgType = ENUM_MSG_TYPE_DEL_FRIEND_REQUEST;
            memcpy(pdu->caData,LoginUserName.toStdString().c_str(),LoginUserName.size());
            memcpy(pdu->caData+32,delName.toStdString().c_str(),delName.size());
            qDebug()<<pdu->caData;
            qDebug()<<pdu->caData+32;
            TcpClient::getInstance().getTcpSocket()->write((char*)pdu,pdu->uiPDULen);
            free(pdu);
            pdu = NULL;
        }
    }
}

void Friend::privateChat()
{
    qDebug()<<"调用privateChat（）";
    if(NULL != m_pFriendListWidget->currentItem())
    {
        QString Chatname = m_pFriendListWidget->currentItem()->text();
        privateChat::getInstance().setChatName(Chatname);
        if(privateChat::getInstance().isHidden())
        {
            privateChat::getInstance().show();
        }
    }
}

void Friend::groupChat()
{
    qDebug()<<"调用groupChat（）";
    QString strMsg = m_pInputMsgLE->text();
    if(!strMsg.trimmed().isEmpty())
    {
        PDU *pdu = mkPDU(strMsg.toUtf8().size()+1);
        pdu->uiMsgType = ENUM_MSG_TYPE_GROUP_CHAT_REQUEST;
        QString loginName = TcpClient::getInstance().getLoginName();
        strncpy(pdu->caData,loginName.toStdString().c_str()
                ,loginName.size());
        strncpy((char*)(pdu->caMsg),strMsg.toUtf8()
                ,strMsg.toUtf8().size());

        // QString myStrMsg = QString ("(我) : %1").arg(strMsg);
        // m_pShowMsgTE->append(myStrMsg);

        TcpClient::getInstance().getTcpSocket()->write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = NULL;
        m_pInputMsgLE->clear();
    }else
    {
        qDebug()<<"消息不能为空";
        m_pInputMsgLE->clear();
    }
}










