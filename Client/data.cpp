#include "data.h"

Data::Data(const QString &type, const QString &size) :m_type(type),m_size(size)
{

}

QString Data::type() const
{
    return m_type;
}

QString Data::size() const
{
    return m_size;
}

