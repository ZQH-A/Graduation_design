#include "workermanager.h"
#include <QThreadPool>
#include "baseworker.h"
#include <QDebug>

WorkerManager::WorkerManager( QObject *parent):QObject(parent)
{
    mWorker.moveToThread(&mThread);
    connect(this,&WorkerManager::manger_login,&mWorker,&BaseWorker::manger_login);
    connect(this,&WorkerManager::init,&mWorker,&BaseWorker::init);
    connect(this,&WorkerManager::manger_register,&mWorker,&BaseWorker::manger_register);
    connect(this,&WorkerManager::disconnect_,&mWorker,&BaseWorker::disconnect_);
    connect(this,&WorkerManager::showMangers,&mWorker,&BaseWorker::showMangers);
    connect(this,&WorkerManager::add_tennants,&mWorker,&BaseWorker::add_tennants);//添加租客
    connect(this,&WorkerManager::showTennants,&mWorker,&BaseWorker::showTennants);//显示和查询租客
    connect(this,&WorkerManager::showOwners,&mWorker,&BaseWorker::showOwners); //显示业主
    connect(this,&WorkerManager::showReal_estate,&mWorker,&BaseWorker::showReal_estate);
    connect(&mWorker,&BaseWorker::login_state_change,this,&WorkerManager::receive_login_state);
    connect(&mWorker,&BaseWorker::register_state_change,this,&WorkerManager::receive_register_state);
    connect(&mWorker,&BaseWorker::update_manger,this,&WorkerManager::receive_manger);
    connect(&mWorker,&BaseWorker::update_tennant,this,&WorkerManager::receive_tennant);
    connect(&mWorker,&BaseWorker::update_owner,this,&WorkerManager::receive_owner);
    connect(&mWorker,&BaseWorker::update_real_estate,this,&WorkerManager::receive_real_estate);
    connect(&mWorker,&BaseWorker::processFinished,[this]{
        qDebug() << "ProcessFinished in : "<<QThread::currentThreadId();
    });
    mThread.start();//启动一个线程
}

WorkerManager::~WorkerManager()
{
    mThread.exit();
    mThread.wait();
}

bool WorkerManager::get_login_state() const
{
    return m_login_state;
}

void WorkerManager::disconnect_from_sever()
{
    emit disconnect_();
}

bool WorkerManager::get_registe_state() const
{
    return m_register_state;
}

void WorkerManager::push_back_manger(MangerModel *model)
{
    m_manger_model = model;
}

void WorkerManager::push_back_tennant(TennantModel *model)
{
    m_tennant_model = model;
}

void WorkerManager::push_back_owner(OwnerModel *model)
{
    m_owner_model = model;
}

void WorkerManager::push_back_real_estate(Real_estateModel *model)
{
    m_real_estate_model = model;
}


void WorkerManager::receive_login_state(bool login_state)
{
    m_login_state = login_state;
    emit login_stateChanged();
    qDebug() << "receive_login_state:"<<m_login_state;
}

void WorkerManager::receive_register_state(bool register_state)
{
    m_register_state = register_state;
    emit register_stateChanged();
}

void WorkerManager::receive_manger(QList<Manger> manger)
{
    m_manger_model->clear();//清空

    for(int i=0;i<manger.size();i++)
    {
        m_manger_model->addManger(manger[i]);
    }
}

void WorkerManager::receive_tennant(QList<Tennant> tennant)
{
    m_tennant_model->clear();

    for(int i=0;i<tennant.size();i++)
    {
        m_tennant_model->addTennant(tennant[i]);
    }
}

void WorkerManager::receive_owner(QList<Owner> owner)
{
    m_owner_model->clear();
    for(int i=0; i<owner.size();i++)
    {
        m_owner_model->addOwner(owner[i]);
    }
}

void WorkerManager::receive_real_estate(QList<Real_estate> real_estate)
{
    m_real_estate_model->clear();
    for(int i=0;i<real_estate.size();i++)
    {
        m_real_estate_model->addReal_estate(real_estate[i]);
    }
    qDebug() << "owner size:"<<m_real_estate_model->rowCount(QModelIndex());
}

