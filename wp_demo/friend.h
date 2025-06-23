#ifndef FRIEND_H
#define FRIEND_H

#include <QWidget>
#include <QTextEdit>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>  //垂直布局
#include <QHBoxLayout>  //水平布局
#include "online.h"


class Friend : public QWidget
{
    Q_OBJECT
public:

    QString m_strSearchName;
    explicit Friend(QWidget *parent = nullptr);
    void showAllOnlineUser(PDU *pdu);
    void updataFriendList(PDU *pdu);
    void updataGroupMsg(PDU *pdu);

public slots:
    void showOnline();
    void searchUser();
    void flushFriend();
    void delFriend();
    void privateChat();
    void groupChat();

signals:
private:
    QTextEdit *m_pShowMsgTE;
    QListWidget *m_pFriendListWidget;
    QLineEdit *m_pInputMsgLE;

    QPushButton *m_pDelFriendPB;
    QPushButton *m_pFlushFriendPB;
    QPushButton *m_pShowOnlineUserPB;
    QPushButton *m_pSearchUserPB;
    QPushButton *pMsgSendPB;
    QPushButton *m_pPrivateChatPB;

    Online *m_pOnline;

};

#endif // FRIEND_H
