/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QVBoxLayout *verticalLayout_10;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *regist_name_le;
    QLineEdit *regist_pwd_le;
    QLineEdit *emil_le;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *code_le;
    QPushButton *code_pb;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *back_pb;
    QPushButton *regist_pb;
    QWidget *page0;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *name_lb;
    QLabel *pwd_lb;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *name_le;
    QLineEdit *pwd_le;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *login_pb;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *zhuxiao_pb;
    QSpacerItem *horizontalSpacer;
    QPushButton *go_regist_pb;

    void setupUi(QWidget *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName("TcpClient");
        TcpClient->resize(668, 324);
        TcpClient->setAutoFillBackground(false);
        TcpClient->setStyleSheet(QString::fromUtf8("*\n"
"{\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"QWidget#stackedWidget\n"
"{\n"
"	border-radius:30px;\n"
"	background-color: rgba(150, 150, 150, 50);\n"
"	border-image:url(:/img/img/background2.png);\n"
"\n"
"}\n"
"QLabel\n"
"{\n"
"	color: rgba(0,0,0);\n"
"\n"
"}\n"
"/*\350\276\223\345\205\245\346\241\206*/\n"
"QLineEdit#name_le,\n"
"QLineEdit#pwd_le,\n"
"QLineEdit#regist_name_le,\n"
"QLineEdit#emil_le,\n"
"QLineEdit#code_le,\n"
"QLineEdit#regist_pwd_le\n"
"{\n"
"	background-color: transparent;\n"
"	border: 3px solid rgba(255, 255, 255, 150);  /*\350\276\271\346\241\206*/\n"
"	border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"    padding: 4px 8px; /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"/*\350\276\223\345\205\245\346\241\206\346\202\254\345\201\234*/\n"
"QLineEdit:hover#name_le,\n"
"QLineEdit:hover#pwd_le,\n"
"QLineEdit:hover#regist_name_le,\n"
"QLineEdit:hover#regist_pwd_le,\n"
"QLineEdit:hover#emil_le,\n"
"QLineEdit:hover#code_le\n"
"{\n"
"	background-color: transparent;\n"
"	border: 3px solid "
                        "rgba(0, 255, 0, 150);  /*\350\276\271\346\241\206*/\n"
"	border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"    padding: 4px 8px; /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"/*\350\276\223\345\205\245\346\241\206\347\204\246\347\202\271*/\n"
"QLineEdit:focus#name_le,\n"
"QLineEdit:focus#pwd_le,\n"
"QLineEdit:focus#regist_name_le,\n"
"QLineEdit:focus#regist_pwd_le,\n"
"QLineEdit:focus#emil_le,\n"
"QLineEdit:focus#code_le\n"
"{\n"
"	background-color: transparent;\n"
"	border: 3px solid rgba(0, 255, 0, 150);  /*\350\276\271\346\241\206*/\n"
"	border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"    padding: 4px 8px; /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"/*\346\214\211\351\222\256*/\n"
"QPushButton#login_pb,\n"
"QPushButton#go_regist_pb,\n"
"QPushButton#back_pb,\n"
"QPushButton#regist_pb,\n"
"QPushButton#code_pb,\n"
"QPushButton#zhuxiao_pb\n"
"{\n"
"	background-color:rgba(171, 171, 171, 180);\n"
"	border: 3px solid rgba(255, 255, 255, 150);  /*\350\276\271\346\241\206*/\n"
"	/*borde"
                        "r: 1px solid transparent; /* \351\200\217\346\230\216\350\276\271\346\241\206\345\215\240\344\275\215 */\n"
"	border-radius: 10px; /* \345\234\206\350\247\222 */\n"
"    padding: 4px 8px; /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"/*\346\214\211\351\222\256\345\212\250\347\224\273*/\n"
"QPushButton:hover#login_pb,\n"
"QPushButton:hover#go_regist_pb,\n"
"QPushButton:hover#back_pb,\n"
"QPushButton:hover#regist_pb,\n"
"QPushButton:hover#code_pb,\n"
"QPushButton:hover#zhuxiao_pb\n"
"{\n"
"	border: 1px solid rgba(0, 170, 255, 150);\n"
"	color: rgb(0, 170, 255);\n"
"}\n"
""));
        verticalLayout_10 = new QVBoxLayout(TcpClient);
        verticalLayout_10->setObjectName("verticalLayout_10");
        stackedWidget = new QStackedWidget(TcpClient);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page1 = new QWidget();
        page1->setObjectName("page1");
        verticalLayout_9 = new QVBoxLayout(page1);
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label = new QLabel(page1);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(20);
        label->setFont(font);

        verticalLayout_6->addWidget(label);

        label_4 = new QLabel(page1);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout_6->addWidget(label_4);

        label_2 = new QLabel(page1);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout_6->addWidget(label_2);

        label_3 = new QLabel(page1);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_6->addWidget(label_3);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        regist_name_le = new QLineEdit(page1);
        regist_name_le->setObjectName("regist_name_le");
        regist_name_le->setFont(font);

        verticalLayout_7->addWidget(regist_name_le);

        regist_pwd_le = new QLineEdit(page1);
        regist_pwd_le->setObjectName("regist_pwd_le");
        regist_pwd_le->setFont(font);

        verticalLayout_7->addWidget(regist_pwd_le);

        emil_le = new QLineEdit(page1);
        emil_le->setObjectName("emil_le");
        emil_le->setFont(font);

        verticalLayout_7->addWidget(emil_le);


        verticalLayout_8->addLayout(verticalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        code_le = new QLineEdit(page1);
        code_le->setObjectName("code_le");
        code_le->setFont(font);

        horizontalLayout_3->addWidget(code_le);

        code_pb = new QPushButton(page1);
        code_pb->setObjectName("code_pb");
        code_pb->setFont(font);

        horizontalLayout_3->addWidget(code_pb);


        verticalLayout_8->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_8);


        verticalLayout_9->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        back_pb = new QPushButton(page1);
        back_pb->setObjectName("back_pb");
        back_pb->setFont(font);

        horizontalLayout_5->addWidget(back_pb);

        regist_pb = new QPushButton(page1);
        regist_pb->setObjectName("regist_pb");
        regist_pb->setFont(font);

        horizontalLayout_5->addWidget(regist_pb);


        verticalLayout_9->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(page1);
        page0 = new QWidget();
        page0->setObjectName("page0");
        verticalLayout_3 = new QVBoxLayout(page0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        name_lb = new QLabel(page0);
        name_lb->setObjectName("name_lb");
        name_lb->setFont(font);

        verticalLayout->addWidget(name_lb);

        pwd_lb = new QLabel(page0);
        pwd_lb->setObjectName("pwd_lb");
        pwd_lb->setFont(font);

        verticalLayout->addWidget(pwd_lb);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        name_le = new QLineEdit(page0);
        name_le->setObjectName("name_le");
        name_le->setFont(font);

        verticalLayout_2->addWidget(name_le);

        pwd_le = new QLineEdit(page0);
        pwd_le->setObjectName("pwd_le");
        pwd_le->setFont(font);
        pwd_le->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(pwd_le);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        login_pb = new QPushButton(page0);
        login_pb->setObjectName("login_pb");
        login_pb->setFont(font);

        horizontalLayout_6->addWidget(login_pb);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        zhuxiao_pb = new QPushButton(page0);
        zhuxiao_pb->setObjectName("zhuxiao_pb");
        zhuxiao_pb->setFont(font);

        horizontalLayout_2->addWidget(zhuxiao_pb);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        go_regist_pb = new QPushButton(page0);
        go_regist_pb->setObjectName("go_regist_pb");
        go_regist_pb->setFont(font);

        horizontalLayout_2->addWidget(go_regist_pb);


        verticalLayout_3->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page0);

        verticalLayout_10->addWidget(stackedWidget);


        retranslateUi(TcpClient);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QWidget *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "TcpClient", nullptr));
        label->setText(QCoreApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_4->setText(QCoreApplication::translate("TcpClient", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("TcpClient", "\351\202\256\347\256\261\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("TcpClient", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        code_pb->setText(QCoreApplication::translate("TcpClient", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        back_pb->setText(QCoreApplication::translate("TcpClient", "\350\277\224\345\233\236\347\231\273\345\275\225", nullptr));
        regist_pb->setText(QCoreApplication::translate("TcpClient", "\346\263\250\345\206\214", nullptr));
        name_lb->setText(QCoreApplication::translate("TcpClient", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        pwd_lb->setText(QCoreApplication::translate("TcpClient", "\345\257\206\347\240\201\357\274\232", nullptr));
        name_le->setText(QString());
        login_pb->setText(QCoreApplication::translate("TcpClient", "\347\231\273\345\275\225", nullptr));
        zhuxiao_pb->setText(QCoreApplication::translate("TcpClient", "\346\263\250\351\224\200", nullptr));
        go_regist_pb->setText(QCoreApplication::translate("TcpClient", "\347\202\271\345\207\273\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
