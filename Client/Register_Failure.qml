import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow{
    id:failure
    visible:true
    width: 380
    height: 180
    title: qsTr("房屋管理系统")

    Loader{
        id:pageLoader
    }

    Label{
        id:failure_title
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 10
        text:"注册失败"
        font.pointSize: 18
        color: "mediumturquoise"
    }
    Rectangle{
        id:rect
        width: failure.width
        height: 2
        anchors.left: parent.left
        anchors.top: failure_title.bottom
        anchors.topMargin: 10
        color: "mediumturquoise"
    }

    Label{
        id:failure_text
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: failure_title.bottom
        anchors.topMargin: 20
        font.pointSize: 14
        text:"该账号已被注册，注册失败"
    }

    Rectangle{  //自定义按钮
        id:login_failure
        width: failure.width/2
        height: 60
        border.color: "gainsboro"
        border.width: 1
        anchors.left:parent.left
        anchors.bottom: parent.bottom

        Text{
            id:login_failure_text
            anchors.centerIn: parent
            text:qsTr("再次注册")
            font.pointSize: 10
            font.bold: true
        }
        MouseArea{
            anchors.fill: login_failure
            onPressed: {
                failure.visible = false
            }
        }
    }

    Rectangle{  //自定义按钮
        id:return_home
        width: failure.width/2
        height: 60
        border.color: "gainsboro"
        border.width: 1
        anchors.left:login_failure.right
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
                console.log("click return_home")
                failure.visible = false
            }
        }
    }
}
