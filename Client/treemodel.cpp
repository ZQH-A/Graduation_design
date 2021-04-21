#include "treemodel.h"

TreeModel::TreeModel(QObject *parent) : QAbstractItemModel(parent)
{//初始化
    QList<QVariant> list;
    list.append("RootNode");
    pRootNode = new TreeNode(list, NULL);

    QList<QVariant> list_Home_page;//首页
    list_Home_page.append(QString("首页"));
    auto item_Home_Page= new TreeNode(list_Home_page,pRootNode);
    pRootNode->appendChile(item_Home_Page);

    QList<QVariant> list_Office_management;//房产管理
    list_Office_management.append(QString("房产管理"));
    auto item_o_m = new TreeNode(list_Office_management,pRootNode);
    pRootNode->appendChile(item_o_m);
    QList<QVariant> list_P_R;//基本管理
    list_P_R.append(QString("基本管理"));
    auto item_P_R = new TreeNode(list_P_R, item_o_m);
    item_o_m->appendChile(item_P_R);

    QList<QVariant> list_S_R;//人员管理
    list_S_R.append(QString("人员管理"));
    auto item_S_R = new TreeNode(list_S_R,pRootNode);
    pRootNode->appendChile(item_S_R);
    QList<QVariant> list_A_L_L; //系统用户管理
    list_A_L_L.append(QString("系统用户管理"));
    auto item_A_L_L = new TreeNode(list_A_L_L,item_S_R);
    item_S_R->appendChile(item_A_L_L);
    QList<QVariant> list_t_f; // 租客档案
    list_t_f.append(QString("租客档案"));
    auto item_t_f = new TreeNode(list_t_f,item_S_R);
    item_S_R->appendChile(item_t_f);
    QList<QVariant> list_owner;// 业主管理
    list_owner.append(QString("业主管理"));
    auto item_owner = new TreeNode(list_owner,item_S_R);
    item_S_R->appendChile(item_owner);


    QList<QVariant> list_bill;// 我的账单
    list_bill.append(QString("我的账本"));
    auto item_bill = new TreeNode(list_bill,pRootNode);
    pRootNode->appendChile(item_bill);
    QList<QVariant> list_payments;//收支流水
    list_payments.append(QString("收支流失"));
    auto item_payments = new TreeNode(list_payments,item_bill);
    item_bill->appendChile(item_payments);
    QList<QVariant> list_statistical;//收支统计
    list_statistical.append("收支统计");
    auto item_statistical = new TreeNode(list_statistical,item_bill);
    item_bill->appendChile(item_statistical);


    QList<QVariant> list_maintenance;//报表管理
    list_maintenance.append("报表管理");
    auto item_maintenance = new TreeNode(list_maintenance,pRootNode);
    pRootNode->appendChile(item_maintenance);
    QList<QVariant> list_business; //经营报表
    list_business.append("经营报表");
    auto item_business = new TreeNode(list_business,item_maintenance);
    item_maintenance->appendChile(item_business);
    QList<QVariant> list_house;//房产报表
    list_house.append("房产报表");
    auto item_house = new TreeNode(list_house,item_maintenance);
    item_maintenance->appendChile(item_house);
    QList<QVariant> list_Meter;//抄表记录
    list_Meter.append("抄表记录");
    auto item_Meter = new TreeNode(list_Meter,item_maintenance);
    item_maintenance->appendChile(item_Meter);
    QList<QVariant> list_W_E;//水电总表
    list_W_E.append("水电总表");
    auto item_W_E = new TreeNode(list_W_E,item_maintenance);
    item_maintenance->appendChile(item_W_E);
    QList<QVariant> list_spare;//闲置房号报表
    list_spare.append("闲置房号");
    auto item_spare = new TreeNode(list_spare,item_maintenance);
    item_maintenance->appendChile(item_spare);

    QList<QVariant> list_operations;//系统设置
    list_operations.append("系统设置");
    auto item_operations = new TreeNode(list_operations,pRootNode);
    pRootNode->appendChile(item_operations);
    QList<QVariant> list_bill_print;//账单打印设置
    list_bill_print.append("账单打印设置");
    auto iten_bill_print  = new TreeNode(list_bill_print,item_operations);
    item_operations->appendChile(iten_bill_print);
    QList<QVariant> list_account; //收款账户
    list_account.append("收款账户");
    auto item_account = new TreeNode(list_account,item_operations);
    item_operations->appendChile(item_account);


    QList<QVariant> list_Analysis;//帮助文档
    list_Analysis.append("帮助文档");
    auto item_Analysis = new TreeNode(list_Analysis,pRootNode);
    pRootNode->appendChile(item_Analysis);

    QList<QVariant> list_management;//系统公告
    list_management.append("系统公告");
    auto item_management = new TreeNode(list_management,pRootNode);
    pRootNode->appendChile(item_management);     

}

TreeModel::~TreeModel() //析构
{
    pRootNode->deleteAllChild();
    delete pRootNode;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    return 1;
    if(parent.isValid())
    {
        return static_cast<TreeNode *>(parent.internalPointer())->columnCount();
    }
    else
    {
        return pRootNode->columnCount();
    }
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeNode *parentNode;
    if(parent.column() >0)
    {
        return 0;
    }
    if(!parent.isValid())
    {
        parentNode = pRootNode;
    }
    else
    {
        parentNode = static_cast<TreeNode *>(parent.internalPointer());
    }
    return parentNode->childCount();
}

QHash<int, QByteArray> TreeModel::roleNames() const
{
    QHash<int, QByteArray> names(QAbstractItemModel::roleNames());
    names[NAME] = "name";
    return names;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    switch (role) {

    case NAME:
        return static_cast<TreeNode *>(index.internalPointer())->data(0);
    }
    return QVariant();
}

Qt::ItemFlags TreeModel::flags(const QModelIndex & index) const
{
    if(!index.isValid())
    {
        return 0;
    }
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column, parent))
    {
        return QModelIndex();
    }

    TreeNode *parentNode;
    if(!parent.isValid())
    {
        parentNode = pRootNode;
    }
    else
    {
        parentNode = static_cast<TreeNode  *> (parent.internalPointer());
    }

    TreeNode *childNode = parentNode->child(row);
    if(childNode)
    {
        return createIndex(row, column, childNode);
    }
    else
    {
        return QModelIndex();
    }
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return QModelIndex();
    }

    TreeNode *childNode = static_cast<TreeNode *>(index.internalPointer());
    TreeNode *parentNode = childNode->parent();

    if(parentNode == pRootNode)
    {
        return QModelIndex();
    }
    return createIndex(parentNode->row(),0,parentNode);
}
