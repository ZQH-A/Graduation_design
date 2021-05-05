#ifndef MANGERMODEL_H
#define MANGERMODEL_H

#include <QAbstractListModel>
#include "manger.h"

class MangerModel :public QAbstractListModel
{
    Q_OBJECT
public:
    MangerModel(QObject *parent = 0);
    enum MangerInfo{
        ACCOUNT = Qt::UserRole+1,
        PASSWORD,
        NAME,
        TEL,
        SEX
    };

    void addManger(const Manger &m);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void clear()
    {
        beginResetModel();
        m_manger.clear();
        endResetModel();
    }

    Q_INVOKABLE QVariantList getHeaderList();
    Q_INVOKABLE bool isSqlModel();
    Q_INVOKABLE int number();

protected:
    QHash<int,QByteArray> roleNames() const;
private:
    QList<Manger> m_manger;
};

#endif // MANGERMODEL_H
