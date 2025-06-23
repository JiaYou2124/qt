/********************************************************************************
** Form generated from reading UI file 'privatechat.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVATECHAT_H
#define UI_PRIVATECHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_privateChat
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *showMsg_te;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *inputMsg_le;
    QPushButton *sendMsg_pb;

    void setupUi(QWidget *privateChat)
    {
        if (privateChat->objectName().isEmpty())
            privateChat->setObjectName("privateChat");
        privateChat->resize(643, 418);
        privateChat->setStyleSheet(QString::fromUtf8("\n"
"\n"
"\n"
"\n"
"\n"
"/* \346\225\264\344\275\223\347\252\227\345\217\243\346\240\267\345\274\217 */\n"
"QWidget#privateChat {\n"
"    background-color: #ededed;\n"
"    border-radius: 0px;\n"
"}\n"
"\n"
"/* \346\266\210\346\201\257\346\230\276\347\244\272\345\214\272\345\237\237\346\240\267\345\274\217 */\n"
"QTextEdit#showMsg_te {\n"
"    border: none;\n"
"    background-color: #ededed;\n"
"    font-size: 14px;\n"
"    padding: 10px;\n"
"    color: #333333;\n"
"    font-family: 'Microsoft YaHei', 'PingFang SC', 'Helvetica Neue', Arial, sans-serif;\n"
"    line-height: 1.4;\n"
"    selection-background-color: #3498db;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QTextEdit#showMsg_te:focus {\n"
"    border: none;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* TabWidget \346\240\267\345\274\217 */\n"
"QTabWidget {\n"
"    background-color: #ededed;\n"
"    border: none;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: none;\n"
"    background-color: #ededed;\n"
"    margin-top: 0px;\n"
"}\n"
"\n"
"QTabBar::tab "
                        "{\n"
"    background-color: #f7f7f7;\n"
"    color: #333333;\n"
"    border: 1px solid #d9d9d9;\n"
"    border-bottom: none;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    padding: 8px 16px;\n"
"    margin-right: 1px;\n"
"    font-family: 'Microsoft YaHei', Arial, sans-serif;\n"
"    font-size: 13px;\n"
"    min-width: 60px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #ededed;\n"
"    color: #333333;\n"
"    border-bottom: 1px solid #ededed;\n"
"    font-weight: normal;\n"
"}\n"
"\n"
"QTabBar::tab:hover:!selected {\n"
"    background-color: #f0f0f0;\n"
"}\n"
"\n"
"/* \350\276\223\345\205\245\346\241\206\346\240\267\345\274\217 */\n"
"QLineEdit#inputMsg_le {\n"
"    border: 1px solid #d9d9d9;\n"
"    border-radius: 6px;\n"
"    background-color: #ffffff;\n"
"    font-size: 14px;\n"
"    padding: 8px 12px;\n"
"    color: #333333;\n"
"    font-family: 'Microsoft YaHei', 'PingFang SC', Arial, sans-serif;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QLineEdit#inp"
                        "utMsg_le:focus {\n"
"    border: 1px solid #07c160;\n"
"    outline: none;\n"
"    background-color: #ffffff;\n"
"}\n"
"\n"
"QLineEdit#inputMsg_le:hover {\n"
"    border-color: #b3b3b3;\n"
"}\n"
"\n"
"/* \345\217\221\351\200\201\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"QPushButton#sendMsg_pb {\n"
"    background-color: #07c160;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    font-weight: normal;\n"
"    padding: 8px 20px;\n"
"    min-width: 60px;\n"
"    font-family: 'Microsoft YaHei', 'PingFang SC', Arial, sans-serif;\n"
"}\n"
"\n"
"QPushButton#sendMsg_pb:hover {\n"
"    background-color: #06ad56;\n"
"}\n"
"\n"
"QPushButton#sendMsg_pb:pressed {\n"
"    background-color: #059748;\n"
"}\n"
"\n"
"QPushButton#sendMsg_pb:focus {\n"
"    outline: none;\n"
"    border: 1px solid #04843b;\n"
"}\n"
"\n"
"QPushButton#sendMsg_pb:disabled {\n"
"    background-color: #c0c0c0;\n"
"    color: #888888;\n"
"}"));
        verticalLayout = new QVBoxLayout(privateChat);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(privateChat);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        showMsg_te = new QTextEdit(tab);
        showMsg_te->setObjectName("showMsg_te");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        showMsg_te->setFont(font);
        showMsg_te->setTabChangesFocus(false);
        showMsg_te->setReadOnly(true);

        horizontalLayout->addWidget(showMsg_te);


        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        inputMsg_le = new QLineEdit(privateChat);
        inputMsg_le->setObjectName("inputMsg_le");
        inputMsg_le->setFont(font);

        horizontalLayout_2->addWidget(inputMsg_le);

        sendMsg_pb = new QPushButton(privateChat);
        sendMsg_pb->setObjectName("sendMsg_pb");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setBold(false);
        sendMsg_pb->setFont(font1);

        horizontalLayout_2->addWidget(sendMsg_pb);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(privateChat);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(privateChat);
    } // setupUi

    void retranslateUi(QWidget *privateChat)
    {
        privateChat->setWindowTitle(QCoreApplication::translate("privateChat", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("privateChat", "Tab 1", nullptr));
        sendMsg_pb->setText(QCoreApplication::translate("privateChat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class privateChat: public Ui_privateChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATECHAT_H
