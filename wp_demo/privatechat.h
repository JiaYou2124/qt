#ifndef PRIVATECHAT_H
#define PRIVATECHAT_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "protocol.h"
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QMap>
#include <QTabWidget>

namespace Ui {
class privateChat;
}

//单个聊天标签页的结构
struct ChatTab{
    QWidget* widget;
    QTextEdit* showMsg_te;
    QLineEdit* inputMsg_le;
    QPushButton* sendMsg_pb;
    QString chatName;
};

class privateChat : public QWidget
{
    Q_OBJECT

public:
    explicit privateChat(QWidget *parent = nullptr);
    ~privateChat();

    static privateChat &getInstance();

    void setChatName(QString strName);

    void updataMsg(const PDU *pdu);

    void createOrSwitchToChatTab(const QString &chatName);

    void removeChatTab(const QString &chatName);


private slots:
    // void on_sendMsg_pb_clicked();

    void hideWarningLabel();  // 隐藏警告标签的槽函数

    void onSendMsgClicked();

    void onTabCloseRequested(int index);

private:
    void showWarningMessage(const QString &message);  // 显示警告消息的方法
    QWidget* createChatWidget(const QString &charName);
    void setupChatWidgetStyle(QWidget* widget);
    Ui::privateChat *ui;
    QTabWidget *m_tabWidget;

    QString m_strChatName;
    QString m_strLoginName;
    QLabel *m_warningLabel;   // 警告标签
    QTimer *m_warningTimer;   // 定时器

    // 存储每个聊天对象的标签页信息
    QMap<QString, ChatTab> m_chatTabs;
};

#endif // PRIVATECHAT_H
