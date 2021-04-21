import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.3
import QtQuick 2.3

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
            text:"当前位置：首页"
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
    }
}
