#include "document.h"
#include "ui_document.h"
#include <QInputDialog>
#include <QFileDialog>

Document::Document(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Document)
{
    ui->setupUi(this);

    m_EnterDir.clear();

    m_pTimer = new QTimer;

    m_isDownLoad = false;

    m_iTotal = 0;
    m_iRecved = 0;

    connect(ui->document_lw,SIGNAL(doubleClicked(QModelIndex))
            ,this,SLOT(enterDir(QModelIndex)));

    connect(m_pTimer,SIGNAL(timeout())
             ,this,SLOT(uploadFiledata()));

}

Document::~Document()
{
    delete ui;
}

void Document::updateFileList(const PDU *pdu)
{
    if(NULL == pdu)
    {
        return;
    }
    ui->document_lw->clear();
    FileInfo *pFileInfo = NULL;
    int iCount = pdu->uiMsgLen/sizeof(FileInfo);
    for(int i = 0;i<iCount;i++)
    {
        pFileInfo = (FileInfo*)(pdu->caMsg)+i;
        QListWidgetItem *pItem = new QListWidgetItem;
        if(0 == pFileInfo->iFileType)
        {
            pItem->setIcon(QIcon(QPixmap(":/img/img/文件夹.png")));
        }
        else if(1 == pFileInfo->iFileType)
        {
            pItem->setIcon(QIcon(QPixmap(":/img/img/文件.png")));
        }
        pItem->setText(pFileInfo->caFileName);
        ui->document_lw->addItem(pItem);

    }
}

void Document::reFreshFileList()
{
    QString curPath = TcpClient::getInstance().getcurPath();
    uint pathSize = curPath.toUtf8().size()+1;
    PDU *pdu = mkPDU(pathSize);
    pdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FILE_REQUEST;
    strncpy((char*)pdu->caMsg,curPath.toUtf8().data(),pathSize);
    TcpClient::getInstance().getTcpSocket()->write((char*)pdu,pdu->uiPDULen);
    free(pdu);
    pdu = NULL;
}

Document &Document::getInstance()
{
    static Document instance;
    return instance;
}

void Document::clearEnterName()
{
    m_EnterDir.clear();
    return;
}

QString Document::getm_enterDir()
{
    return m_EnterDir;
}

void Document::setDownLoadFlag(bool flag)
{
    m_isDownLoad = flag;
}

bool Document::getDownLoad()
{
    return m_isDownLoad;
}

QString Document::getSaveFilePath()
{
    return m_saveFilePath;
}

void Document::on_createdir_pb_clicked()
{
    QString DirName = QInputDialog::getText(this,"新建文件夹","新文件夹名字");
    DirName = DirName.trimmed();
    if(DirName.isNull())
    {
        return;
    }
    else if(DirName.isEmpty())
    {
        QMessageBox::warning(this,"不能为空","名字不能为空！");
        return;
    }



    QString path = TcpClient::getInstance().getcurPath();

    if(DirName.toUtf8().size()>=32)
    {
        QMessageBox::warning(this,"名字过长","文件夹名字过长，建议使用英文");
        return;
    }
    else
    {
        QString loginName = TcpClient::getInstance().getLoginName();
        PDU *pdu = mkPDU(path.toUtf8().size()+1);
        pdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_REQUEST;
        //用户名在caData前32位
        strncpy(pdu->caData,loginName.toStdString().c_str(),loginName.size());
        //文件夹名在caData后32位
        strncpy(pdu->caData+32,DirName.toUtf8().constData(),DirName.toUtf8().size());
        //拷贝路径到caMsg
        memcpy(pdu->caMsg,path.toStdString().c_str(),path.size()+1);
        TcpClient::getInstance().getTcpSocket()->write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = NULL;
    }

}


void Document::on_flushFile_pb_clicked()
{
    // QString curPath = TcpClient::getInstance().getcurPath();
    // uint pathSize = curPath.toUtf8().size()+1;
    // PDU *pdu = mkPDU(pathSize);
    // pdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FILE_REQUEST;
    // strncpy((char*)pdu->caMsg,curPath.toUtf8().data(),pathSize);
    // TcpClient::getInstance().getTcpSocket()->write((char*)pdu,pdu->uiPDULen);
    // free(pdu);
    // pdu = NULL;
    reFreshFileList();
}




void Document::on_deldir_pb_clicked()
{
    QString curPath = TcpClient::getInstance().getcurPath();
    QListWidgetItem *pItem = ui->document_lw->currentItem();
    if(NULL == pItem)
    {
        QMessageBox::warning(this,"删除文件","请选择要删除的文件");
        return;
    }
    else
    {
        int ref = QMessageBox::information(this,"删除文件","确认是否删除文件",QMessageBox::Ok,QMessageBox::No);
        if(ref == QMessageBox::Ok)
        {
            QString delName = pItem->text();
            PDU *pdu = mkPDU(curPath.toUtf8().size()+1);
            pdu->uiMsgType = ENUM_MSG_TYPE_DELETE_FILEDIR_REQUEST;
            strncpy(pdu->caFileName,delName.toUtf8().data(),delName.toUtf8().size());
            memcpy(pdu->caMsg,curPath.toUtf8().data(),curPath.toUtf8().size());
            TcpClient::getInstance().getTcpSocket()->write((char*)pdu,pdu->uiPDULen);
            free(pdu);
            pdu = NULL;
        }
        else
        {
            return;
        }
    }
}


void Document::on_rename_pb_clicked()
{
    QString curPath = TcpClient::getInstance().getcurPath();
    QListWidgetItem *pItem = ui->document_lw->currentItem();
    if(NULL == pItem)
    {
        QMessageBox::warning(this,"重命名文件","请选择要重命名的文件");
        return;
    }
    else
    {
        int ref = QMessageBox::information(this,"重命名文件","确认是否重命名文件",QMessageBox::Ok,QMessageBox::No);
        if(ref == QMessageBox::Ok)
        {
            QString strOldName = pItem->text();
            qDebug()<<"旧名字："<<strOldName;
            QString strNewName = QInputDialog::getText(this,"重命名","请输入新的文件名");
            qDebug()<<"新名字："<<strNewName;
            if(strNewName.trimmed().isEmpty())
            {
                QMessageBox::warning(this,"重命名文件","不能为空");
                return;
            }
            else
            {
                PDU *pdu = mkPDU(curPath.toUtf8().size()+1);
                pdu->uiMsgType = ENUM_MSG_TYPE_RENAME_FILE_REQUEST;
                //旧名字在caFileName
                strncpy(pdu->caFileName,strOldName.toUtf8().data(),strOldName.toUtf8().size());
                //新名字在caFileName+255
                strncpy(pdu->caFileName+255,strNewName.toUtf8().data(),strNewName.toUtf8().size());
                //地址在caMsg
                strncpy((char*)pdu->caMsg,curPath.toUtf8().data(),curPath.toUtf8().size());
                TcpClient::getInstance().getQTcpSocket().write((char*)pdu,pdu->uiPDULen);
                free(pdu);
                pdu = NULL;
            }
        }else
        {
            return;
        }
    }
}

void Document::enterDir(const QModelIndex &index)
{
    QString nameDir = index.data().toString();
    // qDebug()<<nameDir;
    m_EnterDir = nameDir;
    QString curPath = TcpClient::getInstance().getcurPath();
    PDU *pdu = mkPDU(curPath.toUtf8().size()+1);
    pdu->uiMsgType = ENUM_MSG_TYPE_ENTER_FILE_REQUEST;
    //文件名存放在caFileName
    strncpy(pdu->caFileName,nameDir.toUtf8().data(),255);
    //文件路径存放在caMsg
    strncpy((char*)pdu->caMsg,curPath.toUtf8().data(),curPath.toUtf8().size());

    TcpClient::getInstance().getQTcpSocket().write((char*)pdu,pdu->uiPDULen);
    free(pdu);
    pdu = NULL;

}


void Document::on_back_pb_clicked()
{
    QString path = TcpClient::getInstance().getcurPath();
    QString rootPath = "./" + TcpClient::getInstance().getLoginName();
    if(path == rootPath)
    {
        return;
    }
    else
    {
        int index = path.lastIndexOf('/');
        path.remove(index,path.size()-1);
        qDebug()<<path;
        TcpClient::getInstance().setcurPath(path);
        reFreshFileList();

    }


}


void Document::on_upload_pb_clicked()
{
    QString path = TcpClient::getInstance().getcurPath();
    m_UploadFilePath =QFileDialog::getOpenFileName();
    // qDebug()<<uploadFilePath;
    if(!m_UploadFilePath.isEmpty())
    {
        int index = m_UploadFilePath.lastIndexOf('/');
        QString fileName = m_UploadFilePath.right(m_UploadFilePath.size()-index-1);

        qDebug()<<fileName;

        QFile file(m_UploadFilePath);

        qint64 fileSize = file.size();      //文件大小

        PDU *pdu = mkPDU(path.toUtf8().size()+1);
        pdu->uiMsgType = ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST;
        memcpy(pdu->caMsg,path.toUtf8().data(),path.toUtf8().size());
        sprintf(pdu->caFileName,"%s %lld",fileName.toUtf8().data()
                ,fileSize);

        TcpClient::getInstance().getQTcpSocket().write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = NULL;

        m_pTimer->start(1000);
    }
    else
    {
        return;
    }
}

void Document::uploadFiledata()
{
    m_pTimer->stop();
    QFile file(m_UploadFilePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,"上传文件","打开文件失败");
        return;
    }
    char *pBuffer = new char[4096];
    qint64 ret = 0;
    while(true)
    {
        ret = file.read(pBuffer,4096);
        if(ret>0 && ret<=4096)
        {
            TcpClient::getInstance().getTcpSocket()->write(pBuffer,ret);

            // // 等待数据发送完成
            // if(!TcpClient::getInstance().getTcpSocket()->waitForBytesWritten(3000)) // 3秒超时
            // {
            //     QMessageBox::warning(this,"上传文件","发送数据超时");
            //     break;
            // }
        }
        else if(ret == 0)
        {
            break;
        }
        else
        {
            QMessageBox::warning(this,"上传文件","上传文件失败:读取文件失败");
            break;
        }
    }
    file.close();
    delete[]pBuffer;
    pBuffer = NULL;
}


void Document::on_delFile_pb_clicked()
{
    QString path = TcpClient::getInstance().getcurPath();
    QListWidgetItem *pItem = ui->document_lw->currentItem();
    if(NULL == pItem)
    {
        return;
    }
    else
    {
        int ref = QMessageBox::information(this,"删除文件","确认是否删除文件",QMessageBox::Ok,QMessageBox::No);
        if(ref == QMessageBox::Ok)
        {
            QString delName = pItem->text();
            PDU *pdu = mkPDU(path.toUtf8().size()+1);
            pdu->uiMsgType = ENUM_MSG_TYPE_DELETE_FILE_REQUEST;
            strncpy(pdu->caFileName,delName.toUtf8().data(),delName.toUtf8().size());
            memcpy(pdu->caMsg,path.toUtf8().data(),path.toUtf8().size());
            TcpClient::getInstance().getTcpSocket()->write((char*)pdu,pdu->uiPDULen);
            free(pdu);
            pdu = NULL;
        }
        else
        {
            return;
        }
    }

}


void Document::on_download_pb_clicked()
{
    QString path = TcpClient::getInstance().getcurPath();
    QListWidgetItem *pItem = ui->document_lw->currentItem();
    if(pItem == NULL)
    {
        return;
    }
    else
    {
        QString fileName = pItem->text();
        PDU *pdu = mkPDU(path.toUtf8().size()+1);
        pdu->uiMsgType = ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST;
        strncpy(pdu->caFileName,fileName.toUtf8().data(),fileName.toUtf8().size());
        memcpy((char*)pdu->caMsg,path.toUtf8().data(),path.toUtf8().size());

        QString saveFilePath = QFileDialog::getSaveFileName(this,"保存文件",fileName);
        if(saveFilePath.isEmpty())
        {
            QMessageBox::warning(this,"下载文件","请选择有效路径！");
            m_saveFilePath.clear();
            return;
        }
        else
        {
            m_saveFilePath = saveFilePath;
        }
        TcpClient::getInstance().getQTcpSocket().write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = NULL;
    }
}

