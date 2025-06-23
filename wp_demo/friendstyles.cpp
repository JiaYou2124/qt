#include "friendstyles.h"

QString FriendStyles::getFriendListStyle()
{
    return "QListWidget { "
           "border: 1px solid #cccccc; "
           "border-radius: 5px; "
           "background-color: #f9f9f9; "
           "font-size: 14px; "
           "outline: none; "
           "} "
           "QListWidget::item { "
           "padding: 8px; "
           "border-bottom: 1px solid #eeeeee; "
           "outline: none; "
           "border: none; "
           "} "
           "QListWidget::item:selected { "
           "background-color: #3498db; "
           "color: white; "
           "outline: none; "
           "border: none; "
           "} "
           "QListWidget::item:hover { "
           "background-color: #5dade2; "
           "outline: none; "
           "border: none; "
           "} "
           "QListWidget::item:focus { "
           "outline: none; "
           "border: none; "
           "}";
}

QString FriendStyles::getMessageDisplayStyle()
{
    return "QTextEdit { "
           "border: 1px solid #cccccc; "
           "border-radius: 8px; "
           "background-color: #ffffff; "
           "font-size: 14px; "
           "padding: 10px; "
           "color: #333333; "
           "font-family: 'Microsoft YaHei', Arial, sans-serif; "
           "line-height: 1.4; "
           "}";
}

QString FriendStyles::getInputLineStyle()
{
    return "QLineEdit { "
           "border: 2px solid #e0e0e0; "
           "border-radius: 6px; "
           "background-color: #ffffff; "
           "font-size: 14px; "
           "padding: 8px 12px; "
           "color: #333333; "
           "font-family: 'Microsoft YaHei', Arial, sans-serif; "
           "} "
           "QLineEdit:focus { "
           "border-color: #3498db; "
           "outline: none; "
           "background-color: #f8f9fa; "
           "}";
}

QString FriendStyles::getButtonStyle()
{
    return "QPushButton { "
           "background-color: #3498db; "
           "color: white; "
           "border: none; "
           "border-radius: 6px; "
           "font-size: 14px; "
           "font-weight: bold; "
           "padding: 10px 15px; "
           "min-width: 80px; "
           "font-family: 'Microsoft YaHei', Arial, sans-serif; "
           "} "
           "QPushButton:hover { "
           "background-color: #2980b9; "
           "transform: translateY(-1px); "
           "} "
           "QPushButton:pressed { "
           "background-color: #21618c; "
           "transform: translateY(0px); "
           "} "
           "QPushButton:focus { "
           "outline: none; "
           "border: 2px solid #5dade2; "
           "}";
}

QString FriendStyles::getSendButtonStyle()
{
    return "QPushButton { "
           "background-color: #27ae60; "
           "color: white; "
           "border: none; "
           "border-radius: 6px; "
           "font-size: 14px; "
           "font-weight: bold; "
           "padding: 10px 15px; "
           "min-width: 60px; "
           "font-family: 'Microsoft YaHei', Arial, sans-serif; "
           "} "
           "QPushButton:hover { "
           "background-color: #229954; "
           "transform: translateY(-1px); "
           "} "
           "QPushButton:pressed { "
           "background-color: #1e8449; "
           "transform: translateY(0px); "
           "} "
           "QPushButton:focus { "
           "outline: none; "
           "border: 2px solid #58d68d; "
           "}";
}

QString FriendStyles::getWidgetBackgroundStyle()
{
    return "QWidget { "
           "background-color: #f8f9fa; "
           "font-family: 'Microsoft YaHei', Arial, sans-serif; "
           "}";
}

QString FriendStyles::getOnlineListStyle()
{
    return "QListWidget { "
           "border: 1px solid #cccccc; "
           "border-radius: 8px; "
           "background-color: #ffffff; "
           "font-size: 16px; "
           "outline: none; "
           "padding: 5px; "
           "} "
           "QListWidget::item { "
           "padding: 12px 15px; "
           "border-bottom: 1px solid #f0f0f0; "
           "outline: none; "
           "border: none; "
           "color: #333333; "
           "} "
           "QListWidget::item:selected { "
           "background-color: #3498db; "
           "color: white; "
           "outline: none; "
           "border: none; "
           "border-radius: 4px; "
           "} "
           "QListWidget::item:hover { "
           "background-color: #e8f4fd; "
           "color: #2980b9; "
           "outline: none; "
           "border: none; "
           "border-radius: 4px; "
           "} "
           "QListWidget::item:focus { "
           "outline: none; "
           "border: none; "
           "}";
}

QString FriendStyles::getAddFriendButtonStyle()
{
    return "QPushButton { "
           "background-color: #27ae60; "
           "color: white; "
           "border: none; "
           "border-radius: 8px; "
           "font-size: 16px; "
           "font-weight: bold; "
           "padding: 12px 20px; "
           "min-width: 100px; "
           "font-family: 'Microsoft YaHei', Arial, sans-serif; "
           "} "
           "QPushButton:hover { "
           "background-color: #229954; "
           "transform: translateY(-1px); "
           "} "
           "QPushButton:pressed { "
           "background-color: #1e8449; "
           "transform: translateY(0px); "
           "} "
           "QPushButton:focus { "
           "outline: none; "
           "border: 2px solid #58d68d; "
           "}";
}

QString FriendStyles::getOnlineWidgetStyle()
{
    return "QWidget { "
           "background-color: #f8f9fa; "
           "border: 1px solid #dee2e6; "
           "border-radius: 10px; "
           "padding: 10px; "
           "}";
}
