#include "privatechat.h"
#include "ui_privatechat.h"
#include "protocol.h"
#include "tcpclient.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

privateChat::privateChat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::privateChat)
{
    ui->setupUi(this);

    ui->showMsg_te->setFocusPolicy(Qt::NoFocus);
    
    // 初始化警告标签
    m_warningLabel = new QLabel(this);
    m_warningLabel->setStyleSheet(
        "QLabel {"
        "    background-color: #F8F8FF;"
        "    color: #000000;"
        "    border: 1px solid #DCDCDC;"
        "    border-radius: 5px;"
        "    padding: 8px;"
        "    font-weight: bold;"
        "}"
    );
    m_warningLabel->setAlignment(Qt::AlignCenter);
    m_warningLabel->hide();  // 初始时隐藏
    
    // 初始化定时器
    m_warningTimer = new QTimer(this);
    m_warningTimer->setSingleShot(true);  // 只触发一次
    connect(m_warningTimer, &QTimer::timeout, this, &privateChat::hideWarningLabel);
    
    // 设置警告标签的位置（在输入框上方）
    m_warningLabel->setParent(this);
    m_warningLabel->setGeometry(10, height() - 100, width() - 20, 30);
}

privateChat::~privateChat()
{
    delete ui;
}

void privateChat::showWarningMessage(const QString &message)
{
    m_warningLabel->setText(message);
    
    // 动态调整标签位置和大小
    int labelWidth = width() - 20;
    int labelHeight = 30;
    int labelX = 10;
    int labelY = height() - 100;  // 在输入框上方
    
    m_warningLabel->setGeometry(labelX, labelY, labelWidth, labelHeight);
    m_warningLabel->show();
    m_warningLabel->raise();  // 确保标签在最上层
    
    // 启动定时器，1.5秒后隐藏
    m_warningTimer->start(1500);
}

void privateChat::hideWarningLabel()
{
    m_warningLabel->hide();
}

privateChat &privateChat::getInstance()
{
    static privateChat instance;
    return instance;
}

void privateChat::setChatName(QString strName)
{
    //获得聊天对象name
    m_strChatName = strName;
    m_strLoginName = TcpClient::getInstance().getLoginName();
}

void privateChat::updataMsg(const PDU *pdu)
{
    if(NULL == pdu)
    {
        return ;
    }
    char sendName[32];
    memcpy(sendName,pdu->caData,32);
    QString strSendName = QString(sendName);
    QString strMsg = QString((char*)pdu->caMsg);
    ui->showMsg_te->append(QString("%1 : %2").arg(strSendName).arg(strMsg));
}

void privateChat::on_sendMsg_pb_clicked()
{
    QString strMsg = ui->inputMsg_le->text();
    if(!strMsg.trimmed().isEmpty())
    {
        PDU *pdu=mkPDU(strMsg.toUtf8().size()+1);
        pdu->uiMsgType = ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST;
        memcpy(pdu->caData,m_strLoginName.toStdString().c_str()
               ,m_strLoginName.size());
        memcpy(pdu->caData+32,m_strChatName.toStdString().c_str()
               ,m_strChatName.size());

        strncpy((char*)pdu->caMsg,strMsg.toUtf8().constData(),strMsg.toUtf8().size());

        ui->showMsg_te->append(QString("(我) : %1").arg(strMsg));

        TcpClient::getInstance().getQTcpSocket().write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = NULL;
        ui->inputMsg_le->clear();
    }else
    {
        // 使用自定义标签提醒替代QMessageBox
        showWarningMessage("发送的聊天信息不能为空");
        ui->inputMsg_le->clear();
    }
}


