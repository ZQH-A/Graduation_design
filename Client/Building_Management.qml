import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.3
import QtQuick 2.3

Item{
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

    Rectangle{  //整个页面
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: line.bottom
        anchors.bottom: parent.bottom
        color: "#f2f2f2"



        Rectangle{  //整个白色页面
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: parent.top
            anchors.topMargin: 20
            width: parent.width-20
            height: parent.height-20



            ListModel{
                id:theModel

                ListElement{
                    Room_number:"201"
                    Rent:"定价￥998.0"
                    Idle:"闲置4天"
                }
            }

           ListModel{
               id:theModel_1

               ListElement{
                   Room_number:"201"
                   Rent:"定价￥998.0"
                   Idle:"闲置4天"
               }

               ListElement{
                   Room_number:"201"
                   Rent:"定价￥998.0"
                   Idle:"闲置4天"
               }
           }
            Item{  //显示页面
                id:page
                height: parent.height
                anchors.left:parent.left
                anchors.leftMargin:200
                anchors.right: parent.right
                Rectangle{
                    anchors.fill: parent
//                    color: "red"
                    Image{
                        id:logo
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        anchors.top: parent.top
                        anchors.topMargin:20
                        width: 50
                        height: 50
                        source: "qrc:images/house_logo.png"
                    }

                    Label{
                        id:real_estate_text
                        text:"01(住宅)"
                        anchors.left:logo.right
                        anchors.leftMargin: 20
                        font.pointSize: 11
                        anchors.top: parent.top
                        anchors.topMargin:20
                    }
                    Rectangle{
                        id:logo_rectangle
                        anchors.left: logo.right
                        anchors.top:real_estate_text.bottom
                        anchors.topMargin: 10
                        anchors.leftMargin: 20

                        Rectangle{  //自定义按钮
                            id:update
                            width: update_text.width
                            height: update_text.height
                            anchors.left: parent.left
                            color:"white"
                            Text{
                                id:update_text
                                font.pointSize: 10
                                text:qsTr("修改")
                                color:"#5787e7"
                            }
                            MouseArea{
                                anchors.fill: parent
                                onPressed: {
                                    console.log("click")
                                }
                            }
                        }

                        Rectangle{  //自定义按钮
                            id:delete_
                            width: delete__text.width
                            height: delete__text.height
                            anchors.leftMargin: 20
                            anchors.left: update.right
                            color:"white"
                            Text{
                                id:delete__text
                                font.pointSize: 10
                                text:qsTr("删除")
                                color:"#5787e7"
                            }
                            MouseArea{
                                anchors.fill: parent
                                onPressed: {
                                    console.log("click")
                                }
                            }
                        }
                    }

                    Rectangle{
                        id:column_line
                        height: logo.height
                        color: "gray"
                        width: 1
                        anchors.left:logo_rectangle.right
                        anchors.leftMargin: parent.width/3
                        anchors.top: parent.top
                        anchors.topMargin: 20
                    }

                    Label{
                        id:idle
                        text:"1/2"
                        anchors.left:column_line.right
                        anchors.leftMargin:50
                        font.bold:true
                        font.pointSize: 10
                        anchors.top: parent.top
                        anchors.topMargin:30
                    }
                    Label{
                        id:idle_text
                        text:"总/闲置房号"
                        anchors.top: idle.bottom
                        anchors.topMargin: 10
                        anchors.horizontalCenter: idle.horizontalCenter
                        font.pointSize: 8
                    }

                    Label{
                        id:rent
                        text:"0.00"
                        anchors.left: idle.right
                        anchors.verticalCenter: idle.verticalCenter
                        anchors.leftMargin:80
                        font.bold:true
                        font.pointSize: 10
                    }
                    Label{
                        id:rent_text
                        text:"租金"
                        anchors.top: rent.bottom
                        anchors.topMargin: 10
                        anchors.horizontalCenter: rent.horizontalCenter
                        font.pointSize: 8
                    }

                    Label{
                        id:deposit
                        text:"0.00"
                        anchors.left: rent.right
                        anchors.verticalCenter: rent.verticalCenter
                        anchors.leftMargin:80
                        font.bold:true
                        font.pointSize: 10
                    }
                    Label{
                        id:deposit_text
                        text:"租金"
                        anchors.top: deposit.bottom
                        anchors.topMargin: 10
                        anchors.horizontalCenter: deposit.horizontalCenter
                        font.pointSize: 8
                    }

                    Rectangle{
                        id:column_line_
                        height: logo.height
                        color: "gray"
                        width: 1
                        anchors.left:deposit_text.right
                        anchors.leftMargin: 50
                        anchors.top: parent.top
                        anchors.topMargin: 20
                    }

                    Rectangle{  //自定义按钮
                        id:add_house
                        width: 100
                        height: 30
                        anchors.left: column_line_.right
                        anchors.leftMargin: parent.width/11
                        anchors.top: parent.top
                        anchors.topMargin: 20
                        radius: 3
                        color:"#5787e7"
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
                            text:qsTr("添加房号")
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
                        id:house_sort
                        width: 100
                        height: 30
                        anchors.left: add_house.right
                        anchors.leftMargin: 20
                        anchors.top: parent.top
                        anchors.topMargin: 20
                        radius: 3
                        color:"#5787e7"
                        Image {
                            id:up_and_down_2
                            anchors.left: parent.left
                            anchors.verticalCenter: parent.verticalCenter
                            source: "qrc:images/up_and_down_1.png"
                        }
                        Text{
                            id:house_sort_text
                            anchors.left: up_and_down_2.right
                            anchors.verticalCenter: up_and_down_2.verticalCenter
                            text:qsTr("房号排序")
                            color:"white"
                        }
                        MouseArea{
                            anchors.fill: parent
                            onPressed: {
                                console.log("click")
                            }
                        }
                    }

                    Rectangle{  //房号信息展示
                        id:room_number_rectangle
                        anchors.left: parent.left
                        anchors.leftMargin: 5
                        anchors.top: logo.bottom
                        anchors.topMargin: 20
                        anchors.right: parent.right
                        anchors.bottom: parent.bottom
                        color: "#fbfbfb"
//                        color:"red"




                        GridView{
                            id:room_number_gridView
                            anchors.fill: parent
                            anchors.margins: 20
                            clip:true
                            cellHeight: 140  //设置项大小
                            cellWidth: 200
                            delegate:room_numberDelegate
                            model:theModel
                        }

                        Component{
                            id:room_numberDelegate

                            Rectangle{
                                id:room
                                width: 180
                                height: 120
                                radius: 3
                                opacity: 1 // 透明度
                                border.color: "gray"
                                border.width: 1

                                Rectangle{
                                    anchors.left: parent.left
                                    anchors.leftMargin: 5
                                    anchors.top: parent.top
                                    anchors.topMargin: 5
                                    anchors.right: parent.right
                                    anchors.rightMargin: 5
                                    anchors.bottom: parent.bottom
                                    anchors.bottomMargin: 5
                                    color: "#d7d8d9"

                                    Label{
                                        id:room_number_label
                                        anchors.left: parent.left
                                        anchors.leftMargin: 10
                                        anchors.top: parent.top
                                        anchors.topMargin: 10
                                        color: "white"
                                        text:Room_number
                                        font.bold: true
                                        font.pointSize: 10
                                    }

                                    Label{
                                        id:rent_label
                                        anchors.left: parent.left
                                        anchors.leftMargin: 10
                                        anchors.top: room_number_label.bottom
                                        anchors.topMargin: 20
                                        text:Rent
                                        color: "white"
                                        font.pointSize: 9
                                    }

                                    Label{
                                        id:idle_label
                                        anchors.left: parent.left
                                        anchors.leftMargin: 10
                                        anchors.top: rent_label.bottom
                                        anchors.topMargin: 20
                                        text:Idle
                                        color: "white"
                                        font.pointSize: 9
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Rectangle{
                id:recMenu
                width: 200
                height: parent.height
                anchors.left: parent.left
                anchors.top: parent.top
//                color: "red"

                Rectangle{
                    id:column_line_1
                    width: 5
                    color: "#5787e7"
                    height:real_estate_.height
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.top: parent.top
                    anchors.topMargin: 20
                }

                Label{
                    id:real_estate_
                    text:"房产"
                    font.bold: true
                    font.pointSize: 10
                    anchors.left: column_line_1.right
//                    anchors.leftMargin: 10
                    anchors.verticalCenter: column_line_1.verticalCenter
                }

                Rectangle{  //自定义按钮
                    id:add_real_estate
                    width: 80
                    height: 30
                    anchors.right: parent.right
                    anchors.verticalCenter: real_estate_.verticalCenter
                    radius: 3
                    color:"#5787e7"
                    Image {
                        id:up_and_down_3
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        source: "qrc:images/up_and_down_1.png"
                    }
                    Text{
                        id:add_real_estate_text
                        anchors.left: up_and_down_3.right
                        anchors.verticalCenter: up_and_down_3.verticalCenter
                        text:qsTr("添加")
                        color:"white"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onPressed: {
                            console.log("click")
                        }
                    }
                }

                property int pageIndex: 3
                RepeaterMenu{
                    id:repeaterMenu
                    maxWidth: 200
                    maxHeight:parent.height-20
                    anchors.left: parent.left
                    anchors.top: real_estate_.bottom
                    anchors.bottom: parent.bottom
//                    ListModel{
//                        id:listModel_
//                        ListElement{
//                            name:qsTr("目录1")
////                            iconSource:"qrc:images/dir1.png"
//                        }
//                        ListElement{
//                            name:           qsTr("目录2")
////                            iconSource:     "qrc:images/dir2.png"
//                        }
//                        ListElement{
//                            name:           qsTr("目录3")
////                            iconSource:     "qrc:images/dir3.png"
//                        }
//                    }

//                    listModel: listModel_
                    listModel: rModel
                    Connections{
                        target: repeaterMenu
                        onPageSig:{
                            console.log(idx)


                            pageIndex = idx

                        }
                    }
                }
            }
        }
    }
}
