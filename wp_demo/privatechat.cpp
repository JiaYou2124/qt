#include "privatechat.h"
#include "ui_privatechat.h"
#include "protocol.h"
#include "tcpclient.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTabBar>

privateChat::privateChat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::privateChat)
{
    ui->setupUi(this);
    
    // 获取UI中的TabWidget
    m_tabWidget = ui->tabWidget;
    m_tabWidget->setTabsClosable(true);
    m_tabWidget->setMovable(true);
    
    // 连接标签页关闭信号
    connect(m_tabWidget, &QTabWidget::tabCloseRequested, 
            this, &privateChat::onTabCloseRequested);
    
    // 清除默认的标签页
    m_tabWidget->clear();
    
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
    m_warningLabel->hide();
    
    // 初始化定时器
    m_warningTimer = new QTimer(this);
    m_warningTimer->setSingleShot(true);
    connect(m_warningTimer, &QTimer::timeout, this, &privateChat::hideWarningLabel);
    
    // 获取登录用户名
    m_strLoginName = TcpClient::getInstance().getLoginName();
    
    // 设置窗口标题
    setWindowTitle("私聊窗口");
}

privateChat::~privateChat()
{
    delete ui;
}

void privateChat::showWarningMessage(const QString &message)
{
    m_warningLabel->setText(message);
    
    int labelWidth = width() - 20;
    int labelHeight = 30;
    int labelX = 10;
    int labelY = height() - 100;
    
    m_warningLabel->setGeometry(labelX, labelY, labelWidth, labelHeight);
    m_warningLabel->show();
    m_warningLabel->raise();
    
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
    createOrSwitchToChatTab(strName);
}

void privateChat::createOrSwitchToChatTab(const QString &chatName)
{
    // 如果已存在该聊天对象的标签页，直接切换
    if (m_chatTabs.contains(chatName)) {
        for (int i = 0; i < m_tabWidget->count(); ++i) {
            if (m_tabWidget->tabText(i) == chatName) {
                m_tabWidget->setCurrentIndex(i);
                return;
            }
        }
    }
    
    // 创建新的聊天标签页
    QWidget* chatWidget = createChatWidget(chatName);
    int index = m_tabWidget->addTab(chatWidget, chatName);
    m_tabWidget->setCurrentIndex(index);
    
    // 存储标签页信息
    ChatTab chatTab;
    chatTab.widget = chatWidget;
    chatTab.showMsg_te = chatWidget->findChild<QTextEdit*>("showMsg_te");
    chatTab.inputMsg_le = chatWidget->findChild<QLineEdit*>("inputMsg_le");
    chatTab.sendMsg_pb = chatWidget->findChild<QPushButton*>("sendMsg_pb");
    chatTab.chatName = chatName;
    
    m_chatTabs[chatName] = chatTab;
}

QWidget* privateChat::createChatWidget(const QString &chatName)
{
    QWidget* widget = new QWidget();
    
    // 创建布局
    QVBoxLayout* mainLayout = new QVBoxLayout(widget);
    
    // 创建消息显示区域
    QTextEdit* showMsg_te = new QTextEdit();
    showMsg_te->setObjectName("showMsg_te");
    showMsg_te->setReadOnly(true);
    showMsg_te->setFocusPolicy(Qt::NoFocus);
    
    // 创建输入区域
    QHBoxLayout* inputLayout = new QHBoxLayout();
    QLineEdit* inputMsg_le = new QLineEdit();
    inputMsg_le->setObjectName("inputMsg_le");
    QPushButton* sendMsg_pb = new QPushButton("发送");
    sendMsg_pb->setObjectName("sendMsg_pb");
    
    inputLayout->addWidget(inputMsg_le);
    inputLayout->addWidget(sendMsg_pb);
    
    mainLayout->addWidget(showMsg_te);
    mainLayout->addLayout(inputLayout);
    
    // 设置样式
    setupChatWidgetStyle(widget);
    
    // 连接发送按钮信号
    connect(sendMsg_pb, &QPushButton::clicked, this, &privateChat::onSendMsgClicked);
    
    // 连接回车键发送
    connect(inputMsg_le, &QLineEdit::returnPressed, this, &privateChat::onSendMsgClicked);
    
    return widget;
}

void privateChat::setupChatWidgetStyle(QWidget* widget)
{
    // 应用样式表
    widget->setStyleSheet(
        "QTextEdit#showMsg_te {"
        "    border: none;"
        "    background-color: #ededed;"
        "    font-size: 14px;"
        "    padding: 10px;"
        "    color: #333333;"
        "    font-family: 'Microsoft YaHei', 'PingFang SC', 'Helvetica Neue', Arial, sans-serif;"
        "    line-height: 1.4;"
        "    selection-background-color: #3498db;"
        "    selection-color: white;"
        "}"
        "QLineEdit#inputMsg_le {"
        "    border: 1px solid #d9d9d9;"
        "    border-radius: 6px;"
        "    background-color: #ffffff;"
        "    font-size: 14px;"
        "    padding: 8px 12px;"
        "    color: #333333;"
        "    font-family: 'Microsoft YaHei', 'PingFang SC', Arial, sans-serif;"
        "    min-height: 20px;"
        "}"
        "QLineEdit#inputMsg_le:focus {"
        "    border: 1px solid #07c160;"
        "    outline: none;"
        "}"
        "QPushButton#sendMsg_pb {"
        "    background-color: #07c160;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 6px;"
        "    font-size: 14px;"
        "    padding: 8px 20px;"
        "    min-width: 60px;"
        "    font-family: 'Microsoft YaHei', 'PingFang SC', Arial, sans-serif;"
        "}"
        "QPushButton#sendMsg_pb:hover {"
        "    background-color: #06ad56;"
        "}"
        "QPushButton#sendMsg_pb:pressed {"
        "    background-color: #059748;"
        "}"
    );
}

void privateChat::updataMsg(const PDU *pdu)
{
    if(NULL == pdu) {
        return;
    }
    
    char sendName[32];
    memcpy(sendName, pdu->caData, 32);
    QString strSendName = QString(sendName);
    QString strMsg = QString((char*)pdu->caMsg);
    
    // 确保有该用户的聊天标签页
    createOrSwitchToChatTab(strSendName);
    
    // 在对应的标签页中显示消息
    if (m_chatTabs.contains(strSendName)) {
        ChatTab &chatTab = m_chatTabs[strSendName];
        chatTab.showMsg_te->append(QString("%1 : %2").arg(strSendName).arg(strMsg));
    }
}

void privateChat::onSendMsgClicked()
{
    // 获取当前活动的标签页
    int currentIndex = m_tabWidget->currentIndex();
    if (currentIndex < 0) {
        return;
    }
    
    QString currentChatName = m_tabWidget->tabText(currentIndex);
    if (!m_chatTabs.contains(currentChatName)) {
        return;
    }
    
    ChatTab &chatTab = m_chatTabs[currentChatName];
    QString strMsg = chatTab.inputMsg_le->text();
    
    if (!strMsg.trimmed().isEmpty()) {
        PDU *pdu = mkPDU(strMsg.toUtf8().size() + 1);
        pdu->uiMsgType = ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST;
        
        memcpy(pdu->caData, m_strLoginName.toStdString().c_str(), m_strLoginName.size());
        memcpy(pdu->caData + 32, currentChatName.toStdString().c_str(), currentChatName.size());
        strncpy((char*)pdu->caMsg, strMsg.toUtf8().constData(), strMsg.toUtf8().size());
        
        chatTab.showMsg_te->append(QString("(我) : %1").arg(strMsg));
        
        TcpClient::getInstance().getQTcpSocket().write((char*)pdu, pdu->uiPDULen);
        free(pdu);
        pdu = NULL;
        
        chatTab.inputMsg_le->clear();
    } else {
        showWarningMessage("发送的聊天信息不能为空");
        chatTab.inputMsg_le->clear();
    }
}

void privateChat::onTabCloseRequested(int index)
{
    if (index < 0 || index >= m_tabWidget->count()) {
        return;
    }
    
    QString chatName = m_tabWidget->tabText(index);
    removeChatTab(chatName);

    // 当所有标签页都被关闭时，关闭窗口
    if (m_tabWidget->count() == 0) {
        this->close();
    }
}

void privateChat::removeChatTab(const QString &chatName)
{
    if (!m_chatTabs.contains(chatName)) {
        return;
    }
    
    // 找到并移除标签页
    for (int i = 0; i < m_tabWidget->count(); ++i) {
        if (m_tabWidget->tabText(i) == chatName) {
            QWidget* widget = m_tabWidget->widget(i);
            m_tabWidget->removeTab(i);
            delete widget;
            break;
        }
    }
    
    // 从映射中移除
    m_chatTabs.remove(chatName);
}


