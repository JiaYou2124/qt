#ifndef OPEDB_H
#define OPEDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStringList>


class opeDB : public QObject
{
    Q_OBJECT
public:
    explicit opeDB(QObject *parent = nullptr);
    static opeDB& getInstance();
    void init();
    ~opeDB();

    bool handleRegist(const char *name,const char *pwd);
    int handleLogin(const char *name,const char *pwd);
    void handleOffline(const char *name);
    int handSearchUser(const char *name);
    QStringList handleAllOnlineUser();
    int handAddFirend(const char *LoginUserName,const char *name);
    bool handAddFirendYes(const char *LoginUserName,const char *name);
    QStringList handleFlushFriend(const char *name);
    bool handDelFriend(const char *loginName,const char *name);

private:
    QSqlDatabase m_db;  //连接数据库


signals:
};

#endif // OPEDB_H
