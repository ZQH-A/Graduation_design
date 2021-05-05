#include "real_estate.h"

Real_estate::Real_estate()
{

}

Real_estate::Real_estate(int Real_estate_id, const QString &name, const QString &address, const QString &type)
{
    m_real_estate_id = Real_estate_id;
    m_name = name;
    m_address = address;
    m_type = type;
}

int Real_estate::Real_estate_id() const
{
    return m_real_estate_id;
}

QString Real_estate::name() const
{
    return m_name;
}

QString Real_estate::address() const
{
    return m_address;
}

QString Real_estate::type() const
{
    return m_type;
}
