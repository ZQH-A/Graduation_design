#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H

#include <QThread>
#include <QObject>
#include "baseworker.h"
#include "tennantmodel.h"
#include "ownermodel.h"
#include "real_estatemodel.h"

class WorkerManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool login_state READ get_login_state NOTIFY login_stateChanged)
    Q_PROPERTY(bool register_state READ get_registe_state NOTIFY register_stateChanged)
public:
    WorkerManager(QObject *parent = nullptr);
    ~WorkerManager();//线程退出
    bool get_login_state() const;
    void disconnect_from_sever();
    bool get_registe_state() const;
    void push_back_manger(MangerModel *model);
    void push_back_tennant(TennantModel *model);
    void push_back_owner(OwnerModel *model);
    void push_back_real_estate(Real_estateModel *model);
signals:
   void manger_login(QString account,QString password);
   void init();
   void login_stateChanged();
   void register_stateChanged();
   void manger_register(QString account,QString password,QString name,QString tel);
   void showMangers(QString account,QString name,QString tel,QString sex);  //最开始的管理员显示和管理员查询
   void showTennants(QString search); //最开始的租客信息显示和 租客信息查询
   void showOwners(); // 显示业主信息
   void showReal_estate(); // 显示房产信息
   void disconnect_();//断开连接
   //添加租客                  房产                   房号        姓名         电话号码        身份证号         开始时间          结束时间     缴租周期        月租金          押金
   bool add_tennants(QString Real_estate,QString House_id,QString name,QString tel,QString ID_number, QString begin,QString end,QString cycle,QString month_rent,QString deposit);
public slots:
   void receive_login_state(bool login_state);
   void receive_register_state(bool register_state);
   void receive_manger(QList<Manger> manger);
   void receive_tennant(QList<Tennant> tennant);
   void receive_owner(QList<Owner> owner);
   void receive_real_estate(QList<Real_estate> real_estate);
private:
    bool m_login_state = false; //接收返回的登录状态
    bool m_register_state = false; // 接收返回的注册状态
    QThread mThread;
    BaseWorker mWorker;
    MangerModel *m_manger_model;
    TennantModel *m_tennant_model;
    OwnerModel *m_owner_model;
    Real_estateModel * m_real_estate_model;
};
#endif // WORKERMANAGER_H
