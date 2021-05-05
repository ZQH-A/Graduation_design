#ifndef MANGER_H
#define MANGER_H

#include <QString>

class Manger
{
public:
    Manger(const QString &account,const QString &password,const QString &name, const QString &tel,const QString &sex);
    Manger();
    QString account() const;
    QString password() const;
    QString name() const;
    QString tel() const;
    int number() const;
    QString sex() const;
private:
    QString m_account;
    QString m_password;
    QString m_name;
    QString m_tel;
    QString m_sex;
};

#endif // MANGER_H
