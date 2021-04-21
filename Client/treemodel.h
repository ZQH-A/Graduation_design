#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include <QObject>
#include "treenode.h"

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

    enum nodeRoles{
        NAME = Qt::UserRole +1
    };
public:
    TreeModel(QObject *parent = nullptr);
    ~TreeModel();

//    void appendChild(const QModelIndex& index, QList<QVariant> dataList, int count);
//    void setNodeName(QString appendName,QModelIndex index);

    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;

private:
    TreeNode *pRootNode; //根节点
};

#endif // TREEMODEL_H
