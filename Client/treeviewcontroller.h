#ifndef TREEVIEWCONTROLLER_H
#define TREEVIEWCONTROLLER_H

#include <QObject>
#include <treemodel.h>

class TreeViewController : public QObject
{
    Q_OBJECT
public:
    TreeViewController(QObject* parent = nullptr);
    ~TreeViewController();
public slots: // 被qml 调用
    Q_INVOKABLE QAbstractItemModel *getTreeModel();
private:
    TreeModel* m_TreeModel;
};

#endif // TREEVIEWCONTROLLER_H
