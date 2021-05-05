import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    Rectangle{
        anchors.fill: parent
        color: "white"
        Add_Tennants{
            id:add_tennants
            visible: false
        }

        Rectangle{
            id:button_
            height: 40
            width: parent.width
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 20

            Rectangle{  //自定义按钮
                id:date
                width: 120
                height: 40
                anchors.left: parent.left
                anchors.leftMargin: 40
                border.color: "#e7eaec"
                border.width: 1
                radius: 3
                color:"#5787e7"
                Image {
                    id: up_and_down
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/up_and_down_1.png"
                }
                Text{
                    id:date_text
                    anchors.left: up_and_down.right
                    anchors.verticalCenter: up_and_down.verticalCenter
                    text:qsTr("按到期日")
                    color:"white"
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        console.log("click")
                    }
                }
            }

            Rectangle{  //自定义按钮
                id:house
                width: 80
                height: date.height
                anchors.left: date.right
                anchors.verticalCenter: date.verticalCenter
                border.color: "#e7eaec"
                border.width: 1
                radius: date.radius
                color:"#f5f5f5"
                Image {
                    id:up_and_down_1
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/up_and_down_1.png"
                }
                Text{
                    id:house_text
                    anchors.left: up_and_down_1.right
                    anchors.verticalCenter: up_and_down_1.verticalCenter
                    text:qsTr("按房产")
                    color:"black"
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        console.log("click")
                    }
                }
            }
            Rectangle{  //自定义按钮
                id:check_in
                width: 120
                height: 40
                anchors.left: house.right
                anchors.verticalCenter: date.verticalCenter
                border.color: "#e7eaec"
                border.width: 1
                color:"#f5f5f5"
                Image {
                    id:up_and_down_2
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/up_and_down_1.png"
                }
                Text{
                    id:check_in_text
                    anchors.left: up_and_down_2.right
                    anchors.verticalCenter: up_and_down_2.verticalCenter
                    text:qsTr("按入住日期")
                    color:"black"
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        console.log("click")
                    }
                }
            }

            Rectangle{  //自定义按钮
                id:add
                width: 100
                height: date.height
                anchors.left: check_in.right
                anchors.leftMargin: 20
                anchors.verticalCenter: date.verticalCenter
                radius: date.radius
                color:"#5787e7"
                Image {
                    id:up_and_down_3
                    anchors.left: parent.left
                    anchors.leftMargin: 15
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/add_tennant.png"
                }
                Text{
                    id:add_text
                    anchors.left: up_and_down_3.right
                    anchors.verticalCenter: up_and_down_3.verticalCenter
                    text:qsTr("添加租客")
                    color:"white"
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        console.log("click")
                        add_tennants.visible = true
                    }
                }
            }

            Rectangle{  //自定义按钮
                id:print_
                width: 100
                height: date.height
                anchors.left: add.right
                anchors.leftMargin: 15
                anchors.verticalCenter: date.verticalCenter
                radius: date.radius
                color:"#5787e7"
                Image {
                    id:up_and_down_4
                    anchors.left: parent.left
                    anchors.leftMargin: 30
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/print.png"
                }
                Text{
                    id:print_text
                    anchors.left: up_and_down_4.right
                    anchors.verticalCenter: up_and_down_4.verticalCenter
                    text:qsTr("打印")
                    color:"white"
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        console.log("click")
                    }
                }
            }


            Rectangle{  //自定义按钮
                id:export_
                width: 120
                height: date.height
                anchors.left: print_.right
                anchors.leftMargin: 15
                anchors.verticalCenter: date.verticalCenter
                radius: date.radius
                color:"#5787e7"
                Image {
                    id:up_and_down_5
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/export.png"
                }
                Text{
                    id:export_text
                    anchors.left: up_and_down_5.right
                    anchors.verticalCenter: up_and_down_5.verticalCenter
                    text:qsTr("导出租客信息")
                    color:"white"
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        console.log("click")
                    }
                }
            }

            TextField{
                id:search
                anchors.left: export_.right
                anchors.leftMargin: 50
                anchors.verticalCenter: date.verticalCenter
                 placeholderText: qsTr("房产/房号/租客姓名/手机号码")
                width: 350
                height: 40
            }

            Rectangle{  //自定义按钮
                id:search_button
                width: 70
                height: 40
                anchors.left: search.right
                anchors.verticalCenter: date.verticalCenter
                color:"#5787e7"
                radius: date.radius
                Image {
                    id:up_and_down_6
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/search.png"
                }
                Text{
                    id:search_button_text
                    anchors.left: up_and_down_6.right
                    anchors.verticalCenter: up_and_down_6.verticalCenter
                    text:qsTr("搜索")
                    color:"white"
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        console.log("搜索")
                        worker.showTennants(search.text)
                    }
                }
            }
        }

        Rectangle{
            id:title
            anchors.top: button_.bottom
            anchors.topMargin: 20
            anchors.left: parent.left
            width: parent.width
            anchors.bottom: parent.bottom
            anchors.right: parent.right

            DataTable_Button{
                id:tenants
                anchors.fill: parent
                headerList: ["姓名","房产-房号","联系电话","到租日期","缴费周期","每期缴租","入住天数","缴费次数","缴费情况"]
                columnsWidth:parent.width/11
                parent_width: parent.width
                model:tModel
            }
        }
    }
}
