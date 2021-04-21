#ifndef SIMPLETCPSOCKETCLIENT_H
#define SIMPLETCPSOCKETCLIENT_H

#include "manger.h"
#include <QTcpSocket>

#define LOGIN 0x0103 //客户端登录
#define REGISTER 0x0104 //客户端注册
#define DISCONNECT 0x0105 //客户端断开连接
#define RECE_USER_INFO 0x0106 //接收服务器端发送的管理员信息
class SimpleTcpSocketClient
{
public:
    SimpleTcpSocketClient();
    ~SimpleTcpSocketClient();
    void Connect();
    bool login(QString account,QString password);//管理员登录
    void sendHeader(int type,int length =0);//像服务器发送接下来要进行的操作 和服务器将要接收的字节数
    void ReceiveHeader();
    void disconnect();
    bool insert_manger(QString account,QString password,QString name,QString tel);//注册成管理员
    QList<Manger> receive_Manger_info();

private:
    QTcpSocket* m_pTcpSocket;
    int m_type;
    int m_len;
};

#endif // SIMPLETCPSOCKETCLIENT_H
