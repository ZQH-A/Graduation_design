import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.3
import QtQuick 2.3

//房屋管理页面
Item {

    Rectangle{
        anchors.fill: parent
        Rectangle{//
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
            text:"当前位置：房屋管理> 基本管理"
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

        Rectangle{//搜索两个字
            id:search
            width: parent.width
            height: 50
            anchors.top:line.bottom
            anchors.topMargin: 30
            color: "#044599"
            Label{
                anchors.left: parent.left
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                text:"搜索"
                color: "white"
                font.pointSize: 10
                font.bold: true
            }
        }

        Row{  //下拉框 和输入框
            id:search_box
            width: parent.width
            height: 40
            anchors.left: parent.left
            anchors.top: search.bottom
            Label{
                id:lable_community
                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                text:"小区"
                font.pointSize: 10
            }

            ComboBox{
                id:com_community
                currentIndex: 0
                anchors.left:lable_community.right
                anchors.leftMargin: 10
                anchors.verticalCenter: lable_community.verticalCenter
                width: 140
                model: ListModel {
                    id: cbItems
                    ListElement {
                        text: "--请选择--"
                        //                        color: "Yellow"
                    }
                    ListElement {
                        text: "当前节点后"

                    }
                }
            }

            Label{
                id:building_number
                anchors.left: com_community.right
                anchors.leftMargin: 10
                anchors.verticalCenter: com_community.verticalCenter
                text:"楼栋号"
                font.pointSize: 10
            }

            ComboBox{
                id:com_building_number
                anchors.left: building_number.right
                anchors.leftMargin: 10
                anchors.verticalCenter: building_number.verticalCenter
                width: 140
                model: ListModel {
                    id: num_Item
                    ListElement {
                        text: "--请选择--"
                        //                        color: "Yellow"
                    }
                }
            }

            Label{
                id:model
                anchors.left: com_building_number.right
                anchors.leftMargin: 10
                anchors.verticalCenter: com_building_number.verticalCenter
                text:"户型"
                font.pointSize: 10
            }
            ComboBox{
                id:com_model
                anchors.left: model.right
                anchors.leftMargin: 10
                anchors.verticalCenter: model.verticalCenter
                width: 140
                model: ListModel {
                    id: model_Item
                    ListElement {
                        text: "--请选择--"
                        //                        color: "Yellow"
                    }
                }
            }
            Label{
                id:state
                anchors.left: com_model.right
                anchors.leftMargin: 10
                anchors.verticalCenter: com_model.verticalCenter
                text:"状态"
                font.pointSize: 10
            }
            ComboBox{
                id:com_state
                anchors.left: state.right
                anchors.leftMargin: 10
                anchors.verticalCenter: state.verticalCenter
                width: 140
                model: ListModel {
                    id: state_Item
                    ListElement {
                        text: "--请选择--"
                        //                        color: "Yellow"
                    }
                }
            }
            Label{
                id:located
                anchors.left: com_state.right
                anchors.leftMargin: 10
                anchors.verticalCenter: com_state.verticalCenter
                text:"座落"
                font.pointSize: 10
            }
            TextField{
                id:text_located
                anchors.left: located.right
                anchors.leftMargin: 10
                anchors.verticalCenter: located.verticalCenter
                width: 180
            }
        }

        Rectangle{
            id:line_1
            width: parent.width
            height: 1
            anchors.left: parent.left
            anchors.top: search_box.bottom
            anchors.topMargin: 10
            color: "darkgray"
        }

        Row{//增 删 查 改 的按钮
            id:button_box
            anchors.left: parent.left
            anchors.top: line_1.bottom
            width: parent.width
            height:40
            Button{
                id:button_select
                anchors.left: parent.left
                anchors.leftMargin: parent.width/3*2
                width:80
                anchors.verticalCenter: parent.verticalCenter
                text:"查询"
            }
            Button{
                id:button_add
                anchors.left: button_select.right
                anchors.leftMargin: 10
                width:80
                anchors.verticalCenter: button_select.verticalCenter
                text:"新增"
            }
            Button{
                id:button_delete
                anchors.left: button_add.right
                anchors.leftMargin: 10
                width: 80
                anchors.verticalCenter: button_add.verticalCenter
                text:"删除"
            }
            Button{
                id:button_import
                anchors.left: button_delete.right
                anchors.leftMargin: 10
                width: 80
                anchors.verticalCenter: button_delete.verticalCenter
                text:"导入"
            }
            Button{
                id:button_export
                anchors.left: button_import.right
                anchors.leftMargin: 10
                width: 80
                anchors.verticalCenter: button_import.verticalCenter
                text:"导出"
            }
        }


        Rectangle{
            id:line_2
            width: parent.width
            height: 1
            anchors.left: parent.left
            anchors.top: button_box.bottom
            color: "darkgray"
        }




        DataTableView{//使用DataTableView 来展示表格
            id:table_house
            anchors.left: parent.left
            anchors.top: line_2.bottom
            anchors.topMargin: 5
            width: parent.width
            anchors.bottom: parent.bottom
            //            model:mymodel
//            headerList: ["日期","地点","地址","经度","纬度","备注"]//不自己设置时，表头使用model数据列名
            model:mModel
        }

        Row{
            id:tail
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            width: parent.width
            height: 40
            Label{
                id:record
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5
                text:"共有90记录,当前在第1/9页"
                font.pointSize: 13
            }

            Button{
                id:first_page
                anchors.left:record.right
                anchors.leftMargin: parent.width/4
                width:100
                height: 30
                anchors.verticalCenter: record.verticalCenter
                text:"首页"
            }

            Button{
                id:previous_page
                anchors.left:first_page.right
                anchors.leftMargin: 10
                width:100
                height: 30
                anchors.verticalCenter: record.verticalCenter
                text:"上一页"
            }

            Button{
                id:next_page
                anchors.left:previous_page.right
                anchors.leftMargin: 10
                width:100
                height: 30
                anchors.verticalCenter: record.verticalCenter
                text:"上一页"
            }

            Button{
                id:back_page
                anchors.left:next_page.right
                anchors.leftMargin: 10
                width:100
                height: 30
                anchors.verticalCenter: record.verticalCenter
                text:"尾页"
            }

            Label{
                id:go
                text:"转到第"
                anchors.left: back_page.right
                anchors.leftMargin: 10
                anchors.verticalCenter: record.verticalCenter
                font.pointSize: 13
            }
            TextField{
                id:page_text
                anchors.left: go.right
                anchors.leftMargin: 5
                anchors.verticalCenter: record.verticalCenter
                width: 60
            }
            Label{
                id:page
                anchors.left: page_text.right
                anchors.leftMargin: 5
                anchors.verticalCenter: record.verticalCenter
                text:"页"
                font.pointSize: 13
            }
            Button{
                id:jump
                anchors.left: page.right
                anchors.leftMargin: 10
                width:100
                height: 30
                anchors.verticalCenter: record.verticalCenter
                text:"跳转"
            }
        }
    }
}

