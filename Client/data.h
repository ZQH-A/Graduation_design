#ifndef DATA_H
#define DATA_H

#include <QString>

class Data
{
public:
    Data(const QString &type, const QString &size);
    QString type() const;
    QString size() const;
private:
    QString m_type;
    QString m_size;
};

#endif // DATA_H
