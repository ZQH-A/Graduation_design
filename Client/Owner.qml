import QtQuick 2.0
import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.3

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
            text:"当前位置：人员管理> 业主管理"
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

        Rectangle{
            id:title_rectangel
            width: parent.width
            height: 100
            anchors.left: parent.left
            anchors.top: position.bottom
            anchors.topMargin: 11
            color: "white"
            Label{
                anchors.left: parent.left
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                text:"共"+oModel.rowCount()+"位业主"
                font.pointSize: 15
            }

            Rectangle{  //自定义按钮
                id:add_owner
                width: 120
                height: 40
                anchors.right: parent.right
                anchors.rightMargin: parent.width/3
                anchors.verticalCenter: parent.verticalCenter
                radius: 3
                color:"#5787e7"
                Image {
                    id:up_and_down_5
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/add_tennant.png"
                }
                Text{
                    id:export_text
                    anchors.left: up_and_down_5.right
                    anchors.verticalCenter: up_and_down_5.verticalCenter
                    text:qsTr("添加业主")
                    color:"white"
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {

                        console.log("click")
//                        theModel.append({name:"曾强辉",real_estate:"04",Room_number:"101,201",Tel:"15320215710",
//                                            Cycle:"1月",Lease:"2021-04-30至2022-05-29"});
                    }
                }
            }
            Rectangle{  //自定义按钮
                id:export_owner
                width: 120
                height: 40
                anchors.left: add_owner.right
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                radius: 3
                color:"#5787e7"
                Image {
                    id:up_and_down_6
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/export.png"
                }
                Text{
                    id:export_owner_text
                    anchors.left: up_and_down_6.right
                    anchors.verticalCenter: up_and_down_6.verticalCenter
                    text:qsTr("导出业主信息")
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
                id:sort_owner
                width: 120
                height: 40
                anchors.left: export_owner.right
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                radius: 3
                color:"#5787e7"
                Image {
                    id:up_and_down_7
                    anchors.left: parent.left
                    anchors.leftMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:images/up_and_down.png"
                }
                Text{
                    id:sort_owner_text
                    anchors.left: up_and_down_7.right
                    anchors.verticalCenter: up_and_down_7.verticalCenter
                    text:qsTr("业主排序")
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
                id:history_owner
                width: 120
                height: 40
                anchors.left: sort_owner.right
                anchors.leftMargin: 20
                anchors.verticalCenter: parent.verticalCenter
                radius: 3
                color:"white"
                Text{
                    id:history_owner_text
                    anchors.left: parent.left
                    anchors.centerIn: parent
                    text:qsTr("历史业主>>")
                    color:"black"
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
            id:line_1
            width: parent.width
            height: 1
            anchors.left: parent.left
            anchors.top: title_rectangel.bottom
            color: "darkgray"
        }

        Rectangle {
            anchors.left: parent.left
            anchors.top:line_1.bottom
            width: parent.width
            anchors.bottom: parent.bottom
            color: "white"


            //list模型默认9项
//            ListModel {
//                id: theModel

//                ListElement { name:"曾强辉";real_estate:"04";Room_number:"101,201";Tel:"15320215710";
//                    Cycle:"1月";Lease:"2021-04-30至2022-05-29" }
//                ListElement { name:"曾强辉";real_estate:"04";Room_number:"101,201";Tel:"15320215710";
//                    Cycle:"1月";Lease:"2021-04-30至2022-05-29"}
//                ListElement { name:"曾强辉";real_estate:"04";Room_number:"101,201";Tel:"15320215710";
//                    Cycle:"1月";Lease:"2021-04-30至2022-05-29"}
//                ListElement { name:"曾强辉";real_estate:"04";Room_number:"101,201";Tel:"15320215710";
//                    Cycle:"1月";Lease:"2021-04-30至2022-05-29"}
//                ListElement { name:"曾强辉";real_estate:"04";Room_number:"101,201";Tel:"15320215710";
//                    Cycle:"1月";Lease:"2021-04-30至2022-05-29"}
//                ListElement { name:"曾强辉";real_estate:"04";Room_number:"101,201";Tel:"15320215710";
//                    Cycle:"1月";Lease:"2021-04-30至2022-05-29"}
//                ListElement { name:"曾强辉";real_estate:"04";Room_number:"101,201";Tel:"15320215710";
//                    Cycle:"1月";Lease:"2021-04-30至2022-05-29"}
//                ListElement { name:"曾强辉";real_estate:"04";Room_number:"101,201";Tel:"15320215710";
//                    Cycle:"1月";Lease:"2021-04-30至2022-05-29"}
//                ListElement { name:"曾强辉";real_estate:"04";Room_number:"101,201";Tel:"15320215710";
//                    Cycle:"1月";Lease:"2021-04-30至2022-05-29"}
//            }

            GridView {
                id:_gridView
                anchors.fill: parent;
                anchors.margins: 30
                clip: true
//                model: theModel //绑定数据源
                model:oModel
                cellWidth: 300//设置项大小
                cellHeight: 300
                delegate: numberDelegate //设置绘制代理
            }

            //自定义绘制代理
            Component {
                id: numberDelegate

                Rectangle {
                    id: wrapper
                    width: 280
                    height: 280
                    color: "white"
                    border.width: 1
                    border.color: "#e7eaec"

                    //首先是一个渐变的矩形框
                    radius: 3

                    property var myModel: model
                    property var modelColumnsList:_gridView.model.isSqlModel? _gridView.model.getHeaderList():Object.keys(_repeater.model.get(0)).reverse()
                    Rectangle{
                        id:title_
                        anchors.left: parent.left
                        anchors.leftMargin: 1
                        anchors.top: parent.top
                        anchors.topMargin: 1
                        anchors.right: parent.right
                        anchors.rightMargin: 1
                        height: 60
                        color: "#fafafa"
                        Image {
                            id: touxiang
                            anchors.left: parent.left
                            anchors.leftMargin: 20
                            anchors.top: parent.top
                            anchors.topMargin: 10
                            source: "qrc:images/personel_1.png"
                        }
                        //文本值是number的数值
                        Text {
                            id:name_text
                            anchors.left:touxiang.right
                            anchors.verticalCenter: touxiang.verticalCenter
                            font.pointSize: 10
                            text: myModel[modelColumnsList[0]]
                            color: room_number.color
                        }
                        Image {
                            id: details
                            source: "qrc:images/detail.png"
                            anchors.verticalCenter: touxiang.verticalCenter
                            anchors.right: parent.right
                            anchors.rightMargin: 10
                        }

                        Text{
                            id:real_estate_text
                            text:myModel[modelColumnsList[1]]
                            anchors.top:touxiang.bottom
                            anchors.topMargin: 10
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            font.pointSize: 10
                            color: room_number.color
                        }
                    }

                    Rectangle{
                        id:line_2
                        width: parent.width
                        height: 1
                        anchors.left: parent.left
                        anchors.top: title_.bottom
                        color: "darkgray"
                    }

                    Rectangle{
                        id:content
                        height: parent.height/2
                        width: parent.width-20
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                        anchors.right: parent.right
                        anchors.rightMargin: 10
                        anchors.top:line_2.bottom
                        anchors.topMargin: 20

                        Label{
                            id:room_number
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            text:"关联房号:"
                            color:"#999999"
                        }
                        Text{
                            id:room_number_text
                            anchors.verticalCenter: room_number.verticalCenter
                            anchors.left: room_number.right
                            text:myModel[modelColumnsList[1]]
                            color: room_number.color
                        }

                        Label{
                            id:tel
                            anchors.horizontalCenter: room_number.horizontalCenter
                            anchors.top: room_number.bottom
                            anchors.topMargin: 15
                            text:"联系电话:"
                            color: room_number.color
                        }
                        Text{
                            id:tel_text
                            anchors.verticalCenter: tel.verticalCenter
                            anchors.left: tel.right
                            text:myModel[modelColumnsList[2]]
                            color: room_number.color
                        }

                        Label{
                            id:cycle
                            text:"缴费周期:"
                            anchors.top: tel.bottom
                            anchors.topMargin: 15
                            color: room_number.color
                            anchors.horizontalCenter: room_number.horizontalCenter
                        }

                        Text{
                            id:cycle_text
                            text:myModel[modelColumnsList[6]]
                            anchors.verticalCenter: cycle.verticalCenter
                            anchors.left: cycle.right
                            color: room_number.color
                        }

                        Label{
                            id:month_rent
                            anchors.horizontalCenter: room_number.horizontalCenter
                            anchors.top: cycle.bottom
                            anchors.topMargin: 15
                            text:"每期租金:"
                            color: room_number.color
                        }
                        Text{
                            id:month_rent_text
                            anchors.verticalCenter: month_rent.verticalCenter
                            anchors.left: month_rent.right
                            text:myModel[modelColumnsList[5]]
                            color: room_number.color
                        }

                        Label{
                            id:lease
                            text:"租期:"
                            anchors.top: month_rent.bottom
                            anchors.topMargin: 15
                            anchors.left: parent.left
                            anchors.leftMargin: 10
                            color: room_number.color
                        }

                        Text{
                            id:lease_text
                            text:myModel[modelColumnsList[3]]+"至"+myModel[modelColumnsList[4]]
                            anchors.left: lease.right
                            anchors.verticalCenter: lease.verticalCenter
                            color: room_number.color
                        }
                    }

                    Rectangle{
                        id:button_rectangle
                        width: parent.width-2
                        anchors.left: parent.left
                        anchors.leftMargin: 1
                        anchors.right: parent.right
                        anchors.rightMargin: 1
                        anchors.top: content.bottom
                        anchors.topMargin: 10
                        anchors.bottom: parent.bottom
                        color: "#fafafa"
                        Rectangle{  //自定义按钮
                            id:renewal
                            width: parent.width/3
                            height: 40
                            anchors.left: parent.left
                            radius: 3
                            border.color: "black"
                            border.width: 1
                            color: "#fafafa"
                            Text{
                                id:renewal_text

                                anchors.centerIn: parent
                                font.pointSize: 10
                                text:qsTr("续租")
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
                            id:refund
                            width: parent.width/3
                            height: 40
                            anchors.left: renewal.right
                            radius: 3
                            border.color: "black"
                            border.width: 1
                            color: "#fafafa"
                            Text{
                                id:refund_text
                                anchors.centerIn: parent
                                font.pointSize: 10
                                text:qsTr("退租")
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
                            width: parent.width/3
                            height: 40
                            anchors.left: refund.right
                            radius: 3
                            border.color: "black"
                            border.width: 1
                            color: "#fafafa"
                            Text{
                                id:delete_text
                                anchors.centerIn: parent
                                font.pointSize: 10
                                text:qsTr("删除")
                                color:"#5787e7"
                            }
                            MouseArea{
                                anchors.fill: parent
                                onPressed: {
                                    //删除该项
                                    if (!wrapper.GridView.delayRemove)//是否延迟移除
                                    {

//                                        theModel.remove(index);
//                                        console.log(myModel[modelColumnsList[0]])
//                                        console.log(myModel[modelColumnsList[1]])
//                                        console.log(myModel[modelColumnsList[2]])
//                                        console.log(myModel[modelColumnsList[3]])
//                                        console.log(myModel[modelColumnsList[4]])
//                                        console.log(myModel[modelColumnsList[5]])
//                                        console.log(myModel[modelColumnsList[6]])
//                                        console.log(myModel[modelColumnsList[7]])
//                                         console.log(myModel[modelColumnsList[8]])
//                                         console.log(myModel[modelColumnsList[9]])

                                    }
                                }
                            }
                        }

                    }

                    //GridView移除项  顺序动画
                    GridView.onRemove: SequentialAnimation {
                        //属性变化
                        PropertyAction {
                            target: wrapper;
                            property: "GridView.delayRemove";
                            value: true;
                        }
                        //数字动画
                        NumberAnimation {
                            target: wrapper;//目标对象
                            property: "scale";//执行动画的属性
                            to: 0;//结束值
                            duration: 250;//动画持续时长
                            easing.type: Easing.InOutQuad;//动画执行曲线
                        }
                        PropertyAction {
                            target: wrapper;
                            property: "GridView.delayRemove";
                            value: false;
                        }
                    }

                    //GridView新增项  顺序动画
                    GridView.onAdd: SequentialAnimation {
                        NumberAnimation {
                            target: wrapper;
                            property: "scale";
                            from: 0;//开始值
                            to: 1;
                            duration: 250;
                            easing.type: Easing.InOutQuad;
                        }
                    }
                }
            }
        }
    }
}
