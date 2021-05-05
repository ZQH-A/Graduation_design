#include "connectionpool.h"
#include <QSqlQuery>
#include <QSqlError>

QMutex ConnectionPool::mutex;
QWaitCondition ConnectionPool::waitConnection;
ConnectionPool* ConnectionPool::instance =NULL;

void ConnectionPool::release()
{//删除数据的所有连接
    QMutexLocker locker(&mutex);
    delete instance;
    instance = NULL;
}

QSqlDatabase ConnectionPool::openConnection()
{
    ConnectionPool & pool = ConnectionPool::getInstance();
    QString connectionName;

    QMutexLocker locker(&mutex);

    //已创建的连接数
    int connectionCount = pool.unusedConnectionNames.size() + pool.usedConnectionNames.size();

    //如果连接已经用完，等待 waitInterbal 毫秒看看是否有可用连接，最长等待 maxWaitTime 毫秒
    for(int i=0;i<pool.maxWaitTime && pool.unusedConnectionNames.size() == 0 && connectionCount == pool.maxConnectionCount; i+= pool.waitInterval)
    {
        waitConnection.wait(&mutex ,pool.waitInterval);

        //重新计算已创建连接数
        connectionCount = pool.unusedConnectionNames.size() + pool.unusedConnectionNames.size();
    }

    if(pool.unusedConnectionNames.size() > 0)
    {
        //有已经收回的连接，复用它们
        connectionName = pool.unusedConnectionNames.dequeue();
    }else if(connectionCount < pool.maxConnectionCount)
    {
        //没有已经回收的连接，但是没有达到最大连接数，则创建新的连接
        connectionName = QString("Connection-%1").arg(connectionCount +1);
    }else{
        //已经达到最大连接数
        qDebug() << "Cannot create more connections.";
        return QSqlDatabase();
    }

    //创建连接
    QSqlDatabase db = pool.createConnection(connectionName);

    //有效的连接才放入 usedConnectionNames
    if(db.isOpen())
    {
        pool.usedConnectionNames.enqueue(connectionName);
    }
    return db;
}

void ConnectionPool::closeConnection(QSqlDatabase connection)
{
    ConnectionPool& pool = ConnectionPool::getInstance();
    QString connectionName = connection.connectionName();
    //如果是我们创建的连接，从used 里删除，放入 unused里
    if(pool.usedConnectionNames.contains(connectionName))
    {
        QMutexLocker locker(&mutex);
        pool.usedConnectionNames.removeOne(connectionName);
        pool.unusedConnectionNames.enqueue(connectionName);
        waitConnection.wakeOne();
    }
}

ConnectionPool::~ConnectionPool()
{//销毁连接池的时候删除所有的连接
    foreach (QString connectionName, usedConnectionNames) {
        QSqlDatabase::removeDatabase(connectionName);
    }
    foreach (QString connectionName, unusedConnectionNames) {
        QSqlDatabase::removeDatabase(connectionName);
    }
}

ConnectionPool &ConnectionPool::getInstance()
{//单例模式
    if(NULL == instance)
    {
        QMutexLocker locker(&mutex);

        if(NULL == instance)
        {
            instance = new ConnectionPool();
        }
    }
    return *instance;
}

ConnectionPool::ConnectionPool()
{//创建数据库连接的信息在实际开发的时都需要通过读取配置文件得到
    hostName = "localhost";
    databaseName = "info";
    userName = "root";
    password = "root";
    databaseType = "QMYSQL";
    testOnBorrow = true;
    testOnBorrowSql = "select 1";

    maxWaitTime = 1000;
    waitInterval = 200;
    maxConnectionCount = 5;
}

QSqlDatabase ConnectionPool::createConnection(const QString &connectionName)
{//连接已经创建过了，复用它，而不是重新创建
    if(QSqlDatabase::contains(connectionName))
    {
        QSqlDatabase db1 = QSqlDatabase::database(connectionName);

        if(testOnBorrow)
        {//返回连接前访问数据库，如果连接断开，重新建立连接
            qDebug() << "Test connection on borrow,execute:"<<testOnBorrowSql<<",for"<<connectionName;
            QSqlQuery query(testOnBorrowSql,db1);

            if(query.lastError().type() != QSqlError::NoError && !db1.open())
            {
                qDebug() << "Open database error:"<<db1.lastError().text();
                return QSqlDatabase();
            }
        }
        return db1;
    }

    //创建一个新的连接
    QSqlDatabase db = QSqlDatabase::addDatabase(databaseType,connectionName);
    db.setHostName(hostName);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);

    if(!db.open())
    {
        qDebug()<< "Open database error:"<< db.lastError().text();
        return QSqlDatabase();
    }
    return db;
}
