#include "styles.h"

// Friend组件样式
QString Styles::getFriendListStyle()
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

QString Styles::getMessageDisplayStyle()
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

QString Styles::getInputLineStyle()
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

QString Styles::getButtonStyle()
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
           "} "
           "QPushButton:pressed { "
           "background-color: #21618c; "
           "} "
           "QPushButton:focus { "
           "outline: none; "
           "border: 2px solid #5dade2; "
           "}";
}

QString Styles::getSendButtonStyle()
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
           "} "
           "QPushButton:pressed { "
           "background-color: #1e8449; "
           "} "
           "QPushButton:focus { "
           "outline: none; "
           "border: 2px solid #58d68d; "
           "}";
}

QString Styles::getWidgetBackgroundStyle()
{
    return "QWidget { "
           "background-color: #f8f9fa; "
           "font-family: 'Microsoft YaHei', Arial, sans-serif; "
           "}";
}

// Online组件样式
QString Styles::getOnlineListStyle()
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

QString Styles::getAddFriendButtonStyle()
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
           "} "
           "QPushButton:pressed { "
           "background-color: #1e8449; "
           "} "
           "QPushButton:focus { "
           "outline: none; "
           "border: 2px solid #58d68d; "
           "}";
}

QString Styles::getOnlineWidgetStyle()
{
    return "QWidget { "
           "background-color: #f8f9fa; "
           "border: 1px solid #dee2e6; "
           "border-radius: 10px; "
           "padding: 10px; "
           "}";
}

// OpeWidget组件样式
QString Styles::getNavigationListStyle()
{
    return "QListWidget { "
           "background-color: #3498db; "
           "border: 1px solid #34495e; "
           "border-radius: 8px; "
           "font-size: 15px; "
           "color: #ecf0f1; "
           "padding: 5px; "
           "outline: none; "
           "} "
           "QListWidget::item { "
           "padding: 12px 8px; "
           "border-bottom: 1px solid #34495e; "
           "outline: none; "
           "border: none; "
           "color: #bdc3c7; "
           "} "
           "QListWidget::item:selected { "
           "background-color: #3498db; "
           "color: white; "
           "outline: none; "
           "border: none; "
           "border-radius: 4px; "
           "} "
           "QListWidget::item:hover { "
           "background-color: #34495e; "
           "color: #ecf0f1; "
           "outline: none; "
           "border: none; "
           "border-radius: 4px; "
           "} "
           "QListWidget::item:focus { "
           "outline: none; "
           "border: none; "
           "}";
}

QString Styles::getStackedWidgetStyle()
{
    return "QStackedWidget { "
           "background-color: #ffffff; "
           "border: 1px solid #ddd; "
           "border-radius: 8px; "
           "}";
}

QString Styles::getOpeWidgetBackgroundStyle()
{
    return "OpeWidget { "
           "background-color: #f8f9fa; "
           "}";
}

// Book组件样式
QString Styles::getBookListStyle()
{
    return "QListWidget { "
           "border: 1px solid #cccccc; "
           "border-radius: 8px; "
           "background-color: #ffffff; "
           "font-size: 14px; "
           "outline: none; "
           "padding: 5px; "
           "} "
           "QListWidget::item { "
           "padding: 10px 12px; "
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

QString Styles::getBookButtonStyle()
{
    return "QPushButton { "
           "background-color: #9b59b6; "
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
           "background-color: #8e44ad; "
           "} "
           "QPushButton:pressed { "
           "background-color: #7d3c98; "
           "} "
           "QPushButton:focus { "
           "outline: none; "
           "border: 2px solid #bb8fce; "
           "}";
}

QString Styles::getBookWidgetStyle()
{
    return "QWidget { "
           "background-color: #f8f9fa; "
           "font-family: 'Microsoft YaHei', Arial, sans-serif; "
           "}";
}
