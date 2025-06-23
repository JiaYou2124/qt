#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QWidget>
#include "tcpclient.h"
#include "protocol.h"
#include <QTimer>


namespace Ui {
class Document;
}

class Document : public QWidget
{
    Q_OBJECT

public:
    explicit Document(QWidget *parent = nullptr);
    ~Document();
    void updateFileList(const PDU *pdu);

    void reFreshFileList();

    static Document &getInstance();

    void clearEnterName();

    QString getm_enterDir();

    void setDownLoadFlag(bool flag);

    bool getDownLoad();

    QString getSaveFilePath();

    qint64 m_iTotal;        //总大小
    qint64 m_iRecved;       //已接收多少

private slots:
    void on_createdir_pb_clicked();

    void on_flushFile_pb_clicked();

    void on_deldir_pb_clicked();

    void on_rename_pb_clicked();

    void enterDir(const QModelIndex &index);

    void on_back_pb_clicked();

    void on_upload_pb_clicked();

    void uploadFiledata();


    void on_delFile_pb_clicked();

    void on_download_pb_clicked();

private:
    Ui::Document *ui;
    QString m_EnterDir;
    QString m_UploadFilePath;

    QTimer *m_pTimer;
    QString m_saveFilePath;
    bool m_isDownLoad;
};

#endif // DOCUMENT_H
