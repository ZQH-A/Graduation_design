#ifndef DATAENCAPSULATION_H
#define DATAENCAPSULATION_H
//数据封装
//处理从 qml 端传送的数据或者 传送数据到 qml 端
#include <QObject>
#include "simpletcpsocketclient.h"
#include "mangermodel.h"
#include "tennant.h"

class DataEncapsulation : public QObject
{
    Q_OBJECT
public:
    DataEncapsulation();
    void connect();
    Q_INVOKABLE void disconnect();
    Q_INVOKABLE bool insert_manger(QString account,QString password,QString name,QString tel);//注册成管理员
    Q_INVOKABLE bool login_manger(QString account,QString password);//登录
    Q_INVOKABLE QList<Manger> display_user_infor(QString account,QString name,QString tel,QString sex); //从服务器端接收用户信息
    QList<Tennant> display_tennant_info(QString search);//显示租客信息
    QList<Owner> display_owner_info(); //显示业主信息
    QList<Real_estate> display_real_estate_info(); //显示房产信息
    bool add_tennants(QString Real_estate,QString House_id,QString name,QString tel,QString ID_number, QString begin,QString end,QString cycle,int month_rent,int deposit);//添加租客
private:
    SimpleTcpSocketClient *tcpSocketClient; //进行数据处理
};

#endif // DATAENCAPSULATION_H
