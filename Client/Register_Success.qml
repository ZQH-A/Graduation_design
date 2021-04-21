import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow{
    id:success
    visible:true
    width: 380
    height: 180
    title: qsTr("房屋管理系统")

    Loader{
        id:pageLoader
    }

    Label{
        id:success_title
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 10
        text:"注册成功"
        font.pointSize: 18
        color: "mediumturquoise"
    }
    Rectangle{
        id:rect
        width: success.width
        height: 2
        anchors.left: parent.left
        anchors.top: success_title.bottom
        anchors.topMargin: 10
        color: "mediumturquoise"
    }

    Label{
        id:success_text
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: success_title.bottom
        anchors.topMargin: 20
        font.pointSize: 14
        text:"注册成功"
    }

    Rectangle{  //自定义按钮
        id:login_success
        width: success.width/2
        height: 60
        border.color: "gainsboro"
        border.width: 1
        anchors.left:parent.left
        anchors.bottom: parent.bottom

        Text{
            id:login_success_text
            anchors.centerIn: parent
            text:qsTr("直接登录")
            font.pointSize: 10
            font.bold: true
        }
        MouseArea{
            anchors.fill: login_success
            onPressed: {
                success.close()
                register.close()
                pageLoader.source="MainPage.qml"
            }
        }
    }

    Rectangle{  //自定义按钮
        id:return_home
        width: success.width/2
        height: 60
        border.color: "gainsboro"
        border.width: 1
        anchors.left:login_success.right
        anchors.bottom: parent.bottom

        Text{
            id:return_home_text
            anchors.centerIn: parent
            text:qsTr("返回首页")
            font.pointSize: 10
            font.bold: true
        }
        MouseArea{
            anchors.fill: return_home
            onPressed: {
                console.log("click")
            }
        }
    }
}
