/********************************************************************************
** Form generated from reading UI file 'online.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINE_H
#define UI_ONLINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Online
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *online_lw;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *add_friend_pb;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Online)
    {
        if (Online->objectName().isEmpty())
            Online->setObjectName("Online");
        Online->resize(239, 312);
        Online->setStyleSheet(QString::fromUtf8("QListWidget { \n"
"           border: 1px solid #cccccc; \n"
"           border-radius: 8px; \n"
"           background-color: #ffffff; \n"
"           font-size: 16px; \n"
"           outline: none;\n"
"           padding: 5px; \n"
"           } \n"
"           QListWidget::item { \n"
"           padding: 12px 15px; \n"
"           border-bottom: 1px solid #f0f0f0; \n"
"           outline: none; \n"
"           border: none; \n"
"           color: #333333; \n"
"           } \n"
"           QListWidget::item:selected { \n"
"           background-color: #3498db; \n"
"           color: white; \n"
"           outline: none; \n"
"           border: none; \n"
"           border-radius: 4px; \n"
"           } \n"
"           QListWidget::item:hover { \n"
"           background-color: #e8f4fd; \n"
"           color: #2980b9; \n"
"           outline: none; \n"
"           border: none; \n"
"           border-radius: 4px; \n"
"           } \n"
"           QListWidget::item:focus { \n"
"           outline: none; \n"
"  "
                        "         border: none; \n"
"           }\n"
"QPushButton { \n"
"           background-color: blue; \n"
"           color: black; \n"
"           border: none; \n"
"           border-radius: 8px; \n"
"           font-size: 16px; \n"
"           font-weight: bold; \n"
"           padding: 12px 20px; \n"
"           min-width: 100px; \n"
"           font-family: 'Microsoft YaHei', Arial, sans-serif; \n"
"           }\n"
"           QPushButton:hover { \n"
"           background-color: #229954; \n"
"           transform: translateY(-1px); \n"
"          } \n"
"           QPushButton:pressed { \n"
"           background-color: #1e8449; \n"
"           transform: translateY(0px); \n"
"           } \n"
"           QPushButton:focus { \n"
"           outline: none; \n"
"           border: 2px solid #58d68d; \n"
"           }\n"
"QWidget { \n"
"           background-color: #f8f9fa; \n"
"           border: 1px solid #dee2e6; \n"
"           border-radius: 10px; \n"
"           padding: 10px; \n"
"           }"));
        horizontalLayout_2 = new QHBoxLayout(Online);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        online_lw = new QListWidget(Online);
        online_lw->setObjectName("online_lw");
        QFont font;
        online_lw->setFont(font);

        horizontalLayout->addWidget(online_lw);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        add_friend_pb = new QPushButton(Online);
        add_friend_pb->setObjectName("add_friend_pb");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setBold(true);
        add_friend_pb->setFont(font1);

        verticalLayout->addWidget(add_friend_pb);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Online);

        QMetaObject::connectSlotsByName(Online);
    } // setupUi

    void retranslateUi(QWidget *Online)
    {
        Online->setWindowTitle(QCoreApplication::translate("Online", "Form", nullptr));
        add_friend_pb->setText(QCoreApplication::translate("Online", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Online: public Ui_Online {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINE_H
