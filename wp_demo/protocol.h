#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <stdlib.h>
#include <unistd.h>
#include <string>

typedef  unsigned int uint;

#define REGIST_OK "注册成功！"
#define REGIST_FAILED "注册失败：用户名已存在！"
#define LOGIN_OK "登录成功！"
#define LOGIN_FAILED "登录失败：用户名不存在或密码错误！"
#define LOGIN_ONLINEED "当前用户已登录！"
#define SEARCH_USER_ONLINE "用户在线！"
#define SEARCH_USER_NOT_ONLINE "用户离线！"
#define SEARCH_USER_NO_SUCH_USER "！！用户不存在！！"
#define SEARCH_USER_NULL "用户为空无法查询！"

enum ENUM_MSG_TYPE
{
    ENUM_MSG_TYPE_MIN = 0,
    ENUM_MSG_TYPE_REGIST_REQUEST,                   //request 注册请求
    ENUM_MSG_TYPE_REGIST_RESPOND,                   //respond 注册回复

    ENUM_MSG_TYPE_LOGIN_REQUEST,                    //request 登录请求
    ENUM_MSG_TYPE_LOGIN_RESPOND,                    //respond 登录回复

    ENUM_MSG_TYPE_LIST_ONLINEUSER_REQUEST,          //request 查看在线用户请求
    ENUM_MSG_TYPE_LIST_ONLINEUSER_RESPOND,          //respond 查看在线用户回复

    ENUM_MSG_TYPE_SEARCH_USER_REQUEST,              //request 搜索用户请求
    ENUM_MSG_TYPE_SEARCH_USER_RESPOND,              //respond 搜索用户回复

    ENUM_MSG_TYPE_ADD_FRIEND_REQUEST,               //request 添加好友请求
    ENUM_MSG_TYPE_ADD_FRIEND_RESPOND,               //respond 添加好友回复

    ENUM_MSG_TYPE_ADD_FRIEND_YES,                   //同意添加好友
    ENUM_MSG_TYPE_ADD_FRIEND_NO,                    //不同意添加好友

    ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST,             //刷新好友请求
    ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND,             //刷新好友回复

    ENUM_MSG_TYPE_DEL_FRIEND_REQUEST,               //删除好友请求
    ENUM_MSG_TYPE_DEL_FRIEND_RESPOND,               //删除好友回复

    ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST,             //私聊请求
    ENUM_MSG_TYPE_PRIVATE_CHAT_RESPOND,             //私聊回复

    ENUM_MSG_TYPE_GROUP_CHAT_REQUEST,               //群聊请求
    ENUM_MSG_TYPE_GROUP_CHAT_RESPOND,               //群聊回复

    ENUM_MSG_TYPE_CREATE_DIR_REQUEST,               //创建文件夹请求
    ENUM_MSG_TYPE_CREATE_DIR_RESPOND,               //创建文件夹回复

    ENUM_MSG_TYPE_FLUSH_FILE_REQUEST,               //刷新文件请求
    ENUM_MSG_TYPE_FLUSH_FILE_RESPOND,               //刷新文件回复

    ENUM_MSG_TYPE_DELETE_FILEDIR_REQUEST,           //删除文件夹请求
    ENUM_MSG_TYPE_DELETE_FILEDIR_RESPOND,           //删除文件夹回复

    ENUM_MSG_TYPE_RENAME_FILE_REQUEST,              //重命名文件夹请求
    ENUM_MSG_TYPE_RENAME_FILE_RESPOND,              //重命名文件夹回复

    ENUM_MSG_TYPE_ENTER_FILE_REQUEST,               //进入文件夹请求
    ENUM_MSG_TYPE_ENTER_FILE_RESPOND,               //进入文件夹回复

    ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST,              //上传文件请求
    ENUM_MSG_TYPE_UPLOAD_FILE_RESPOND,              //上传文件回复

    ENUM_MSG_TYPE_DELETE_FILE_REQUEST,              //删除文件请求
    ENUM_MSG_TYPE_DELETE_FILE_RESPOND,              //删除文件回复

    ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST,            //下载文件请求
    ENUM_MSG_TYPE_DOWNLOAD_FILE_RESPOND,            //下载文件回复

    ENUM_MSG_TYPE_MAX = 0x00ffffff, //设置为32

};

struct FileInfo{
    char caFileName[255];       //文件名字
    int iFileType;              //文件类型
};

struct PDU
{
    uint uiPDULen;          //总的协议数据单元大小
    uint uiMsgType;         //消息类型
    char caData[64];
    char caFileName[510];
    uint uiMsgLen;          //实际消息长度
    int caMsg[];            //实际消息
};

PDU *mkPDU(uint uiMsgLen);
#endif // PROTOCOL_H

