#include "dataencapsulation.h"

DataEncapsulation::DataEncapsulation()//打开数据库并创建一些基本表
{
    tcpSocketClient = new SimpleTcpSocketClient();
}

void DataEncapsulation::connect()
{
    tcpSocketClient->Connect();
}

void DataEncapsulation::disconnect()
{
    tcpSocketClient->disconnect();
}

bool DataEncapsulation::insert_manger(QString account, QString password, QString name, QString tel)
{
    return tcpSocketClient->insert_manger(account,password,name,tel);
}

bool DataEncapsulation::login_manger(QString account, QString password)
{
    return tcpSocketClient->login(account,password);
}

QList<Manger> DataEncapsulation::display_user_infor(QString account,QString name,QString tel,QString sex)
{
    QList<Manger> manger = tcpSocketClient->receive_Manger_info(account,name,tel,sex);
    return manger;
}

QList<Tennant> DataEncapsulation::display_tennant_info(QString search)
{
    QList<Tennant> tenants = tcpSocketClient->receive_Tennant_info(search);
    return tenants;
}

QList<Owner> DataEncapsulation::display_owner_info()
{
    QList<Owner> owner = tcpSocketClient->receive_Owner_info();
    return owner;
}

QList<Real_estate> DataEncapsulation::display_real_estate_info()
{
    QList<Real_estate> real_estate = tcpSocketClient->receive_Real_estate_info();
    return real_estate;
}

bool DataEncapsulation::add_tennants(QString Real_estate, QString House_id, QString name, QString tel, QString ID_number, QString begin, QString end,QString cycle, int month_rent, int deposit)
{
    return tcpSocketClient->add_tennants(Real_estate,House_id,name,tel,ID_number,begin,end,cycle,month_rent,deposit);
}

