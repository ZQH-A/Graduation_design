#include "owner.h"

Owner::Owner(const QString &name, const QString &payment_account, const QString &tel, const QString &real_estate, const QString &begin, const QString &end, int deposit, const QString &cycle, int month_rent, const QString &note)
{
    m_name = name;
    m_payment_account = payment_account;
    m_tel = tel;
    m_real_estate = real_estate;
    m_begin = begin;
    m_end = end;
    m_deposit =deposit;
    m_cycle = cycle;
    m_month_rent = month_rent;
    m_note = note;
}

Owner::Owner()
{

}

QString Owner::name() const
{
    return m_name;
}

QString Owner::payment_account() const
{
    return m_payment_account;
}

QString Owner::tel() const
{
    return m_tel;
}

QString Owner::real_estate() const
{
    return m_real_estate;
}

QString Owner::begin() const
{
    return m_begin;
}

QString Owner::end() const
{
    return m_end;
}

QString Owner::deposit() const
{
    return QString::number(m_deposit);
}

QString Owner::cycle() const
{
    return m_cycle;
}

QString Owner::month_rent() const
{
    return QString::number(m_month_rent);
}

QString Owner::note() const
{
    return m_note;
}
