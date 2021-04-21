#include "database.h"
#include "connectionpool.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

DataBase::DataBase(QString name)
{
}

//创建基本表
void DataBase::DB_create()
{
    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() << "In thread run():"<< db.connectionName();

    QSqlQuery query(db);
    //创建系统管理员表
    QString create_manger = "create table if not exists Mangers (Account char(11) primary key NOT NULL,Password char(30) NOT NULL,Name varchar(10) NULL,Tel char(11),Sex char NULL);";
    query.prepare(create_manger);
    bool success =query.exec(create_manger);
    if(!success)
    {
        qDebug() <<"query error(Mangers): "<<query.lastError();
    }else
    {
        qDebug() << "create Mangers successfully";
    }
    //创建业主信息表
    QString create_owner = "create table if not exists Owners (Owner_id int primary key NOT NULL,Name varchar(10) NOT NULL,Address varchar(30) NOT NULL,Payment_account varchar(20)NOT NULL,Sex char NULL,Tel char(11) NOT NULL,House_Number int 0);";
    query.prepare(create_owner);
    success = query.exec(create_owner);
    if(!success)
    {
        qDebug() <<"query error(Owners): "<<query.lastError();
    }else
    {
        qDebug() << "create Owners successfully";
    }
    //创建租客信息表
    QString create_tenant = "create table if not exists Tenants (Tenant_id int primary key NOT NULL,Name varchar(10) NOT NULL,Tel char(11) NOT NULL,ID_number char(20) NOT NULL, Sex char NULL,Cost int NOT NULL,House_id int NOT NULL,Lease int NOT NULL);";
    query.prepare(create_tenant);
    success = query.exec(create_tenant);
    if(!success)
    {
        qDebug() <<"query error(Tenants): "<<query.lastError();
    }else
    {
        qDebug() << "create Tenants successfully";
    }
    //创建房屋信息表
    QString create_house = "create table if not exists Houses (House_id int primary key NOT NULL,Address varchar(20) NOT NULL, Area double NOT NULL,State varchar(10) NOT NULL,Shap varchar(10) NOT NULL,Month_rent int NOT NULL,Max_people int 1,Produce_cycle int 1,Instructions varchar(50) NULL);";
    query.prepare(create_house);
    success = query.exec(create_house);
    if(!success)
    {
        qDebug() <<"query error(House): "<<query.lastError();
    }else
    {
        qDebug() << "create House successfully";
    }
    //创建合同信息表                                                   编号                                    月租金                  租期          起租日期                  到租日期               承租人                       承租人身份证号                      地址                        押金
    QString create_contract = "create table if not exists Contracts (Contract_id int primary key NOT NULL,Months_rent int NOT NULL,Lease int 1,Begin DATETIME NOT NULL, End DATETIME NOT NULL,Lessee varchar(10) NOT NULL,ID_number char(20) NOT NULL,Tel char(11) NOT NULL,Address varchar(30) NOT NULL,Deposit int 0,Total_money int 0);";
    query.prepare(create_contract);
    success = query.exec(create_contract);
    if(!success)
    {
        qDebug() <<"query error(Contracts): "<<query.lastError();
    }else
    {
        qDebug() << "create Contracts successfully";
    }

}

bool DataBase::DB_insert_manger(QString account, QString password, QString name, QString tel)
{
    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() << "In thread run():"<<db.connectionName();

    QSqlQuery query(db);
    //先进行验证，如果该账号没有被注册过则注册然后返回true,否则返回false
    query.prepare("select * from mangers where Account =? ");
    query.bindValue(0,account);
    query.exec();
    //进行验证
    if(!query.next())
    {//账号未被注册
        query.clear();
        query.prepare("insert into mangers values(?,?,?,?)");
        query.bindValue(0,account);
        query.bindValue(1,password);
        query.bindValue(2,name);
        query.bindValue(3,tel);

        if(!query.exec())
        {
            qDebug() <<"用户添加失败"<<query.lastError();
            ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
            return false;
        }
        qDebug() << "用户添加成功";
        ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
        return true;
    }
    else{//账号已被注册
        qDebug()<< "此账号已被注册";
    }
    ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
    return false;
}
//管理员登录
bool DataBase::DB_login(QString account, QString password)
{
    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() <<"In thread run():"<<db.connectionName();

    QSqlQuery query(db);

    query.prepare("select * from mangers where Account =? and Password=?");
    query.bindValue(0,account);
    query.bindValue(1,password);
    if(!query.exec())
    {
        qDebug()<<"查询管理者语句失败"<<query.lastError();
        ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
        return false;
    }
    if(!query.next())
    {
        qDebug()<<"登录失败，账户或密码错误";
        ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
        return false;
    }
    else{
        qDebug()<<"登录成功";
        ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
        return true;
    }
    ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
    return false;
}

QByteArray DataBase::DB_manger_info()
{
    //使用json 进行格式化
    QJsonDocument jdoc;
    QJsonObject obj;
    QJsonArray arr;

    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() << "In thread run():"<< db.connectionName();

    QSqlQuery query(db);

    query.prepare("select * from mangers limit 9");
    if(!query.exec())
    {
        qDebug()<<"查询管理者语句失败"<<query.lastError();
        ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
        return QByteArray();
    }
    while(query.next())
    {
        QJsonObject Member; //定义数组成员
        Member["ACCOUNT"] = query.value(0).toString();
        Member["PASSWORD"] = query.value(1).toString();
        Member["NAME"] = query.value(2).toString();
        Member["TEL"] = query.value(3).toString();
        arr.append(Member);
    }

    obj["ARRAYS"] = arr;
    jdoc.setObject(obj);
    QByteArray byteArray = jdoc.toJson(QJsonDocument::Compact);
    qDebug() <<QString(byteArray);
    return byteArray;
}



