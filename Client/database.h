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
    bool DB_conn(QString name); //连接数据库
    void DB_create();   //创建基本表
    bool DB_insert_manger(QString account,QString password,QString name,QString tel); //往管理员表中插入数据
    bool DB_login(QString account,QString password);//管理员登录
    QSqlDatabase database();
private:
    QSqlQuery *query;  //查询类
    QSqlDatabase *db; //数据库类
};

#endif // DATABASE_H
