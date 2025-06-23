#include "mytcpsocket.h"
#include <QDebug>
#include "mytcpserver.h"
#include <QDir>
#include <QFileInfoList>
#include <QFile>

MyTcpSocket::MyTcpSocket()
{
    connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    connect(this,SIGNAL(disconnected()),this,SLOT(clientOfflinet()));

    m_bUploadt = false;

    m_pTimer = new QTimer;
    connect(m_pTimer,SIGNAL(timeout())
            ,this,SLOT(sendFileToClient()));
}

QString MyTcpSocket::getName()
{
    return user_Name;
}

void MyTcpSocket::recvMsg()
{

    // 检查连接状态（关键修复）
    if(this->state() != QAbstractSocket::ConnectedState) {
        qDebug() << "套接字未连接，跳过处理";
        return;
    }

    if(!m_bUploadt)
    {
        qDebug() <<"bytesAvailable:" <<this->bytesAvailable();
        uint uiPDULen = 0;
        this->read((char*)&uiPDULen,sizeof(uint));
        uint uiMsgLen = uiPDULen - sizeof(PDU);
        PDU *pdu = mkPDU(uiMsgLen);
        this->read((char*)pdu+sizeof(uint),uiPDULen-sizeof(uint));
        // qDebug() << pdu->uiMsgType <<(char*)(pdu->caMsg);
        PDU *respdu = mkPDU(0);

        //判断接收的数据类型
        switch(pdu->uiMsgType)
        {
        case ENUM_MSG_TYPE_REGIST_REQUEST:
        {
            char caName[32] = {'\0'};
            char caPwd[32] = {'\0'};
            strncpy(caName,pdu->caData,32);
            strncpy(caPwd,pdu->caData+32,32);
            qDebug() << caName << caPwd << pdu->uiMsgType;
            bool ret = opeDB::getInstance().handleRegist(caName,caPwd);
            respdu->uiMsgType = ENUM_MSG_TYPE_REGIST_RESPOND;
            if (ret)
            {
                qDebug()<<"ENUM_MSG_TYPE_REGIST_RESPOND:";
                strcpy(respdu->caData,REGIST_OK);
                QDir dir;
                qDebug()<<"create:"<< dir.mkdir(QString("./%1").arg(caName));

            }
            else
            {
                strcpy(respdu->caData,REGIST_FAILED);
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_LOGIN_REQUEST:
        {
            // qDebug() << ENUM_MSG_TYPE_LOGIN_REQUEST;
            char caName[32] = {'\0'};
            char caPwd[32] = {'\0'};
            strncpy(caName,pdu->caData,32);
            strncpy(caPwd,pdu->caData+32,32);
            qDebug() << caName << caPwd << pdu->uiMsgType;
            int ret = opeDB::getInstance().handleLogin(caName,caPwd);
            respdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_RESPOND;
            if(ret == 1)
            {
                //登录成功
                strcpy(respdu->caData,LOGIN_OK);
                user_Name = caName;
                qDebug()<<caName<<LOGIN_OK;
            }else if (ret == 2)
            {
                //当前用户已登录
                strcpy(respdu->caData,LOGIN_ONLINEED);
            }else if (ret == 0)
            {
                //登录失败
                strcpy(respdu->caData,LOGIN_FAILED);
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_LIST_ONLINEUSER_REQUEST:
        {
            // qDebug()<<"查看在线用户！";
            QStringList ret = opeDB::getInstance().handleAllOnlineUser();
            qDebug()<<"当前在线用户数量："<<ret.size();
            uint uiMsgLen = ret.size()*32;
            PDU *respdu = mkPDU(uiMsgLen);
            respdu->uiMsgType = ENUM_MSG_TYPE_LIST_ONLINEUSER_RESPOND;
            for(int i = 0;i<ret.size();i++)
            {
                memcpy((char*)(respdu->caMsg)+i*32
                       ,ret.at(i).toStdString().c_str()
                       ,ret.at(i).size());
                // qDebug()<<"循环执行："<<i+1<<"次";
            }
            write((char*)respdu,respdu->uiPDULen);
            qDebug()<<"回复信息大小："<<uiMsgLen;
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_SEARCH_USER_REQUEST:
        {
            int ret = opeDB::getInstance().handSearchUser(pdu->caData);
            PDU *respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_SEARCH_USER_RESPOND;
            if(ret == 0)
            {
                qDebug()<<"---用户:"<<pdu->caData<<" 离线！---";
                strcpy(respdu->caData,SEARCH_USER_NOT_ONLINE);
            }else if(ret == 1)
            {
                qDebug()<<"用户:"<<pdu->caData<<" 在线！";
                strcpy(respdu->caData,SEARCH_USER_ONLINE);
            }else if(ret == -1)
            {
                qDebug()<<SEARCH_USER_NO_SUCH_USER;
                strcpy(respdu->caData,SEARCH_USER_NO_SUCH_USER);
            }
            else if(ret == -2)
            {
                qDebug()<<SEARCH_USER_NULL;
                strcpy(respdu->caData,SEARCH_USER_NULL);
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_ADD_FRIEND_REQUEST:
        {
            QString LoginName,name;
            LoginName = pdu->caData;
            name = pdu->caData+32;
            int ret = opeDB::getInstance().handAddFirend(LoginName.toStdString().c_str()
                                               ,name.toStdString().c_str());
            PDU *respdu;
            respdu=mkPDU(0);

            qDebug()<<"ENUM_MSG_TYPE_ADD_FRIEND_REQUEST:";
            qDebug()<<"请求方Name:"<<LoginName;
            qDebug()<<"被请求方Name:"<<name;
            qDebug()<<"向被请求方发送好友请求";

            respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_RESPOND;
            if(ret == 0)
            {
                //用户不在线
                qDebug()<<"用户不在线";
                strcpy(respdu->caData,"用户不在线");
            }
            else if(ret == 1)
            {
                //用户在线
                Mytcpserver::getInstance().resend(name.toStdString().c_str(),pdu);
            }
            else if(ret == 2)
            {
                //好有已存在
                qDebug()<<"好友已存在!!";
                strcpy(respdu->caData,"好友已存在");
            }
            else if(ret == -2)
            {
                qDebug()<<"无法添加自己为好友";
                strcpy(respdu->caData,"无法添加自己为好友");
            }
            else if(ret == -1)
            {
                //不存在
                strcpy(respdu->caData,"用户不存在！");
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_ADD_FRIEND_YES:
        {
            // 请求方
            QString loginUserName = pdu->caData;
            // 被请求方
            QString name = pdu->caData+32;

            qDebug()<<"ENUM_MSG_TYPE_ADD_FRIEND_YES:";
            qDebug()<<"请求方："<<loginUserName;
            qDebug()<<"被请求方："<<name;
            if(opeDB::getInstance().handAddFirendYes(loginUserName.toStdString().c_str()
                                                      ,name.toStdString().c_str()))
            {
                qDebug()<<"添加成功！";
            }
            else
            {
                qDebug()<<"添加失败！";
            }
            break;
        }
        case ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST:
        {
            char caName[32] = {'\0'};
            strncpy(caName,pdu->caData,32);
            QStringList FriendList = opeDB::getInstance().
                                     handleFlushFriend(caName);
            uint uiMsgLen = FriendList.size()*32;
            PDU *respdu = mkPDU(uiMsgLen);
            respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND;

            for(int i = 0;i<FriendList.size();i++)
            {
                memcpy((char*)(respdu->caMsg)+i*32
                       ,FriendList.at(i).toStdString().c_str()
                       ,FriendList.at(i).size());
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_DEL_FRIEND_REQUEST:
        {
            qDebug()<<"ENUM_MSG_TYPE_DEL_FRIEND_REQUEST";
            char loginName[32] = {'\0'};
            char caName[32] = {'\0'};
            memcpy(loginName,pdu->caData,32);
            memcpy(caName,pdu->caData+32,32);
            qDebug()<<loginName;
            qDebug()<<caName;

            int ref = opeDB::getInstance().handDelFriend(loginName,caName);
            if(ref == 1)
            {
                qDebug()<<"删除成功！";
                QStringList FriendList = opeDB::getInstance().handleFlushFriend(loginName);
                uint uiMsgLen = FriendList.size()*32;
                PDU *respdu = mkPDU(uiMsgLen);
                respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND;
                qDebug()<<"发送ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND！";
                for(int i = 0;i<FriendList.size();i++)
                {
                    memcpy((char*)(respdu->caMsg)+i*32
                           ,FriendList.at(i).toStdString().c_str()
                           ,FriendList.at(i).size());
                }
                write((char*)respdu,respdu->uiPDULen);
                free(respdu);
                respdu = NULL;
            }
            else
            {
                qDebug()<<"删除失败！";
            }
            break;
        }
        case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:
        {
            qDebug()<<"ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:";
            char loginName[32],chatName[32];
            memcpy(loginName,pdu->caData,32);
            memcpy(chatName,pdu->caData+32,32);
            qDebug()<<loginName;
            qDebug()<<chatName;
            qDebug()<<(char*)pdu->caMsg;

            Mytcpserver::getInstance().resend(chatName,pdu);
            break;
        }
        case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
        {
            qDebug()<<"ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:";
            char name[32];
            strncpy(name,pdu->caData,32);
            qDebug()<<(char*)pdu->caMsg;
            QStringList onlineUser = opeDB::getInstance().handleAllOnlineUser();
            QString temp;
            for(int i = 0;i<onlineUser.size();i++)
            {
                temp = onlineUser.at(i);
                Mytcpserver::getInstance().resend(temp.toStdString().c_str(),pdu);
            }
            break;
        }
        case ENUM_MSG_TYPE_CREATE_DIR_REQUEST:
        {
            QDir dir;
            QString path = QString("%1").arg((char*)pdu->caMsg);
            bool ret =dir.exists(path);
            qDebug()<<(char*)pdu->caMsg;
            PDU *respdu = NULL;
            if(ret)
            {
                qDebug()<<"当前目录存在";
                char newDir[32];
                memcpy(newDir,pdu->caData+32,32);
                QString newPath = path+"/"+newDir;

                qDebug()<< newPath;

                ret = dir.exists(newPath);

                if(ret)
                {
                    respdu = mkPDU(0);
                    respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
                    strcpy(respdu->caData,"文件存在");
                    qDebug()<<"当前目录存在";
                }
                else
                {
                    QDir parentDir(path);
                    parentDir.mkdir(QString(newDir));
                    respdu = mkPDU(0);
                    respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
                    strcpy(respdu->caData,"文件夹创建成功");
                }
            }
            else
            {
                qDebug()<<"当前目录不存在";
                respdu = mkPDU(0);
                respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
                strcpy(respdu->caData,"失败");
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_FLUSH_FILE_REQUEST:
        {
            qDebug()<<"ENUM_MSG_TYPE_FLUSH_FILE_REQUEST:";
            char *pCurPath = new char[pdu->uiMsgLen];
            memcpy(pCurPath,pdu->caMsg,pdu->uiMsgLen);
            QDir dir(pCurPath);
            QFileInfoList fileList = dir.entryInfoList();
            int iFileCount = fileList.size();
            PDU * respdu = mkPDU(sizeof(FileInfo)*(iFileCount-2));

            respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FILE_RESPOND;

            qDebug()<<(char*)pCurPath;

            FileInfo *pFileInfo = NULL;
            QString tempFileName;
            int fileIndex = 0;
            for(int i = 0;i<iFileCount;i++)
            {
                if(QString(".")==fileList[i].fileName()||
                    QString("..")==fileList[i].fileName())
                {
                    continue;
                }
                pFileInfo = (FileInfo*)respdu->caMsg+fileIndex;
                tempFileName = fileList[i].fileName();
                memset(pFileInfo->caFileName, 0, sizeof(pFileInfo->caFileName));
                memcpy(pFileInfo->caFileName,tempFileName.toUtf8().data(),tempFileName.toUtf8().size());
                if(fileList[i].isDir())
                {
                    //表示是一个文件夹
                    pFileInfo->iFileType = 0;
                }else if(fileList[i].isFile())
                {
                    //表示是一个常规文件
                    pFileInfo->iFileType = 1;
                }
                fileIndex++;
                // qDebug()<< fileList[i].fileName()
                //         <<fileList[i].size()
                //          //判断是否为文件夹
                //          <<" 文件夹："<<fileList[i].isDir()
                //          //判断是否为常规文件
                //          <<" 常规文件："<<fileList[i].isFile();
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);

            // 修复内存泄漏
            delete[] pCurPath;
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_DELETE_FILEDIR_REQUEST:
        {
            qDebug()<<"ENUM_MSG_TYPE_DELETE_FILEDIR_REQUEST：";
            char caName[255] = {'\0'};
            strcpy(caName,pdu->caFileName);
            char *pPath = new char[pdu->uiMsgLen];
            memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);
            QString path = QString("%1/%2").arg(pPath).arg(caName);
            qDebug()<<path;
            QFileInfo fileInfo(path);
            bool ret = false;
            if(fileInfo.isDir())
            {
                QDir dir;
                dir.setPath(path);
                ret = dir.removeRecursively();
            }
            else if(fileInfo.isFile())
            {
                ret = false;
            }
            PDU *respdu = NULL;
            if(ret)
            {
                QString msg = "删除成功！";
                respdu = mkPDU(msg.toUtf8().size()+1);
                memcpy(respdu->caMsg,msg.toUtf8().data(),msg.toUtf8().size());
                respdu->uiMsgType = ENUM_MSG_TYPE_DELETE_FILEDIR_RESPOND;
            }
            else
            {
                QString msg = "删除失败！";
                respdu = mkPDU(msg.toUtf8().size()+1);
                memcpy(respdu->caMsg,msg.toUtf8().data(),msg.toUtf8().size());
                respdu->uiMsgType = ENUM_MSG_TYPE_DELETE_FILEDIR_RESPOND;
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_RENAME_FILE_REQUEST:
        {
            char caOldName[255];
            char caNewName[255];
            strncpy(caOldName,pdu->caFileName,255);
            strncpy(caNewName,(char*)pdu->caFileName+255,255);
            char *pPath = new char[pdu->uiMsgLen];
            memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);

            qDebug()<<"旧名字："<<caOldName;
            qDebug()<<"新名字："<<caNewName;

            QString oldPath = QString("%1/%2").arg(pPath).arg(caOldName);
            QString newPath = QString("%1/%2").arg(pPath).arg(caNewName);

            qDebug()<<"旧路径："<<oldPath;
            qDebug()<<"新路径："<<newPath;

            QDir dir;
            bool ret = dir.rename(oldPath,newPath);
            PDU *respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_RENAME_FILE_RESPOND;
            if(!ret)
            {
                strcpy(respdu->caData,"重命名失败!");
            }else
            {
                strcpy(respdu->caData,"重命名成功!");
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_ENTER_FILE_REQUEST:
        {
            char enterDir[255];
            strncpy(enterDir,pdu->caFileName,255);

            char *pPath = new char[pdu->uiMsgLen];
            memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);

            QString Path = QString("%1/%2").arg(pPath).arg(enterDir);

            qDebug()<<Path;
            QFileInfo fileinfo(Path);

            PDU *respdu = NULL;

            if(fileinfo.isDir())
            {
                QDir dir(Path);
                QFileInfoList fileList = dir.entryInfoList();
                int iFileCount = fileList.size();
                respdu = mkPDU(sizeof(FileInfo)*(iFileCount-2));

                respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FILE_RESPOND;

                FileInfo *pFileInfo = NULL;
                QString tempFileName;
                int fileIndex = 0;
                for(int i = 0;i<iFileCount;i++)
                {
                    if(QString(".")==fileList[i].fileName()||
                        QString("..")==fileList[i].fileName())
                    {
                        continue;
                    }
                    pFileInfo = (FileInfo*)respdu->caMsg+fileIndex;
                    tempFileName = fileList[i].fileName();
                    memset(pFileInfo->caFileName, 0, sizeof(pFileInfo->caFileName));
                    memcpy(pFileInfo->caFileName,tempFileName.toUtf8().data(),tempFileName.toUtf8().size());
                    if(fileList[i].isDir())
                    {
                        //表示是一个文件夹
                        pFileInfo->iFileType = 0;
                    }else if(fileList[i].isFile())
                    {
                        //表示是一个常规文件
                        pFileInfo->iFileType = 1;
                    }
                    fileIndex++;
                }
                write((char*)respdu,respdu->uiPDULen);
                free(respdu);

                // 修复内存泄漏
                // delete[] pCurPath;
                respdu = NULL;

            }
            else if(fileinfo.isFile())
            {
                respdu = mkPDU(0);
                respdu->uiMsgType = ENUM_MSG_TYPE_ENTER_FILE_RESPOND;
                strcpy(respdu->caData,"打开文件夹失败");
                write((char*)respdu,respdu->uiPDULen);
                free(respdu);
                respdu = NULL;
            }
            break;
        }
        case ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST:
        {
            qDebug()<<"ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST:";
            char fileName[255];
            qint64 fileSize = 0;
            sscanf(pdu->caFileName,"%s  %lld",fileName, &fileSize);
            char *pPath = new char[pdu->uiMsgLen];
            memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);
            QString path = QString("%1/%2").arg(pPath).arg(fileName);
            qDebug()<<path;
            delete []pPath;
            pPath = NULL;

            m_file.setFileName(path);
            //只写的方式打开文件，文件若是不存在，则会自动创建文件
            if(m_file.open(QIODevice::WriteOnly))
            {
                m_bUploadt = true;
                m_iTotal = fileSize;
                m_iRecved = 0;
            }
            break;
        }
        case ENUM_MSG_TYPE_DELETE_FILE_REQUEST:
        {
            qDebug()<<"ENUM_MSG_TYPE_DELETE_FILE_REQUEST：";
            char caName[255] = {'\0'};
            strcpy(caName,pdu->caFileName);
            qDebug()<<caName;
            char *pPath = new char[pdu->uiMsgLen];
            memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);
            QString path = QString("%1/%2").arg(pPath).arg(caName);
            qDebug()<<path;
            QFileInfo fileInfo(path);
            bool ret = false;
            if(fileInfo.isFile())
            {
                QFile file(path);
                ret = file.remove();
            }
            else if(fileInfo.isDir())
            {
                ret = false;
            }
            PDU *respdu = NULL;
            if(ret)
            {
                QString msg = "删除成功！";
                respdu = mkPDU(msg.toUtf8().size()+1);
                memcpy(respdu->caMsg,msg.toUtf8().data(),msg.toUtf8().size());
                respdu->uiMsgType = ENUM_MSG_TYPE_DELETE_FILE_RESPOND;
            }
            else
            {
                QString msg = "删除失败！";
                respdu = mkPDU(msg.toUtf8().size()+1);
                memcpy(respdu->caMsg,msg.toUtf8().data(),msg.toUtf8().size());
                respdu->uiMsgType = ENUM_MSG_TYPE_DELETE_FILE_RESPOND;
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
            break;
        }
        case ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST:
        {
            qDebug()<<"ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST:";
            char caFileName[255];
            strcpy(caFileName,pdu->caFileName);
            char *pPath = new char[pdu->uiMsgLen];
            memcpy(pPath,pdu->caMsg,pdu->uiMsgLen);
            QString Path = QString("%1/%2").arg(pPath).arg(caFileName);
            qDebug()<<Path;
            delete []pPath;
            pPath = NULL;

            QFileInfo fileInfo(Path);
            qint64 fileSize = fileInfo.size();
            PDU *respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_DOWNLOAD_FILE_RESPOND;
            sprintf(respdu->caFileName,"%s %lld",caFileName,fileSize);

            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;

            m_file.setFileName(Path);
            m_file.open(QIODevice::ReadOnly);
            m_pTimer->start(1000);

            break;
        }
        default:
            break;
        }
        free(pdu);
        pdu = NULL;
    }
    else
    {
        QByteArray buff = readAll();
        m_file.write(buff);
        m_iRecved += buff.size();
        if(m_iRecved >= m_iTotal)
        {
            m_file.close();
            m_bUploadt = false;
            PDU *respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_UPLOAD_FILE_RESPOND;

            if(m_iRecved == m_iTotal)
            {
                strcpy(respdu->caData,"上传成功！");
                qDebug()<<"上传成功！文件大小:" << m_iTotal;
            }
            else
            {
                strcpy(respdu->caData,"上传失败！");
                qDebug()<<"上传失败！接收数据大小不匹配";
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = NULL;
        }
    }
}

void MyTcpSocket::clientOfflinet()
{
    if(user_Name.isEmpty()||user_Name == "")
    {
        qDebug()<<"当前无用户登录！";
        return;
    }else
    {
        opeDB::getInstance().handleOffline(user_Name.toStdString().c_str());
        emit offline(this);
    }

}

void MyTcpSocket::sendFileToClient()
{
    char *pData = new char[4096];
    qint64 ret = 0;
    while(true)
    {
        ret = m_file.read(pData,4096);
        if(ret >0 && ret <= 4096)
        {
            write(pData,ret);
        }
        else if(0==ret)
        {
            m_file.close();
            m_pTimer->stop();
            qDebug()<<"下载成功！";
            break;
        }
        else if(ret < 0)
        {
            qDebug()<<"发送文件内容给客户端过程中失败";
            m_pTimer->stop();
            m_file.close();
            break;
        }
    }
    delete [] pData;
    pData = NULL;
}
