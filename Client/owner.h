#ifndef OWNER_H
#define OWNER_H

#include <QString>

class Owner
{
public:
    Owner(const QString &name,const QString &payment_account,const QString &tel,const QString &real_estate,const QString &begin,const QString &end,int deposit,const QString &cycle,int month_rent,const QString &note);
    Owner();
    QString name() const;
    QString payment_account() const;
    QString tel() const;
    QString real_estate() const;
    QString begin() const;
    QString end() const;
    QString deposit() const;
    QString cycle() const;
    QString month_rent() const;
    QString note() const;

private:
    QString m_name;
    QString m_payment_account;
    QString m_tel;
    QString m_real_estate;
    QString m_begin;
    QString m_end;
    int m_deposit;
    QString m_cycle;
    int m_month_rent;
    QString m_note;
};

#endif // OWNER_H
