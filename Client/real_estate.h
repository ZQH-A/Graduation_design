#ifndef REAL_ESTATE_H
#define REAL_ESTATE_H

#include <QString>

class Real_estate
{
public:
    Real_estate();
    Real_estate(int Real_estate_id,const QString &name,const QString &address,const QString &type);
    int Real_estate_id() const;
    QString name() const;
    QString address() const;
    QString type() const;
private:
    int m_real_estate_id;
    QString m_name;
    QString m_address;
    QString m_type;
};

#endif // REAL_ESTATE_H
