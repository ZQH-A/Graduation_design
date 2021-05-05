#include "manger.h"

Manger::Manger(const QString &account,const QString &password,const QString &name, const QString &tel,const QString &sex)
{
    m_account = account;
    m_password = password;
    m_name = name;
    m_tel = tel;
    m_sex = sex;
}

Manger::Manger()
{

}

QString Manger::account() const
{
    return m_account;
}

QString Manger::password() const
{
    return m_password;
}

QString Manger::name() const
{
    return m_name;
}

QString Manger::tel() const
{
    return m_tel;
}

int Manger::number() const
{
    return 5;
}

QString Manger::sex() const
{
    return m_sex;
}
