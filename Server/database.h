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
    QByteArray DB_manger_info();
};

#endif // DATABASE_H
