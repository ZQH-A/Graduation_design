#ifndef REAL_ESTATEMODEL_H
#define REAL_ESTATEMODEL_H

#include <QAbstractListModel>
#include "real_estate.h"

class Real_estateModel :public QAbstractListModel
{
    Q_OBJECT
public:
    Real_estateModel(QObject *parent = 0);

    enum Real_estateInfo{
        Real_estate_id = Qt::UserRole+1,
        NAME,
        ADDRESS,
        TYPE
    };

    void addReal_estate(const Real_estate &r);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    void clear();
    Q_INVOKABLE bool isSqlModel();
    Q_INVOKABLE QVariantList getHeaderList();

protected:
    QHash<int,QByteArray> roleNames() const;

private:
    QList<Real_estate> m_real_estate;
};

#endif // REAL_ESTATEMODEL_H
