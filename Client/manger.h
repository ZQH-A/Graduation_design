#ifndef MANGER_H
#define MANGER_H

#include <QString>

class Manger
{
public:
    Manger(const QString &account,const QString &password,const QString &name, const QString &tel);
    QString account() const;
    QString password() const;
    QString name() const;
    QString tel() const;
    int number() const;
private:
    QString m_account;
    QString m_password;
    QString m_name;
    QString m_tel;
};

#endif // MANGER_H
