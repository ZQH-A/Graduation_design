#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QAbstractListModel>
#include "data.h"

class DataModel :public QAbstractListModel
{
    Q_OBJECT
public:
    DataModel(QObject *parent = 0);
    enum AnimalRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };

    void addData(const Data &data);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void clear()
    {
        beginResetModel();
        m_data.clear();
        endResetModel();
    }
    Q_INVOKABLE QVariantList getHeaderList();
    Q_INVOKABLE bool isSqlModel();
    Q_INVOKABLE int number();
protected:
    QHash<int,QByteArray> roleNames() const;
private:
    QList<Data> m_data;
};

#endif // DATAMODEL_H
