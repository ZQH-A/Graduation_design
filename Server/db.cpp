#include "db.h"


DB::DB()
{

}

bool DB::isConnection()
{
    db = QSqlDatabase::addDatabase("QMYSQL"); //数据库对象
    db.setHostName("127.0.0.1"); //数据库服务器IP   连接本机数据库服务器
    db.setPort(3306);   //设置 端口号
    db.setUserName("root"); //数据库用户名
    db.setPassword("root"); //数据库密码
    db.setDatabaseName("info"); //使用哪个数据库
    if(!db.open())
    {
        qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
        return false;
    }
    query = QSqlQuery(db);  //执行 sql 语句的类
    qDebug()<<"连接成功"<<"connect to mysql OK";
    return true;
}

bool DB::Select()
{
    query.exec("select * from userinfo");  //查询empolyees 库中所有的数据
    while(query.next())
    {
        qDebug()<<query.value("name").toString();
        qDebug()<<query.value("ID").toString();
        qDebug()<<query.value("PASSWORD").toString();
    }
}
