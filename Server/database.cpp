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
    //创建业主信息表                                              房东ID                                          姓名                           收款账号                              联系电话               拥有的房屋号                       起租日期                     到租日期                 押金                  缴费周期                      每期缴租                照片地址                      备注
    QString create_owner = "create table if not exists Owners (Owner_id int primary key NOT NULL auto_increment,Name varchar(10) NOT NULL,Payment_account varchar(20) NOT NULL,Tel char(11) NOT NULL,Real_estate varchar(20) NOT NULL,Begin varchar(20) NOT NULL,End varchar(20) NOT NULL,Deposit int NOT NULL,Cycle varchar(10) NOT NULL, Month_rent int NOT NULL,Image_url varchar(20) NULL, Note varchar(50) NULL);";
    query.prepare(create_owner);
    success = query.exec(create_owner);
    if(!success)
    {
        qDebug() <<"query error(Owners): "<<query.lastError();
    }else
    {
        qDebug() << "create Owners successfully";
    }
    //创建租客信息表                                                   姓名                        联系电话               身份证号                                  性别            总费用           房产                          房号                       每期缴租                   缴费次数                   开始日期                     到租日期                      押金         缴费周期
    QString create_tenant = "create table if not exists Tenants (Name varchar(10) NOT NULL,Tel char(11) NOT NULL,ID_number char(20) primary key  NOT NULL, Sex char NULL,Cost int NULL,Real_estate varchar(20) NOT NULL,House_id varchar(10) NOT NULL,Month_rent int NOT NULL,Payment_times int NULL,Begin varchar(20) NOT NULL,End varchar(20) NOT NULL,Deposit int NULL,Cycle varchar(10) NULL);";
    query.prepare(create_tenant);
    success = query.exec(create_tenant);
    if(!success)
    {
        qDebug() <<"query error(Tenants): "<<query.lastError();
    }else
    {
        qDebug() << "create Tenants successfully";
    }
    //创建房产信息表                                                         id                                                     房产名                      详细地址                     房屋类型
    QString create_real_estate = "create table if not exists Real_estate (Real_estate_id int primary key NOT NULL auto_increment,Name varchar(20) NOT NULL,Address varchar(20) NOT NULL,Type varchar(10) NOT NULL);";
    query.prepare(create_real_estate);
    success = query.exec(create_real_estate);
    if(!success)
    {
        qDebug() <<"query error(Real_estate): "<<query.lastError();
    }else
    {
        qDebug() << "create Real_estate successfully";
    }
    //创建房号信息表                                              房号                            楼栋号                         楼层               户型                        面积                 月租金                   收租周期                    房号配置                         图片地址
    QString create_Room = "create table if not exists Room (Real_estate_id int NOT NULL,Room_number varchar(20) NOT NULL, Building_number int NOT NULL,Floor int NOT NULL,Model varchar(20) NOT NULL,Area double NOT NULL,Month_rent int NOT NULL,Cycle varchar(20) NOT NULL,configuration varchar(20) NULL,Image_url varchar(20) NULL);";
    query.prepare(create_Room);
    success = query.exec(create_Room);
    if(!success)
    {
        qDebug() <<"query error(Root): "<<query.lastError();
    }else
    {
        qDebug() << "create Room successfully";
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
    ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
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
        query.prepare("insert into mangers(Account,Password,Name,Tel) values(?,?,?,?)");
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

QByteArray DataBase::DB_manger_info(QString account,QString name,QString tel,QString sex)
{//管理员查询
    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() << "In thread run():"<< db.connectionName();
    QString sql;
    QSqlQuery query(db);
    if(account == "" && name == "" && tel == "" && sex == "")//查询全部
    {
        sql = "select * from mangers";
        query.prepare(sql);
    }else if(account =="" && name == "" && sex == "")  //查询某个电话
    {
        sql = "select * from mangers where tel =?";
        query.prepare(sql);
        query.bindValue(0,tel);
    }else if(account =="" && tel =="" && sex == "")  // 查询某个 姓名
    {
        sql = "select * from mangers where name=?";
        query.prepare(sql);
        query.bindValue(0,name);
    }else if(name =="" && tel =="" && sex == "") //查询某个 账号
    {
        sql = "select * from mangers where account =?";
        query.prepare(sql);
        query.bindValue(0,account);
    }else if (account =="" && name =="" && tel =="") //查询某个性别
    {
        sql = "select * from mangers where sex =?";
        query.prepare(sql);
        query.bindValue(0,sex);
    }else if(tel =="" && sex =="") //查询 姓名加账号
    {
        sql = "select * from mangers where account =? and name =?";
        query.prepare(sql);
        query.bindValue(0,account);
        query.bindValue(1,name);
    }else if(name =="" && sex == "")  // 查询 账号 加电话号码
    {
        sql = "select * from mangers where account =? and tel =?";
        query.prepare(sql);
        query.bindValue(0,account);
        query.bindValue(1,tel);
    }else if(name == "" && tel =="")  // 查询 账号 和性别
    {
        sql = "select * from mangers where account =? and sex =?";
        query.prepare(sql);
        query.bindValue(0,account);
        query.bindValue(1,sex);
    }
    //使用json 进行格式化
    QJsonDocument jdoc;
    QJsonObject obj;
    QJsonArray arr;


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
        Member["SEX"] = query.value(4).toString();
        arr.append(Member);
    }

    obj["ARRAYS"] = arr;
    jdoc.setObject(obj);
    QByteArray byteArray = jdoc.toJson(QJsonDocument::Compact);
    qDebug() <<QString(byteArray);
    ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
    return byteArray;
}

QByteArray DataBase::DB_tennant_info(QString search)
{

    //使用json 进行格式化
    QJsonDocument jdoc;
    QJsonObject obj;
    QJsonArray arr;

    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() << "In thread run():"<< db.connectionName();
    QString sql;
    QSqlQuery query(db);
    if(search == "")
    {
        sql = "select Name,Real_estate,House_id,Tel,End,Begin,Cycle,Month_rent,Payment_times from tenants";
        query.prepare(sql);

        if(!query.exec())
        {
            qDebug()<<"查询管理者语句失败"<<query.lastError();
            ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
            return QByteArray();
        }

        while(query.next())
        {
            QJsonObject Member; //定义数组成员
            Member["NAME"] = query.value(0).toString();
            Member["Real_estate"] = query.value(1).toString();
            Member["House_id"] = query.value(2).toString();
            Member["TEL"] = query.value(3).toString();
            Member["END"] = query.value(4).toString();
            Member["BEGIN"]= query.value(5).toString();
            Member["CYCLE"] = query.value(6).toString();
            Member["Month_rent"] = query.value(7).toInt();
            Member["Payment_time"] = query.value(8).toInt();

            arr.append(Member);
        }
    }else
    {
        int i=4;
        while(i>0)
        {
            if(i == 4)
            {
                sql = "select Name,Real_estate,House_id,Tel,End,Begin,Cycle,Month_rent,Payment_times from tenants where Real_estate =?";

            }else if(i == 3)
            {
                sql = "select Name,Real_estate,House_id,Tel,End,Begin,Cycle,Month_rent,Payment_times from tenants where House_id =?";
            }else if(i == 2)
            {
                sql = "select Name,Real_estate,House_id,Tel,End,Begin,Cycle,Month_rent,Payment_times from tenants where Name =?";
            }else if(i == 1)
            {
                sql = "select Name,Real_estate,House_id,Tel,End,Begin,Cycle,Month_rent,Payment_times from tenants where Tel =?";
            }
            query.prepare(sql);
            query.bindValue(0,search);

            if(!query.exec())
            {
                qDebug()<<"查询管理者语句失败"<<query.lastError();
                ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
                return QByteArray();
            }

            while(query.next())
            {
                QJsonObject Member; //定义数组成员
                Member["NAME"] = query.value(0).toString();
                Member["Real_estate"] = query.value(1).toString();
                Member["House_id"] = query.value(2).toString();
                Member["TEL"] = query.value(3).toString();
                Member["END"] = query.value(4).toString();
                Member["BEGIN"]= query.value(5).toString();
                Member["CYCLE"] = query.value(6).toString();
                Member["Month_rent"] = query.value(7).toInt();
                Member["Payment_time"] = query.value(8).toInt();

                arr.append(Member);
            }
            i--;
        }
    }


    obj["ARRAYS"] = arr;
    jdoc.setObject(obj);
    QByteArray byteArray = jdoc.toJson(QJsonDocument::Compact);
    qDebug() <<QString(byteArray);
    ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
    return byteArray;
}

QByteArray DataBase::DB_owner_info()
{ // 返回业主信息

    //使用json 进行格式化

    QJsonDocument jdoc;
    QJsonObject obj;
    QJsonArray arr;

    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() << "In thread run():"<< db.connectionName();
    QString sql;
    QSqlQuery query(db);

    sql = "select * from owners";

    query.prepare(sql);
    if(!query.exec())
    {
        qDebug()<<"查询业主语句失败"<<query.lastError();
        ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
        return QByteArray();
    }

    while(query.next())
    {
        QJsonObject Member; //定义数组成员
        Member["NAME"] = query.value(1).toString();
        Member["Payment_account"] = query.value(2).toString();
        Member["TEL"] = query.value(3).toString();
        Member["Real_estate"] = query.value(4).toString();
        Member["BEGIN"] = query.value(5).toString();
        Member["END"]= query.value(6).toString();
        Member["DEPOSIT"] = query.value(7).toInt();
        Member["CYCLE"] = query.value(8).toString();
        Member["Month_rent"] = query.value(9).toInt();
        Member["NOTE"] = query.value(11).toString();

        arr.append(Member);
    }

    obj["ARRAYS"] = arr;
    jdoc.setObject(obj);
    QByteArray byteArray = jdoc.toJson(QJsonDocument::Compact);
    qDebug() <<QString(byteArray);
    ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
    return byteArray;
}

QByteArray DataBase::DB_Real_estate_info()
{ //返回房产信息

    //使用json 进行格式化

    QJsonDocument jdoc;
    QJsonObject obj;
    QJsonArray arr;

    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() << "In thread run():"<< db.connectionName();
    QString sql;
    QSqlQuery query(db);

    sql = "select * from real_estate";

    query.prepare(sql);
    if(!query.exec())
    {
        qDebug()<<"查询房产语句失败"<<query.lastError();
        ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
        return QByteArray();
    }

    while(query.next())
    {
        QJsonObject Member; //定义数组成员
        Member["Real_estate_id"] = query.value(0).toInt();
        Member["NAME"] = query.value(1).toString();
        Member["ADDRESS"] = query.value(2).toString();
        Member["TYPE"] = query.value(3).toString();

        arr.append(Member);
    }

    obj["ARRAYS"] = arr;
    jdoc.setObject(obj);
    QByteArray byteArray = jdoc.toJson(QJsonDocument::Compact);
    qDebug() <<QString(byteArray);
    ConnectionPool::closeConnection(db);// 连接使用完后需要释放回数据库连接池
    return byteArray;
}

QByteArray DataBase::DB_Room_info(int Real_estate_id)
{

}
//添加租客
bool DataBase::DB_add_tennants(QString Real_estate, QString House_id, QString name, QString tel, QString ID_number, QString begin, QString end,QString cycle, int month_rent, int deposit)
{
    QSqlDatabase db = ConnectionPool::openConnection();
    qDebug() << "In thread run():"<<db.connectionName();
    QSqlQuery query(db);

    QString sql;
    sql = "insert into Tenants(Real_estate,House_id,name,tel,ID_number,Begin,End,Month_rent,Deposit,Payment_times,Cycle) values(?,?,?,?,?,?,?,?,?,?,?)";
    query.prepare(sql);
    query.bindValue(0,Real_estate);
    query.bindValue(1,House_id);
    query.bindValue(2,name);
    query.bindValue(3,tel);
    query.bindValue(4,ID_number);
    query.bindValue(5,begin);
    query.bindValue(6,end);
    query.bindValue(7,month_rent);
    query.bindValue(8,deposit);
    query.bindValue(9,0);
    query.bindValue(10,cycle);

    if(!query.exec())
    {
        qDebug() << "租客添加失败"<< query.lastError();
        ConnectionPool::closeConnection(db);
        return false;
    }
    qDebug() << "用户添加成功";
    ConnectionPool::closeConnection(db);
    return true;
}



