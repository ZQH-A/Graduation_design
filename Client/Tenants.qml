import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.3
import QtQuick 2.0

//租客信息页
Item {
    Rectangle{
        anchors.fill: parent
        Rectangle{
            id:head_line
            width: parent.width
            height: 1
            anchors.left: parent.left
            color: "darkgray"
        }

        Label{
            id:position
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top:parent.top
            anchors.topMargin: 20
            text:"当前位置：人员管理> 租客档案"
        }
        Rectangle{
            id:line
            width: parent.width
            height: 1
            anchors.left: parent.left
            anchors.top: position.bottom
            anchors.topMargin: 10
            color: "darkgray"
        }

        TabView{
            id:tabview
            anchors.top:line.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom

            Tab{
                id:current
                title:"当前在租"
                source: "Current_Tenants.qml"
            }
            Tab{
                id:history
                title:"历史租客"
            }
        }
    }

}
