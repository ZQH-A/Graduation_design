#ifndef TENNANTMODEL_H
#define TENNANTMODEL_H

#include <QAbstractListModel>
#include "tennant.h"


class TennantModel :public QAbstractListModel
{
    Q_OBJECT
public:
    TennantModel(QObject *parent = 0);

    enum TennantInfo{
        NAME = Qt::UserRole+1,
        Real_estate,
        TEL,
        END,
        CYCLE,
        Month_rent,
        RUZHU,
        Payment_time,
        STATE,
    };

    void addTennant(const Tennant &t);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void clear();

    Q_INVOKABLE QVariantList getHeaderList();
    Q_INVOKABLE bool isSqlModel();
    Q_INVOKABLE int number();
protected:
    QHash<int,QByteArray> roleNames() const;
private:
    QList<Tennant> m_tennant;
};

#endif // TENNANTMODEL_H
