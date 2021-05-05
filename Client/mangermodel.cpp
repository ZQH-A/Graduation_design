#include "mangermodel.h"

MangerModel::MangerModel(QObject *parent):QAbstractListModel(parent)
{

}

void MangerModel::addManger(const Manger &m)
{
    beginInsertRows(QModelIndex(),rowCount(QModelIndex()),rowCount(QModelIndex()));
    m_manger<<m;
    endInsertRows();
}

int MangerModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_manger.count();
}

QVariant MangerModel::data(const QModelIndex &index, int role) const
{
    if(index.row()<0 || index.row()>=m_manger.count())
    {
        return QVariant();
    }
    const Manger &m = m_manger[index.row()];
    if(role == ACCOUNT)
    {
        return m.account();
    }else if(role == PASSWORD)
    {
        return m.password();
    }else if(role == NAME)
    {
        return m.name();
    }else if(role == TEL)
    {
        return m.tel();
    }else if(role == SEX)
    {
        return m.sex();
    }
    return QVariant();
}

QVariantList MangerModel::getHeaderList()
{
    QVariantList list;
    list.append("账号");
    list.append("密码");
    list.append("姓名");
    list.append("电话号码");
    list.append("性别");
    return list;
}

bool MangerModel::isSqlModel()
{
    return true;
}

int MangerModel::number()
{
    if(m_manger.size())
    {
        return m_manger[0].number();
    }
    return 0;
}

QHash<int, QByteArray> MangerModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[ACCOUNT] = "账号";
    roles[PASSWORD] = "密码";
    roles[NAME] = "姓名";
    roles[TEL] = "电话号码";
    roles[SEX] = "性别";
    return roles;
}
