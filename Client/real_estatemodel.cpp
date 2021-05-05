#include "real_estatemodel.h"

Real_estateModel::Real_estateModel(QObject *parent):QAbstractListModel(parent)
{

}

void Real_estateModel::addReal_estate(const Real_estate &r)
{
    beginInsertRows(QModelIndex(),rowCount(QModelIndex()),rowCount(QModelIndex()));
    m_real_estate << r;
    endInsertRows();
}

int Real_estateModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_real_estate.count();
}

QVariant Real_estateModel::data(const QModelIndex &index, int role) const
{
    if(index.row()<0 || index.row()>=m_real_estate.count())
    {
        return QVariant();
    }
    const Real_estate &r = m_real_estate[index.row()];

    if(role == Real_estate_id)
    {
        return r.Real_estate_id();
    }else if(role == NAME)
    {
        return r.name();
    }else if(role == ADDRESS)
    {
        return r.address();
    }else if(role == TYPE)
    {
        return r.type();
    }
    return QVariant();
}

void Real_estateModel::clear()
{
    beginResetModel();
    m_real_estate.clear();
    endResetModel();
}

bool Real_estateModel::isSqlModel()
{
    return true;
}

QVariantList Real_estateModel::getHeaderList()
{
    QVariantList list;
    list.append("ID");
    list.append("房产名");
    list.append("详细地址");
    list.append("房产类型");
    return list;
}

QHash<int, QByteArray> Real_estateModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[Real_estate_id] = "ID";
    roles[NAME] = "房产名";
    roles[ADDRESS] = "详细地址";
    roles[TYPE] = "房产类型";
    return roles;
}
