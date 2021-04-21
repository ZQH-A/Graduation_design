#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "treeviewcontroller.h"
#include "simpletcpsocketclient.h"
#include "dataencapsulation.h"
#include "mangermodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TreeViewController treeViewController;	//理解析构顺序很重要

    DataEncapsulation data;

    MangerModel mangermodel;


    data.push_back_manger(&mangermodel);
    data.display_user_infor();

    //qml 与 c++ 交互
    engine.rootContext()->setContextProperty("mControl", &treeViewController);

    engine.rootContext()->setContextProperty("dataEncapsulation",&data);

    engine.rootContext()->setContextProperty("mModel",&mangermodel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    if (engine.rootObjects().isEmpty())
        return -1;

    int ret= app.exec();
    data.disconnect();
    return ret;
}
