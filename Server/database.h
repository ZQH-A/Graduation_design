#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DataBase
{
public:
    DataBase(QString name);//name 是数据库名称
    void DB_create();   //创建基本表
    bool DB_insert_manger(QString account,QString password,QString name,QString tel); //往管理员表中插入数据
    bool DB_login(QString account,QString password);//管理员登录
    QByteArray DB_manger_info(QString account,QString name,QString tel,QString sex); //系统管理员信息
    QByteArray DB_tennant_info(QString search); //租客信息
    QByteArray DB_owner_info();//业主信息
    QByteArray DB_Real_estate_info(); //房产信息
    QByteArray DB_Room_info(int Real_estate_id);  //Real_estate_id 下的房号信息
    //添加租客
    bool DB_add_tennants(QString Real_estate,QString House_id,QString name,QString tel,QString ID_number, QString begin,QString end,QString cycle,int month_rent,int deposit);
};

#endif // DATABASE_H
