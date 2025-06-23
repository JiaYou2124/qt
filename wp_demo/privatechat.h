#ifndef PRIVATECHAT_H
#define PRIVATECHAT_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "protocol.h"
#include <QTabWidget>

namespace Ui {
class privateChat;
}

class privateChat : public QWidget
{
    Q_OBJECT

public:
    explicit privateChat(QWidget *parent = nullptr);
    ~privateChat();

    static privateChat &getInstance();

    void setChatName(QString strName);

    void updataMsg(const PDU *pdu);



private slots:
    void on_sendMsg_pb_clicked();
    void hideWarningLabel();  // 隐藏警告标签的槽函数


private:
    void showWarningMessage(const QString &message);  // 显示警告消息的方法
    Ui::privateChat *ui;
    QString m_strChatName;
    QTabWidget *m_tabWidget;
    QString m_strLoginName;
    // QMap<QString,ChatWidget*> m_chatWidgets;
    QLabel *m_warningLabel;   // 警告标签
    QTimer *m_warningTimer;   // 定时器
};

#endif // PRIVATECHAT_H
