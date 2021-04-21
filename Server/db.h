#ifndef DB_H
#define DB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class DB
{
public:
    DB();
    bool isConnection(); //连接数据库
    bool Insert(); //在数据库中进行插入
    bool Delete(); //在数据库中进行删除
    bool Select(); // 在数据中进行查询
private:
    QSqlQuery query;  //查询类
    QSqlDatabase db; //数据库类
};

#endif // DB_H
