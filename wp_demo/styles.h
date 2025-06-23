#ifndef STYLES_H
#define STYLES_H

#include <QString>

class Styles
{
public:
    // Friend组件样式
    static QString getFriendListStyle();
    static QString getMessageDisplayStyle();
    static QString getInputLineStyle();
    static QString getButtonStyle();
    static QString getSendButtonStyle();
    static QString getWidgetBackgroundStyle();
    
    // Online组件样式
    static QString getOnlineListStyle();
    static QString getAddFriendButtonStyle();
    static QString getOnlineWidgetStyle();
    
    // OpeWidget组件样式
    static QString getNavigationListStyle();
    static QString getStackedWidgetStyle();
    static QString getOpeWidgetBackgroundStyle();
    
    // Book组件样式
    static QString getBookListStyle();
    static QString getBookButtonStyle();
    static QString getBookWidgetStyle();
};

#endif // STYLES_H