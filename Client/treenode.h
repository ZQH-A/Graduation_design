#ifndef TREENODE_H
#define TREENODE_H
//导航栏中的每一个节点
#include <QList>
#include <QVariant>


class TreeNode
{
public:
    TreeNode(const QList<QVariant> &data, TreeNode *parent);
    ~TreeNode();

    void appendChile(TreeNode *child); //添加子节点
    void deleteAllChild(); // 删除全部子节点

    TreeNode *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeNode *parent();
    void setParent(TreeNode *parent);

    void setNodeData(QVariant data, int index);

private:
    TreeNode *pParentNode;   //父节点
    QList<TreeNode *> mChildeNodes;  //子节点
    QList<QVariant> mNodeData;//QVariant  集合类型
};

#endif // TREENODE_H
