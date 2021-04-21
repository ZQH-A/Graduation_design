#ifndef DATAENCAPSULATION_H
#define DATAENCAPSULATION_H
//数据封装
//处理从 qml 端传送的数据或者 传送数据到 qml 端
#include <QObject>
#include "simpletcpsocketclient.h"
#include "mangermodel.h"

class DataEncapsulation : public QObject
{
    Q_OBJECT
public:
    DataEncapsulation();
    void push_back_manger(MangerModel *model);
    Q_INVOKABLE void disconnect();
    Q_INVOKABLE bool insert_manger(QString account,QString password,QString name,QString tel);//注册成管理员
    Q_INVOKABLE bool login_manger(QString account,QString password);//登录
    Q_INVOKABLE void first_select_house(); //qml端第一次显示关于房子表格，将model的内容更新为数据库中房子信息
    Q_INVOKABLE void first_select_System_User();//qml端第一次显示关于系统用户，将model内容更新为数据库中系统用户信息
    Q_INVOKABLE void display_user_infor(); //从服务器端接收用户信息
private:
    SimpleTcpSocketClient *tcpSocketClient; //进行数据处理
    MangerModel *m_manger_model;
};

#endif // DATAENCAPSULATION_H
