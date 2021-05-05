#include "baseworker.h"
#include <QDebug>
#include <QThread>

BaseWorker::BaseWorker(QObject *parent) :QObject(parent)
{

}

void BaseWorker::manger_login(QString account,QString password)
{
    qDebug() <<"process's Thread:"<<QThread::currentThreadId();
    m_login_state =dataEncapsulation->login_manger(account,password);
    qDebug() << "login state:"<< m_login_state;
    emit login_state_change(m_login_state);
    emit processFinished();
}

void BaseWorker::manger_register(QString account, QString password,QString name,QString tel)
{
    qDebug() <<"process's Thread:"<<QThread::currentThreadId();
    m_register_state = dataEncapsulation->insert_manger(account,password,name,tel);
    qDebug() << "register state:"<< m_register_state;
    emit register_state_change(m_register_state);
    emit processFinished();
}

void BaseWorker::init()
{
    dataEncapsulation = new DataEncapsulation();
    dataEncapsulation->connect();
}

void BaseWorker::disconnect_()// 与服务器断开连接
{
    if(dataEncapsulation)
    {
        dataEncapsulation->disconnect();
    }
}

void BaseWorker::showMangers(QString account,QString name,QString tel,QString sex)
{
    QList<Manger> manger= dataEncapsulation->display_user_infor(account,name,tel,sex);
    emit update_manger(manger);
}

void BaseWorker::showTennants(QString search)
{//显示租客信息
    QList<Tennant> tennant = dataEncapsulation->display_tennant_info(search);
    emit update_tennant(tennant);
}

void BaseWorker::showOwners()
{
    QList<Owner> owner = dataEncapsulation->display_owner_info();
    emit update_owner(owner);
}

void BaseWorker::showReal_estate()
{
    QList<Real_estate> real_estate = dataEncapsulation->display_real_estate_info();
    emit update_real_estate(real_estate);
}

bool BaseWorker::add_tennants(QString Real_estate, QString House_id, QString name, QString tel, QString ID_number, QString begin,QString end,QString cycle, QString month_rent, QString deposit)
{
    qDebug() << "BeseWorker:: add_tennants";

    return dataEncapsulation->add_tennants(Real_estate,House_id,name,tel,ID_number,begin,end,cycle,month_rent.toInt(),deposit.toInt());
}

