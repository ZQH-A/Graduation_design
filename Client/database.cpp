#include "database.h"

DataBase::DataBase(QString name)
{
    db = new QSqlDatabase(QSqlDatabase::addDatabase("QMYSQL")); //初始化数据库对象
    DB_conn(name); //连接数据库
    DB_create(); //创建基本表
}

bool DataBase::DB_conn(QString name)
{
    db->setHostName("localhost");
    db->setDatabaseName(name);
    db->setUserName("root");
    db->setPassword("root");

    if(!db->open())
    {
        qDebug() << "数据库打开失败";
        return false;
    }
    else{
        qDebug() <<"数据库打开成功";
    }
    return true;
}

//创建基本表
void DataBase::DB_create()
{
    query = new QSqlQuery;

    //管理员登录表
    QString create_manger = "create table if not exists Mangers (Account char(11) primary key NOT NULL,Password char(30) NOT NULL,Name varchar(10) NULL,Tel char(11));";
    query->prepare(create_manger);
    bool success =query->exec(create_manger);
    if(!success)
    {
        qDebug() <<"query error(Mangers): "<<query->lastError();
    }else
    {
        qDebug() << "create Mangers successfully";
    }
}

bool DataBase::DB_insert_manger(QString account, QString password, QString name, QString tel)
{
    query = new QSqlQuery;
    //先进行验证，如果该账号没有被注册过则注册然后返回true,否则返回false
    query->prepare("select * from mangers where Account =? ");
    query->bindValue(0,account);
    query->exec();
    //进行验证
    if(!query->next())
    {//账号未被注册
        query->clear();
        query->prepare("insert into mangers values(?,?,?,?)");
        query->bindValue(0,account);
        query->bindValue(1,password);
        query->bindValue(2,name);
        query->bindValue(3,tel);

        if(!query->exec())
        {
            qDebug() <<"用户添加失败"<<query->lastError();
            return false;
        }
        qDebug()<< "用户添加成功";
        return true;
    }
    else{ //账号已被注册
        qDebug()<< "此账号已被注册";
    }
    return false;
}
//管理员登录
bool DataBase::DB_login(QString account, QString password)
{
    query = new QSqlQuery;

    query->prepare("select * from mangers where Account =? and Password=?");
    query->bindValue(0,account);
    query->bindValue(1,password);
    if(!query->exec())
    {
        qDebug()<<"查询管理者语句失败"<<query->lastError();
        return false;
    }
    if(!query->next())
    {
        qDebug()<<"登录失败，账户或密码错误";
        return false;
    }
    else{
        qDebug()<<"登录成功";
        return true;
    }
    return false;
}

QSqlDatabase DataBase::database()
{
    return *db;
}


