/********************************************************************************
** Form generated from reading UI file 'document.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCUMENT_H
#define UI_DOCUMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Document
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *back_pb;
    QPushButton *flushFile_pb;
    QPushButton *rename_pb;
    QPushButton *createdir_pb;
    QPushButton *deldir_pb;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *document_lw;
    QVBoxLayout *verticalLayout_2;
    QPushButton *delFile_pb;
    QPushButton *upload_pb;
    QPushButton *download_pb;
    QPushButton *shareFile_pb;

    void setupUi(QWidget *Document)
    {
        if (Document->objectName().isEmpty())
            Document->setObjectName("Document");
        Document->resize(675, 415);
        Document->setStyleSheet(QString::fromUtf8("/* Document\347\273\204\344\273\266\346\240\267\345\274\217 */\n"
"\n"
"/* \346\226\207\346\241\243\345\210\227\350\241\250\346\240\267\345\274\217 */\n"
"QListWidget {\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 15px;\n"
"    background-color: #ffffff;\n"
"    font-size: 14px;\n"
"    outline: none;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    padding: 12px 15px;\n"
"    border-bottom: 1px solid #f0f0f0;\n"
"    outline: none;\n"
"    border: none;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    outline: none;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #9dbbfd;\n"
"    color: #2980b9;\n"
"    outline: none;\n"
"    border: none;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QListWidget::item:focus {\n"
"    outline: none;\n"
"    border: none;\n"
"}\n"
"\n"
"/* \345\267\246\350\276\271\346\214\211\351\222\256\346\240\267\345"
                        "\274\217 */\n"
"QPushButton#back_pb,\n"
"#createdir_pb,\n"
"#rename_pb,\n"
"#flushFile_pb{\n"
"    background-color: #00aaff;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    padding: 6px;\n"
"    min-width: 100px;\n"
"    min-height: 35px;\n"
"    font-family: 'Microsoft YaHei', Arial, sans-serif;\n"
"}\n"
"\n"
"QPushButton#back_pb:hover,\n"
"#createdir_pb:hover,\n"
"#rename_pb:hover,\n"
"#flushFile_pb:hover {\n"
"    background-color: #55aaff;\n"
"}\n"
"\n"
"QPushButton#back_pb:pressed,\n"
"#createdir_pb:pressed,\n"
"#rename_pb:pressed,\n"
"#flushFile_pb:pressed {\n"
"    background-color: #55aaff;\n"
"}\n"
"\n"
"QPushButton#back_pb:focus,\n"
"#createdir_pb:focus,\n"
"#rename_pb:focus,\n"
"#flushFile_pb:focus {\n"
"    outline: none;\n"
"    border: 2px solid #f39c12;\n"
"}\n"
"\n"
"/* \345\210\240\351\231\244\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"QPushButton#deldir_pb,\n"
"QPushButton#delFile_pb {\n"
"    ba"
                        "ckground-color: #e74c3c;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    padding: 6px 12px;\n"
"    min-width: 100px;\n"
"    min-height: 35px;\n"
"    font-family: 'Microsoft YaHei', Arial, sans-serif;\n"
"}\n"
"\n"
"QPushButton#deldir_pb:hover,\n"
"QPushButton#delFile_pb:hover {\n"
"    background-color: #e73528;\n"
"}\n"
"\n"
"QPushButton#deldir_pb:pressed,\n"
"QPushButton#delFile_pb:pressed {\n"
"    background-color: #e73528;\n"
"}\n"
"\n"
"QPushButton#deldir_pb:focus,\n"
"QPushButton#delFile_pb:focus {\n"
"    outline: none;\n"
"    border: 2px solid #00ff7f;\n"
"}\n"
"\n"
"/* \345\217\263\350\276\271\346\214\211\351\222\256\346\240\267\345\274\217 */\n"
"QPushButton#upload_pb,\n"
"#download_pb,\n"
"#shareFile_pb {\n"
"    background-color: #27ae60;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 15px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    padding: 6px 12px;\n"
"    min-width: 100"
                        "px;\n"
"    min-height: 35px;\n"
"    font-family: 'Microsoft YaHei', Arial, sans-serif;\n"
"}\n"
"\n"
"QPushButton#upload_pb:hover,\n"
"#upload_pb:hover,\n"
"#download_pb:hover,\n"
"#shareFile_pb:hover {\n"
"    background-color: #229954;\n"
"}\n"
"\n"
"QPushButton#upload_pb:pressed,\n"
"#upload_pb:pressed,\n"
"#download_pb:pressed,\n"
"#shareFile_pb:pressed {\n"
"    background-color: #1e8449;\n"
"}\n"
"\n"
"QPushButton#upload_pb:focus,\n"
"#upload_pb:focus,\n"
"#download_pb:focus,\n"
"#shareFile_pb:focus {\n"
"    outline: none;\n"
"    border: 2px solid #58d68d;\n"
"}\n"
"\n"
"/* \346\225\264\344\275\223Widget\346\240\267\345\274\217 */\n"
"QWidget {\n"
"    background-color: #f8f9fa;\n"
"    font-family: 'Microsoft YaHei', Arial, sans-serif;\n"
"}"));
        verticalLayout = new QVBoxLayout(Document);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        back_pb = new QPushButton(Document);
        back_pb->setObjectName("back_pb");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setBold(true);
        back_pb->setFont(font);

        horizontalLayout->addWidget(back_pb);

        flushFile_pb = new QPushButton(Document);
        flushFile_pb->setObjectName("flushFile_pb");
        flushFile_pb->setFont(font);

        horizontalLayout->addWidget(flushFile_pb);

        rename_pb = new QPushButton(Document);
        rename_pb->setObjectName("rename_pb");
        rename_pb->setFont(font);

        horizontalLayout->addWidget(rename_pb);

        createdir_pb = new QPushButton(Document);
        createdir_pb->setObjectName("createdir_pb");
        createdir_pb->setFont(font);

        horizontalLayout->addWidget(createdir_pb);

        deldir_pb = new QPushButton(Document);
        deldir_pb->setObjectName("deldir_pb");
        deldir_pb->setFont(font);

        horizontalLayout->addWidget(deldir_pb);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        document_lw = new QListWidget(Document);
        document_lw->setObjectName("document_lw");

        horizontalLayout_2->addWidget(document_lw);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        delFile_pb = new QPushButton(Document);
        delFile_pb->setObjectName("delFile_pb");
        delFile_pb->setFont(font);

        verticalLayout_2->addWidget(delFile_pb);

        upload_pb = new QPushButton(Document);
        upload_pb->setObjectName("upload_pb");
        upload_pb->setFont(font);

        verticalLayout_2->addWidget(upload_pb);

        download_pb = new QPushButton(Document);
        download_pb->setObjectName("download_pb");
        download_pb->setFont(font);

        verticalLayout_2->addWidget(download_pb);

        shareFile_pb = new QPushButton(Document);
        shareFile_pb->setObjectName("shareFile_pb");
        shareFile_pb->setFont(font);

        verticalLayout_2->addWidget(shareFile_pb);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Document);

        QMetaObject::connectSlotsByName(Document);
    } // setupUi

    void retranslateUi(QWidget *Document)
    {
        Document->setWindowTitle(QCoreApplication::translate("Document", "Form", nullptr));
        back_pb->setText(QCoreApplication::translate("Document", "\350\277\224\345\233\236", nullptr));
        flushFile_pb->setText(QCoreApplication::translate("Document", "\345\210\267\346\226\260\346\226\207\344\273\266\345\244\271", nullptr));
        rename_pb->setText(QCoreApplication::translate("Document", "\351\207\215\345\221\275\345\220\215\346\226\207\344\273\266", nullptr));
        createdir_pb->setText(QCoreApplication::translate("Document", "\345\210\233\345\273\272\346\226\207\344\273\266\345\244\271", nullptr));
        deldir_pb->setText(QCoreApplication::translate("Document", "\345\210\240\351\231\244\346\226\207\344\273\266\345\244\271", nullptr));
        delFile_pb->setText(QCoreApplication::translate("Document", "\345\210\240\351\231\244\346\226\207\344\273\266", nullptr));
        upload_pb->setText(QCoreApplication::translate("Document", "\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
        download_pb->setText(QCoreApplication::translate("Document", "\344\270\213\350\275\275\346\226\207\344\273\266", nullptr));
        shareFile_pb->setText(QCoreApplication::translate("Document", "\345\210\206\344\272\253\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Document: public Ui_Document {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCUMENT_H
