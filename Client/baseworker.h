#ifndef BASEWORKER_H
#define BASEWORKER_H

#include <QVariant>
#include <QObject>
#include <QRunnable>
#include "dataencapsulation.h"


class BaseWorker :public QObject
{
    Q_OBJECT
public:
    BaseWorker(QObject *parent = nullptr);

public slots:
    void manger_login(QString account,QString password); //处理函数
    void manger_register(QString account,QString password,QString name,QString tel);
    void init();
    void disconnect_();
    void showMangers(QString account,QString name,QString tel,QString sex); //管理员信息显示和查询
    void showTennants(QString search); // 租客信息显示和查询
    void showOwners(); //业主信息查询
    void showReal_estate(); //显示房产信息
    bool add_tennants(QString Real_estate,QString House_id,QString name,QString tel,QString ID_number, QString begin,QString end,QString cycle,QString month_rent,QString deposit);
signals:
    void processFinished();
    void login_state_change(bool login_state);
    void register_state_change(bool register_state);
    void update_manger(QList<Manger> manger);
    void update_tennant(QList<Tennant> tennant);
    void update_owner(QList<Owner> owner);
    void update_real_estate(QList<Real_estate> real_estate);
private:
    DataEncapsulation *dataEncapsulation;
    bool m_login_state;
    bool m_register_state;
};

#endif // BASEWORKER_H
