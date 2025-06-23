#include "opedb.h"
#include <QMessageBox>
#include <QSqlRecord>

opeDB::opeDB(QObject *parent)
    : QObject{parent}
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
}

opeDB &opeDB::getInstance()
{
    static opeDB instance;
    return instance;
}

void opeDB::init()
{

    m_db.setHostName("localhost");
    m_db.setUserName("root");
    m_db.setPassword("123456");
    m_db.setDatabaseName("my_wp");

    if(!m_db.open())
    {
        // QMessageBox::warning(this,"警告",db.lastError().text());
        QMessageBox::critical(NULL,"打开数据库","打开数据库失败");
        qDebug() << "数据库连接失败:" << m_db.lastError();

        return;
    }else
    {
        QMessageBox::information(nullptr,"数据库","数据库连接成功");
        qDebug() << "数据库连接成功!";

        //测试能否操作数据库

        // QSqlQuery qu;
        // qu.exec("SELECT * FROM `user`");
        // while(qu.next())
        // {
        //     int count = qu.record().count();
        //     for(int i = 0;i<count;i++)
        //     {
        //         QString strtable = qu.value(i).toString();
        //         qDebug() << strtable ;
        //     }
        // }
    }
}

opeDB::~opeDB()
{
    m_db.close();
    qDebug()<<"数据库关闭";
}

bool opeDB::handleRegist(const char *name, const char *pwd)
{
    if(NULL == name || NULL == pwd)
    {
        qDebug() << "用户名或者密码为空";
        return false;
    }
    QString data = QString("insert into user(name,pwd) values('%1','%2')").arg(name).arg(pwd);

    //打印sql语句
    // qDebug() << data;
    QSqlQuery qu;
    return qu.exec(data);
}

int opeDB::handleLogin(const char *name, const char *pwd)
{
    if(NULL == name || NULL == pwd)
    {
        qDebug() << "用户名或者密码为空";
        return false;
    }
    QString data = QString("SELECT * FROM user WHERE name='%1' and pwd='%2'").arg(name).arg(pwd);
    QSqlQuery qu;
    qu.exec(data);
    if(!qu.next())
    {
        //表示查询失败，密码错误或者用户名不存在
        return 0;
    }
    else
    {
        //获取登录状态
        int online = qu.value(3).toInt();
        qDebug() <<online;
        if(online == 0)
        {
            QString data = QString("UPDATE user set online = 1 WHERE name = '%1'").arg(name);
            qu.exec(data);
            // qDebug()<<"登录状态成功！";
            return 1;
        }else if (online == 1)
        {
            //表示当前用户已经登录
            return 2;
        }
    }
}

void opeDB::handleOffline(const char *name)
{
    if(NULL == name)
    {
        qDebug()<<"name is NULL";
        return;
    }
    QSqlQuery qu;
    QString data = QString("UPDATE user set online = 0 WHERE name = '%1'").arg(name);
    qu.exec(data);
    qDebug()<<"用户下线:"<<name;
}

int opeDB::handSearchUser(const char *name)
{
    if(NULL == name)
    {
        //用户名为空
        return -2;
    }
    QSqlQuery qu;
    QString data = QString("SELECT name,online from user where name = '%1'").arg(name);
    qu.exec(data);
    if(!qu.next())
    {
        //qDebug()<<"用户不存在";
        return -1;
    }
    else
    {
        int ret = qu.value(1).toInt();
        if(ret==0)
        {
            //qDebug()<<name<<": "<<ret<<"用户离线";
            return 0;
        }
        else
        {
            //qDebug()<<name<<": "<<ret<<"用户在线";
            return 1;
        }
    }
}



QStringList opeDB::handleAllOnlineUser()
{
    QString data = QString("select name from user where online = 1");
    QSqlQuery qu;
    qu.exec(data);
    QStringList onlineUser;
    QString tempUser;
    onlineUser.clear();
    if(!qu.next())
    {
        qDebug()<<"当前无用户在线";
        return onlineUser;
    }
    tempUser = qu.value(0).toString();
    onlineUser.append(tempUser);
    while(qu.next())
    {
        tempUser = qu.value(0).toString();
        onlineUser.append(tempUser);
    }
    return onlineUser;
}

int opeDB::handAddFirend(const char *LoginUserName, const char *name)
{
    if(NULL == LoginUserName || NULL == name)
    {
        //空
        return -1;
    }
    else if(strcmp(LoginUserName, name)==0)
    {
        //无法添加自己为好友
        return -2;
    }
    else
    {
        //好有是否存在
        QString data = QString("select * from friend where "
                               "(id = (SELECT id from user where name = '%1') "
                               "and friendId = (SELECT id from user where name = '%2')) "
                               "or (friendId = (SELECT id from user where name = '%1') "
                               "and id = (SELECT id from user where name = '%2'))").arg(LoginUserName).arg(name);
        QSqlQuery qu;
        qu.exec(data);
        if(qu.next())
        {
            qDebug()<<"好友已存在";
            return 2;
        }
        else
        {
            return handSearchUser(name);   //-1不存在,0离线,1在线
        }
    }
}

bool opeDB::handAddFirendYes(const char *LoginUserName, const char *name)
{
    qDebug()<<LoginUserName;
    qDebug()<<name;
    QString data = QString("insert into friend(id,friendId) "
                                   "VALUES "
                                   "((SELECT id from user "
                                   "where name = '%1'),"
                                   "(SELECT id from user "
                                   "where name = '%2')); ").arg(LoginUserName).arg(name);
    QSqlQuery qu;
    return qu.exec(data);
}

QStringList opeDB::handleFlushFriend(const char *name)
{
    QStringList strFriendList;
    strFriendList.clear();
    if(NULL == name)
    {
        return strFriendList;
    }
    QSqlQuery qu;
    /*
    select name from user where id in
    (select id from friend where friendId =
    (SELECT id from user where name='%1')) or id in
    (select friendId from friend where id =
    (SELECT id from user where name='%1'))
    */

    QString data = QString("SELECT name FROM user WHERE id IN "
                           "(SELECT friendId AS userId FROM friend "
                           "WHERE id = (SELECT id FROM user WHERE name = '%1') "
                           "UNION "
                           "SELECT id AS userId FROM friend "
                           "WHERE friendId = (SELECT id FROM user WHERE name = '%1'))").arg(name);
    qu.exec(data);
    QString temp;
    qDebug()<<"----handleFlushFriend()调用----";
    qDebug()<<"用户"<<name<<"好友：";
    while(qu.next())
    {
        temp = qu.value(0).toString();
        strFriendList.append(temp);
        qDebug()<<temp;
    }
    return strFriendList;
}

bool opeDB::handDelFriend(const char *loginName, const char *name)
{
    if(NULL == loginName || NULL == name )
    {
        return false;
    }
    qDebug()<<"----handDelFriend()调用----";
    qDebug()<<"----删除用户："<<name;
    QString data = QString("delete from friend where "
                           "(id = (select id from user where name = '%1') "
                           "and friendId = (select id from user where name = '%2')) "
                           "OR (id = (select id from user where name = '%2') "
                           "and friendId = (select id from user where name = '%1'))").arg(loginName).arg(name);
    QSqlQuery qu;
    return qu.exec(data);
}













