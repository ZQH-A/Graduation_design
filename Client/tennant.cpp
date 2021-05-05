#include "tennant.h"

Tennant::Tennant(QString name,QString Real_estate,QString House_id,QString tel,QString end,QString cycle,int month_rent,QString begin,int Payment_times,QString state)
{
    m_name = name;
    m_Real_estate = Real_estate;
    m_House_id = House_id;
    m_tel = tel;
    m_end = end;
    m_cycle = cycle;
    m_month_rent = month_rent;
    m_begin = begin;
    m_Payment_time = Payment_times;
    m_state = state;
}

Tennant::Tennant()
{

}

QString Tennant::name() const
{
    return m_name;
}

QString Tennant::Real_estate() const
{
    return m_Real_estate+"-"+m_House_id;
}

QString Tennant::tel() const
{
    return m_tel;
}

QString Tennant::end() const
{
    return m_end;
}

QString Tennant::cycle() const
{
    return m_cycle;
}

QString Tennant::month_rent() const
{
    return QString::number(m_month_rent);
}

QString Tennant::ruzhu() const
{
    return "未知";
}

QString Tennant::payment_times() const
{
    return QString::number(m_Payment_time);
}

QString Tennant::state() const
{
    return m_state;
}

int Tennant::number()
{
    return 9;
}
