#include "tcpclient.h"
#include "./ui_tcpclient.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "privatechat.h"
#include "document.h"
#include <QWidget>


TcpClient::TcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TcpClient)
{

    ui->setupUi(this);
    // m_pSW = new QStackedWidget(this);
    ui->stackedWidget->addWidget(ui->page0);
    ui->stackedWidget->addWidget(ui->page1);

    // ui->stackedWidget->setCurrentWidget(0);
    setWindowFlags(Qt::FramelessWindowHint);     //无边框
    setAttribute(Qt::WA_TranslucentBackground, false);




    // resize(500,300);

    //加载配置文件
    loadConfig();

    connect(&m_tcpsocket,SIGNAL(connected()),this,SLOT(showConnect()));

    //处理服务器返回的Msg
    connect(&m_tcpsocket,SIGNAL(readyRead()),this,SLOT(recvMsg()));

    //连接服务器
    m_tcpsocket.connectToHost(QHostAddress(m_strIP),m_usPort);
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::loadConfig()
{

    // QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    // db.setHostName("localhost");
    // db.setUserName("root");
    // db.setPassword("123456");
    // db.setDatabaseName("my_wp");

    // if(!db.open())
    // {
    //     // QMessageBox::warning(this,"警告",db.lastError().text());
    //     qDebug() << "数据库连接失败:" << db.lastError();

    //     return;
    // }else
    // {
    //     // QMessageBox::information(this,"数据库","数据库连接成功");
    //     qDebug() << "数据库连接成功!";
    // }

    // QSqlQuery qu;
    // qu.exec("show tables");
    // while(qu.next())
    // {
    //     QString strtable = qu.value(0).toString();
    //     qDebug() << strtable ;
    // }


    QFile file(":/client.config");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray baData =  file.readAll();
        QString strData = baData.toStdString().c_str();
        file.close();

        strData.replace("\r\n"," ");

        QStringList strList = strData.split(" ");

        m_strIP = strList.at(0);
        m_usPort = strList.at(1).toUShort();
        qDebug() << "ip:" << m_strIP << " port:" << m_usPort;
    }
    else
    {
        QMessageBox::critical(this,"打开配置文件","打开失败");
    }
}

QTcpSocket *TcpClient::getTcpSocket()
{
    return &m_tcpsocket;
}

QString TcpClient::getm_strIP()
{
    return m_strIP;
}

quint16 TcpClient::getm_usPort()
{
    return m_usPort;
}

TcpClient &TcpClient::getInstance()
{
    static TcpClient instance;
    return instance;
}

QTcpSocket &TcpClient::getQTcpSocket()
{
    return m_tcpsocket;
}

QString &TcpClient::getLoginName()
{
    return m_loginUserName;
}

QString TcpClient::getcurPath()
{
    return m_strCurPath;
}

void TcpClient::setcurPath(QString curPath)
{
    m_strCurPath = curPath;
}


void TcpClient::showConnect()
{
    QMessageBox::information(this,"连接服务器","连接服务器成功");
}

void TcpClient::recvMsg()
{
    if(!OpeWidget::getInstance().getDocument()->getDownLoad())
    {
    qDebug() <<"bytesAvailable:" <<m_tcpsocket.bytesAvailable();
    uint uiPDULen = 0;
    m_tcpsocket.read((char*)&uiPDULen,sizeof(uint));
    uint uiMsgLen = uiPDULen - sizeof(PDU);
    PDU *pdu = mkPDU(uiMsgLen);
    m_tcpsocket.read((char*)pdu+sizeof(uint),uiPDULen-sizeof(uint));
    // qDebug() << pdu->uiMsgType <<(char*)(pdu->caMsg);
    PDU *respdu = mkPDU(0);
    //判断接收的数据类型
    switch(pdu->uiMsgType)
    {
    case ENUM_MSG_TYPE_REGIST_RESPOND:
    {
        if (0 == strcmp(pdu->caData,REGIST_OK))
        {
            QMessageBox::information(this,"注册",REGIST_OK);
            ui->regist_name_le->clear();
            ui->regist_pwd_le->clear();
            ui->stackedWidget->setCurrentIndex(0);

        }else if(0 == strcmp(pdu->caData,REGIST_FAILED))
        {
            QMessageBox::warning(this,"注册",REGIST_FAILED);
        }
        break;
    }
    case ENUM_MSG_TYPE_LOGIN_RESPOND:
    {
        if(0 == strcmp(pdu->caData,LOGIN_OK))
        {
            m_strCurPath = QString("./%1").arg(m_loginUserName);
            qDebug()<<m_strCurPath;
            QMessageBox::information(this,"登录",LOGIN_OK);
            OpeWidget::getInstance().show();
            this->hide();
            //刷新好友
            OpeWidget::getInstance().getFriend()->flushFriend();
        }
        else if(0 == strcmp(pdu->caData,LOGIN_ONLINEED))
        {
            QMessageBox::warning(this,"登录",LOGIN_ONLINEED);
        }
        else if(0 == strcmp(pdu->caData,LOGIN_FAILED))
        {
            QMessageBox::warning(this,"登录",LOGIN_FAILED);
        }
        break;
    }
    case ENUM_MSG_TYPE_LIST_ONLINEUSER_RESPOND:
    {
        OpeWidget::getInstance().getFriend()->showAllOnlineUser(pdu);
        qDebug()<<"------ENUM_MSG_TYPE_LIST_ONLINEUSER_RESPOND uiMsgLen:"<<pdu->uiMsgLen;
        break;
    }
    case ENUM_MSG_TYPE_SEARCH_USER_RESPOND:
    {
        QString sName = OpeWidget::getInstance().getFriend()->m_strSearchName;
        if(0 == strcmp(pdu->caData,SEARCH_USER_ONLINE))
        {
            QMessageBox::information(this,"用户在线",QString("用户：%1 在线！").arg(sName));
            //用户在线！
        }else if(0 == strcmp(pdu->caData,SEARCH_USER_NOT_ONLINE))
        {
            QMessageBox::information(this,"用户离线",QString("用户：%1 离线！").arg(sName));
            //用户离线！
        }else if(0 == strcmp(pdu->caData,SEARCH_USER_NO_SUCH_USER))
        {
            QMessageBox::information(this,"用户不存在",QString("用户：%1 不存在！").arg(sName));
            //！！用户不存在！
        }else if(0 == strcmp(pdu->caData,SEARCH_USER_NULL))
        {
            QMessageBox::information(this,"用户名为空",SEARCH_USER_NULL);
            //用户为空无法查询！
        }
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_REQUEST:
    {
        // 被请求方
        char caName[32] = {'\0'};
        // 请求方
        char MySelf[32] = {'\0'};
        strncpy(caName,pdu->caData+32,32);
        strncpy(MySelf,pdu->caData,32);

        qDebug()<<"ENUM_MSG_TYPE_ADD_FRIEND_REQUEST:";
        qDebug()<<"请求方："<<pdu->caData;
        qDebug()<<"被请求方："<<pdu->caData+32;
        qDebug()<<"-------------------------------";
        qDebug()<<"请求方："<<pdu->caData;
        qDebug()<<"被请求方："<<pdu->caData+32;

        int ret = QMessageBox::information(this,"添加好友"
                                 ,QString("%1 想添加您为好友").arg(MySelf)
                                 ,QMessageBox::Yes,QMessageBox::No);
        PDU *respdu = mkPDU(0);
        strncpy(respdu->caData,MySelf,32);          // 请求方在前32位
        strncpy(respdu->caData+32,caName,32);       // 被请求放在后32位置
        memcpy(respdu->caData,MySelf,32);
        if(ret == QMessageBox::Yes)
        {
            respdu->uiMsgType=ENUM_MSG_TYPE_ADD_FRIEND_YES;
        }
        else
        {
            respdu->uiMsgType=ENUM_MSG_TYPE_ADD_FRIEND_NO;
        }
        m_tcpsocket.write((char*)respdu,respdu->uiPDULen);
        free(respdu);
        respdu = NULL;
        break;
    }
    case ENUM_MSG_TYPE_ADD_FRIEND_RESPOND:
    {
        // if(0 == strcmp(pdu->caData,"添加成功"))
        // {
        //     QMessageBox::information(this,"添加好友","添加成功");
        // }
        // QMessageBox::information(this,"添加好友",pdu->caData);
        if(0 == strcmp(pdu->caData,"无法添加自己为好友"))
        {
            QMessageBox::information(this,"添加失败","无法添加自己为好友");
        }
        else if(0 == strcmp(pdu->caData,"好友已存在"))
        {
            QMessageBox::information(this,"添加好友","好友已存在");
        }
    }
    case ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND:
    {
        qDebug()<<"ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND:";
        OpeWidget::getInstance().getFriend()->updataFriendList(pdu);
        break;
    }
    case ENUM_MSG_TYPE_DEL_FRIEND_RESPOND:
    {
        qDebug()<<"ENUM_MSG_TYPE_DEL_FRIEND_RESPOND:";
        OpeWidget::getInstance().getFriend()->updataFriendList(pdu);
        break;
    }
    case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:
    {
        if(privateChat::getInstance().isHidden())
        {
            privateChat::getInstance().show();
        }
        QString chatName = (char*)pdu->caData;
        privateChat::getInstance().setChatName(chatName);
        privateChat::getInstance().updataMsg(pdu);
        break;
    }
    case ENUM_MSG_TYPE_PRIVATE_CHAT_RESPOND:
    {
        // QMessageBox::information(this,"对方离线","对方目前处于离线状态");
        break;
    }
    case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
    {
        OpeWidget::getInstance().getFriend()->updataGroupMsg(pdu);
        break;
    }
    case ENUM_MSG_TYPE_FLUSH_FILE_RESPOND:
    {
        OpeWidget::getInstance().getDocument()->updateFileList(pdu);
        QString enterDir = OpeWidget::getInstance().getDocument()->getm_enterDir();
        if(!enterDir.isEmpty())
        {
            m_strCurPath = m_strCurPath + "/" + enterDir;
            qDebug()<<m_strCurPath;
            OpeWidget::getInstance().getDocument()->clearEnterName();
        }
        break;
    }
    case ENUM_MSG_TYPE_CREATE_DIR_RESPOND:
    {
        QMessageBox::information(this,"创建文件",pdu->caData);
        OpeWidget::getInstance().getDocument()->reFreshFileList();
        break;
    }
    case ENUM_MSG_TYPE_DELETE_FILEDIR_RESPOND:
    {
        QMessageBox::information(this,"删除文件夹",(char*)pdu->caMsg);
        OpeWidget::getInstance().getDocument()->reFreshFileList();
        break;
    }
    case ENUM_MSG_TYPE_RENAME_FILE_RESPOND:
    {
        QMessageBox::information(this,"重命名",(char*)pdu->caData);
        OpeWidget::getInstance().getDocument()->reFreshFileList();
        break;
    }
    case ENUM_MSG_TYPE_ENTER_FILE_RESPOND:
    {
        OpeWidget::getInstance().getDocument()->clearEnterName();
        QMessageBox::information(this,"进入文件夹",pdu->caData);
        break;
    }
    case ENUM_MSG_TYPE_UPLOAD_FILE_RESPOND:
    {
        QMessageBox::information(this,"上传文件",pdu->caData);
        OpeWidget::getInstance().getDocument()->reFreshFileList();
        break;
    }
    case ENUM_MSG_TYPE_DELETE_FILE_RESPOND:
    {
        QMessageBox::information(this,"删除文件",(char*)pdu->caMsg);
        OpeWidget::getInstance().getDocument()->reFreshFileList();
        break;
    }
    case ENUM_MSG_TYPE_DOWNLOAD_FILE_RESPOND:
    {
        // qDebug()<<pdu->caFileName;
        char caFileName[255];
        sscanf(pdu->caFileName,"%s %lld",caFileName,&(OpeWidget::getInstance().getDocument()->m_iTotal));
        if(strlen(caFileName)>0 && OpeWidget::getInstance().getDocument()->m_iTotal>0)
        {
            OpeWidget::getInstance().getDocument()->setDownLoadFlag(true);
            QString path = OpeWidget::getInstance().getDocument()->getSaveFilePath();
            m_file.setFileName(path);
            if(!m_file.open(QIODevice::WriteOnly))
            {
                QMessageBox::warning(this,"下载文件","获得保存文件路径失败!");
                return;
            }

        }
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
        QByteArray buffer = m_tcpsocket.readAll();
        m_file.write(buffer);
        Document *d = OpeWidget::getInstance().getDocument();
        d->m_iRecved += buffer.size();
        if(d->m_iTotal == d->m_iRecved)
        {
            m_file.close();
            d->m_iTotal = 0;
            d->m_iRecved = 0;
            d->setDownLoadFlag(false);
        }
        else if(d->m_iTotal<d->m_iRecved)
        {
            m_file.close();
            d->m_iTotal = 0;
            d->m_iRecved = 0;
            d->setDownLoadFlag(false);

            QMessageBox::critical(this,"下载文件","下载失败");
        }
    }
}
#if 0
void TcpClient::on_send_pb_clicked()
{
    QString strMsg = ui->lineEdit->text();
    if(!strMsg.isEmpty())
    {
        PDU *pdu = mkPDU(strMsg.toUtf8().size()+1);
        pdu->uiMsgType = 8080;
        memcpy(pdu->caMsg,strMsg.toStdString().c_str(),strMsg.toUtf8().size()+1);
        m_tcpsocket.write((char*)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = NULL;
    }
    else
    {
        QMessageBox::warning(this,"信息发送","发送的信息不能为空");
    }
}
#endif

void TcpClient::on_login_pb_clicked()
{
    QString strName = ui->name_le->text();
    QString strPwd = ui->pwd_le->text();
    if(!strName.isEmpty() && !strPwd.isEmpty())
    {
        m_loginUserName = strName;
        PDU*pdu = mkPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_REQUEST;
        strncpy(pdu->caData,strName.toStdString().c_str(),32);
        strncpy(pdu->caData+32,strPwd.toStdString().c_str(),32);
        m_tcpsocket.write((char*)pdu,pdu->uiPDULen);    //发送PDU
        free(pdu);
        pdu = NULL;
    }
    else
    {
        QMessageBox::critical(this,"登录","登录失败：用户名或密码为空！");
    }
}


void TcpClient::on_regist_pb_clicked()
{
    QString strName = ui->regist_name_le->text();
    QString strPwd = ui->regist_pwd_le->text();
    if(!strName.isEmpty() && !strPwd.isEmpty())
    {
        PDU*pdu = mkPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_REGIST_REQUEST;
        strncpy(pdu->caData,strName.toStdString().c_str(),32);
        strncpy(pdu->caData+32,strPwd.toStdString().c_str(),32);
        m_tcpsocket.write((char*)pdu,pdu->uiPDULen);    //发送PDU
        free(pdu);
        pdu = NULL;
    }
    else
    {
        QMessageBox::critical(this,"注册","注册失败：用户名或密码为空！");
    }
    // this->hide();
    // regist.show();
    // regist.exec();
    // this->show();
}

void TcpClient::on_go_regist_pb_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void TcpClient::on_back_pb_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
// 鼠标按下事件 - 开始拖拽
void TcpClient::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bDragging = true;
        m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}
// 鼠标移动事件 - 拖拽窗口
void TcpClient::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && m_bDragging && !m_bMaximized) {
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}
// 鼠标释放事件 - 结束拖拽
void TcpClient::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_bDragging = false;
        event->accept();
    }
}






void TcpClient::on_hide_pb_clicked()
{
    // TcpClient::getInstance().close();
    TcpClient::getInstance().showMinimized(); //最小化窗口
}

void TcpClient::on_close_pb_clicked()
{
    // TcpClient::getInstance().close();
    TcpClient::getInstance().close(); //关闭程序
}

