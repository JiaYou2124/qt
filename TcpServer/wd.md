# C++网盘demo日志
    -数据表设计
        -User
            Id，name，pwd，online
        -Friend
            Id，friendId


    -客户端:
        产生一个socket（m_tcpsocket）,通过这个connect()函数
        发送信号connnected()信号，关联showConnect()函数
        成功链接服务器会发出connnected()信号，借此判断是否成功连接服务器
        m_tcpsocket.write((char*)pdu,pdu->uiPDULen)
            使用TCP套接字发送数据
            write() 方法，用于向连接的TCP服务器发送数据。
            这个方法是阻塞的，意味着它会等待直到所有数据都被发送出去。
            pdu被转换为char*类型，因为write()方法需要一个字节流作为参数。
        free(pdu)
            释放pdu指向的内存
        pdu = NULL
            将pdu指针设置为NULL
    
    -服务器：
        加载配置文件，及打开数据库
        QTcpServer监听（mytcpserver监听）
        循环接收客户端连接
        获得新QTcpSocket
        与客户端数据交互及数据操作
    
    -协议设计
        总的消息大小  uiPDULen
        消息类型     uiMsgType 
        实际消息大小  uiMsgLen 
                    caData[64] 
        实际消息      caMsg[]


    -在网络编程中，发送字符串时应始终使用toUtf8().size()获取实际字节数,而不是sizeof() 
    或QString::size()。
    tpcclient.cpp,TcpClient::on_send_pb_clicked()
    

    -数据库连接:
        private:
            QSqlDatabase m_db;
        m_db = QSqlDatabase::addDatabase("QMYSQL");
        m_db.setHostName("localhost");  //数据库连接
        m_db.setUserName("root");       //数据库名称
        m_db.setPassword("123456");     //数据库密码
        m_db.setDatabaseName("my_wp");  //要操作的数据库
        
    -登录注册注销请求：
        *消息类型：
            +   ENUM_MSG_TYPE_MIN = 0,
            +   ENUM_MSG_TYPE_REGIST_REQUEST,          //request 注册请求
            +   ENUM_MSG_TYPE_REGIST_RESPOND,          //respond 注册回复
            +   ENUM_MSG_TYPE_LOGIN_REQUEST,           //request 登录请求
            +   ENUM_MSG_TYPE_LOGIN_RESPOND,           //respond 登录回复
            +   ENUM_MSG_TYPE_MAX = 0x00ffffff,        //设置为32
        *界面设计：
            +
        *注册，用户名唯一，防止重复注册：
            +
        *登录，防止重复登录：
            +防止重复登录，在数据库添加字段用online记录该用户是否在线
             在线则不允许登录（online=1 表示在线）
            +在登录时保存当前登录用户的userName为：m_loginUserName
        *退出：
            +将数据库在线状态设置为下线状态（online=0），并将socket删除
        *注销，删除好友信息，删除个人信息，删除网盘文件：
            +
    -添加好友：
        *通过在TcpClient保存m_loginUserName登陆者用户名,用于请求方name
        *在online实现发送添加好友的请求
        *QString loginName = TcpClient::getInstance().getLoginName()获取列表选择的文本
    -删除好友：
        *通过在TcpClient保存m_loginUserName登陆者用户名，用于请求方name
        *在online实现发送添加好友的请求
    -刷新好友列表：
        *获取m_loginUserName,传输登录用户name到服务器进行查询该用户好友
    -查看所有在线用户：
        *通过user表单的online来进行查询是否在线，将在线的用户保存到一个列表并传到客户端展示
    


    文件操作
    QDir
    创建文件夹
    查看文件夹
    删除文件夹
    重命名文件夹
    进入文件夹
    返回上一级
        检查是否根目录，根目录无法返回上一级
    上传文件






bug:



















