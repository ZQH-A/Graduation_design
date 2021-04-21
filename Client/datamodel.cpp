#include "datamodel.h"

DataModel::DataModel(QObject *parent) :QAbstractListModel(parent)
{

}

void DataModel::addData(const Data &data)
{
    beginInsertRows(QModelIndex(),rowCount(QModelIndex()),rowCount(QModelIndex()));
//    beginInsertRows();
    m_data<<data;
    endInsertRows();
}

int DataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if(index.row()<0 || index.row()>=m_data.count())
    {
        return QVariant();
    }

    const Data &data =m_data[index.row()];
    if(role == TypeRole)
    {
        return data.type();
    }else if(role == SizeRole)
    {
        return data.size();
    }
    return QVariant();
}

QVariantList DataModel::getHeaderList()
{
    QVariantList list;
    list.append("Type");
    list.append("Size");
    return list;
}

bool DataModel::isSqlModel()
{
    return true;
}

int DataModel::number()
{
    return m_data.count();
}

QHash<int, QByteArray> DataModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[TypeRole] = "Type";
    roles[SizeRole] ="Size";
    return roles;
}

