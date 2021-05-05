#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QTcpSocket>
#include "database.h"

#define LOGIN 0x0103 //客户端登录标志
#define REGISTER 0x0104 //客户端注册
#define DISCONNECT 0x0105 //客户端断开连接
#define RECE_USER_INFO 0x0106 //服务器端发送的管理员信息
#define ADD_TENNANTS 0x0107 //添加租客
#define RECE_TENNANT_INFO 0x0108 //接收服务器端发送的租客信息
#define RECE_OWNER_INFO 0x0109 //接收服务器端发送的业主信息
#define RECE_REAL_ESTATE_INFO 0x010A //接收服务器发送的房产信息
class Transport
{
public:
    Transport(qintptr SocketDescriptor);
    void ReceiveHeader();
    void sendHeader(int type,int length =0);//像客户端发送接下来要进行的操作 和客户端将要接收的字节数
    void ReceiveLogin(); //接收从客户端的账号密码 并验证其是否正确
    void ReceiveRegister(); // 接收从客户端的账号密码等信息，并验证是否被注册过，如果注册过，则注册并返回成功，否则返回失败
    void send_manger_info(); //发送管理员的信息到客户端
    void send_tennant_info();//发送租客信息到客户端
    void send_owner_info();//发送业主信息到客户端
    void send_real_estate_info();//发送房产信息
    int Type(); // 返回类型
    void add_tennants();
    ~Transport();
private:
    QTcpSocket *socket;
    DataBase *db;
    int m_type;
    int m_len;
};



#endif // TRANSPORT_H
