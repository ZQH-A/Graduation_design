#include "treenode.h"

TreeNode::TreeNode(const QList<QVariant> &data, TreeNode *parent)
{
    pParentNode = parent;
    mNodeData = data;
}

TreeNode::~TreeNode()
{
}

void TreeNode::appendChile(TreeNode *child)//添加子节点 并将其父节点设置为自己
{
    child->setParent(this);
    mChildeNodes.append(child);
}

void TreeNode::deleteAllChild()//删除该节点的全部子节点
{
    for(int index = 0; index <mChildeNodes.size(); index++)
    {
        mChildeNodes[index]->deleteAllChild();
    }
    qDeleteAll(mChildeNodes); //删除子节点占用的空间 相当于new 之后的 delete() 函数
    mChildeNodes.clear(); //
}

TreeNode *TreeNode::child(int row)//返回 第row 个孩子
{
    return mChildeNodes.value(row);
}

int TreeNode::childCount() const//返回当前孩子数
{
    return mChildeNodes.count();
}

int TreeNode::columnCount() const
{
    return mNodeData.count();
}

QVariant TreeNode::data(int column) const
{
    return mNodeData.value(column);
}

int TreeNode::row() const
{
    return pParentNode == nullptr ? 0: pParentNode->mChildeNodes.indexOf(const_cast<TreeNode*>(this));
}

TreeNode *TreeNode::parent()
{
    return pParentNode;
}

void TreeNode::setParent(TreeNode *parent)
{
    pParentNode = parent;
}

void TreeNode::setNodeData(QVariant data, int index)
{
    mNodeData[index] = data;
}
