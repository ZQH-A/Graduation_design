#include "treeviewcontroller.h"

TreeViewController::TreeViewController(QObject *parent)
{
    m_TreeModel = new TreeModel();
}

TreeViewController::~TreeViewController()
{
    delete m_TreeModel;
}

QAbstractItemModel* TreeViewController::getTreeModel()
{
    return m_TreeModel;
}
