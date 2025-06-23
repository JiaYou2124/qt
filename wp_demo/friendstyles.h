#ifndef FRIENDSTYLES_H
#define FRIENDSTYLES_H

#include <QString>

class FriendStyles
{
public:
    // 好友列表样式
    static QString getFriendListStyle();
    
    // 消息显示区域样式
    static QString getMessageDisplayStyle();
    
    // 输入框样式
    static QString getInputLineStyle();
    
    // 普通按钮样式
    static QString getButtonStyle();
    
    // 发送按钮样式
    static QString getSendButtonStyle();
    
    // 整体背景样式
    static QString getWidgetBackgroundStyle();
    
    // Online组件样式
    static QString getOnlineListStyle();
    static QString getAddFriendButtonStyle();
    static QString getOnlineWidgetStyle();
};

#endif // FRIENDSTYLES_H