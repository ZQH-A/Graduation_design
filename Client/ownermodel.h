#ifndef OWNERMODEL_H
#define OWNERMODEL_H

#include <QAbstractListModel>
#include "owner.h"

class OwnerModel :public QAbstractListModel
{
    Q_OBJECT
public:
    OwnerModel(QObject *parent = 0);

    enum OwnerInfo{
        NAME = Qt::UserRole+1,
        Payment_account,
        TEL,
        Real_estate,
        BEGIN,
        END,
        DEPOSIT,
        CYCLE,
        Month_rent,
        NOTE
    };

    void addOwner(const Owner &o);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void clear();

    Q_INVOKABLE int number();
    Q_INVOKABLE bool isSqlModel();
    Q_INVOKABLE QVariantList getHeaderList();
protected:
    QHash<int,QByteArray> roleNames() const;
private:
    QList<Owner> m_onwer;
};

#endif // OWNERMODEL_H
