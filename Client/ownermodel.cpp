#include "ownermodel.h"

OwnerModel::OwnerModel(QObject *parent) :QAbstractListModel(parent)
{

}

void OwnerModel::addOwner(const Owner &o)
{
    beginInsertRows(QModelIndex(),rowCount(QModelIndex()),rowCount(QModelIndex()));
    m_onwer << o;
    endInsertRows();
}

int OwnerModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_onwer.count();
}

QVariant OwnerModel::data(const QModelIndex &index, int role) const
{
    if(index.row()<0 || index.row()>=m_onwer.count())
    {
        return QVariant();
    }

    const Owner &o = m_onwer[index.row()];

    if(role == NAME)
    {
        return o.name();
    }else if(role == Payment_account)
    {
        return o.payment_account();
    }else if(role == TEL)
    {
        return o.tel();
    }else if(role == Real_estate)
    {
        return o.real_estate();
    }else if(role == BEGIN)
    {
        return o.begin();
    }else if(role == END)
    {
        return o.end();
    }else if(role == DEPOSIT)
    {
        return o.deposit();
    }else if(role == CYCLE)
    {
        return o.cycle();
    }else if(role == Month_rent)
    {
        return o.month_rent();
    }else if(role == NOTE)
    {
        return o.note();
    }
    return QVariant();
}

void OwnerModel::clear()
{
    beginResetModel();
    m_onwer.clear();
    endResetModel();
}

int OwnerModel::number()
{
    return m_onwer.count();
}

bool OwnerModel::isSqlModel()
{
    return true;
}

QVariantList OwnerModel::getHeaderList()
{
    QVariantList list;
    list.append("姓名");
    list.append("关联房号");
    list.append("联系电话");
    list.append("起租日期");
    list.append("到租日期");
    list.append("每期租金");
    list.append("缴费周期");
    list.append("备注");
    list.append("押金");
    list.append("收款账号");
    return list;
}

QHash<int, QByteArray> OwnerModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[NAME] = "姓名";
    roles[Real_estate] = "关联房号";
    roles[TEL] = "联系电话";
    roles[BEGIN] = "起租日期";
    roles[END] = "到租日期";
    roles[Month_rent] = "每期租金";
    roles[CYCLE] = "缴费周期";
    roles[NOTE] = "备注";
    roles[DEPOSIT] = "押金";
    roles[Payment_account] = "收款账号";
    return roles;
}
