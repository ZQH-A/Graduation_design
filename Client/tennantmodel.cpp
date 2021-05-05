#include "tennantmodel.h"

TennantModel::TennantModel(QObject *parent) :QAbstractListModel(parent)
{

}

void TennantModel::addTennant(const Tennant &t)
{
    beginInsertRows(QModelIndex(),rowCount(QModelIndex()),rowCount(QModelIndex()));
    m_tennant<< t;
    endInsertRows();
}

int TennantModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_tennant.count();
}

QVariant TennantModel::data(const QModelIndex &index, int role) const
{
    if(index.row()<0 || index.row()>=m_tennant.count())
    {
        return QVariant();
    }
    const Tennant &t = m_tennant[index.row()];
    if(role == NAME)
    {
        return t.name();
    }else if(role == Real_estate)
    {
        return t.Real_estate();
    }else if(role == TEL)
    {
        return t.tel();
    }else if(role == END)
    {
        return t.end();
    }else if(role == CYCLE)
    {
        return t.cycle();
    }else if(role == Month_rent)
    {
        return t.month_rent();
    }else if(role == RUZHU)
    {
        return t.ruzhu();
    }else if(role == Payment_time)
    {
        return t.payment_times();
    }else if(role == STATE)
    {
        return t.state();
    }
    return QVariant();
}

void TennantModel::clear()
{
    beginResetModel();
    m_tennant.clear();
    endResetModel();
}

QVariantList TennantModel::getHeaderList()
{
    QVariantList list;
    list.append("姓名");
    list.append("房产-房号");
    list.append("联系电话");
    list.append("到租日期");
    list.append("缴费周期");
    list.append("每期缴租");
    list.append("入住天数");
    list.append("缴费次数");
    list.append("缴费情况");
    return list;
}

bool TennantModel::isSqlModel()
{
    return true;
}

int TennantModel::number()
{
    if(m_tennant.size())
    {
        m_tennant[0].number();
    }
    return 0;
}

QHash<int, QByteArray> TennantModel::roleNames() const
{
    QHash<int,QByteArray> roles;
    roles[NAME] = "姓名";
    roles[Real_estate] = "房产-房号";
    roles[TEL] = "联系电话";
    roles[END] = "到租日期";
    roles[CYCLE] = "缴费周期";
    roles[Month_rent] = "每期缴租";
    roles[RUZHU] = "入住天数";
    roles[Payment_time] = "缴费次数";
    roles[STATE] = "缴费情况";
    return roles;
}
