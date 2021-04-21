#include "dataencapsulation.h"

DataEncapsulation::DataEncapsulation()//打开数据库并创建一些基本表
{
    tcpSocketClient = new SimpleTcpSocketClient();
    tcpSocketClient->Connect();
}

void DataEncapsulation::push_back_manger(MangerModel *model)
{
    m_manger_model = model;
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

void DataEncapsulation::first_select_house()
{

}

void DataEncapsulation::first_select_System_User()
{

}

void DataEncapsulation::display_user_infor()
{
    QList<Manger> manger = tcpSocketClient->receive_Manger_info();
    qDebug() << manger.size();
    for(int i=0;i<manger.size();i++)
    {
        m_manger_model->addManger(manger[i]);
    }
//    m_manger_model->addManger(Manger("1","1","1","1"));
//    m_manger_model->addManger(Manger("2","1","1","1"));
//    m_manger_model->addManger(Manger("3","1","1","1"));
//    m_manger_model->addManger(Manger("4","1","1","1"));
}

