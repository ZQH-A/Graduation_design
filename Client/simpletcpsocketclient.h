#ifndef SIMPLETCPSOCKETCLIENT_H
#define SIMPLETCPSOCKETCLIENT_H

#include "manger.h"
#include "tennant.h"
#include "owner.h"
#include "real_estate.h"
#include <QTcpSocket>

#define LOGIN 0x0103 //客户端登录
#define REGISTER 0x0104 //客户端注册
#define DISCONNECT 0x0105 //客户端断开连接
#define RECE_USER_INFO 0x0106 //接收服务器端发送的管理员信息
#define ADD_TENNANTS 0x0107 //添加租客
#define RECE_TENNANT_INFO 0x0108 //接收服务器端发送的租客信息
#define RECE_OWNER_INFO 0x0109 //接收服务器端发送的业主信息
#define RECE_REAL_ESTATE_INFO 0x010A //接收服务器发送的房产信息

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
    QList<Manger> receive_Manger_info(QString account,QString name,QString tel,QString sex);//接收服务端发送的管理员信息
    QList<Tennant> receive_Tennant_info(QString search); //接收服务端发送的租客信息
    QList<Owner> receive_Owner_info(); // 接收服务器发送的业主信息
    QList<Real_estate> receive_Real_estate_info();
    bool add_tennants(QString Real_estate,QString House_id,QString name,QString tel,QString ID_number, QString begin,QString end,QString cycle,int month_rent,int deposit);
private:
    QTcpSocket* m_pTcpSocket;
    int m_type;
    int m_len;
};

#endif // SIMPLETCPSOCKETCLIENT_H
