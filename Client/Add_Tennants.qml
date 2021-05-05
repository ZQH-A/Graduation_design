import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick 2.4
import QtQuick.Layouts 1.2
import QtQuick.Controls.Styles 1.4


Window{
    visible: true
    width: 840
    height: 760
    title: qsTr("添加租客")
    property int textFieldrightMargin: 100
    property int textFieldwidth: 680
    ScrollView{
        width: 840
        height: 760

        Rectangle{
            width: parent.width
            height: 900
            anchors.left: parent.left
            anchors.top: parent.top

            Rectangle{
                id:head_line
                width: parent.width
                height: 1
                anchors.left: parent.left
                color: "darkgray"
            }
            Rectangle{
                anchors.left: parent.left
                anchors.top: head_line.bottom
                width: parent.width
                height: 100
                id:image_rectangle
                Image{
                    id:first_image
                    anchors.left: parent.left
                    anchors.leftMargin: 280
                    anchors.top: parent.top
                    anchors.topMargin: 20
                    source: "qrc:images/first.png"
                }
                Image{
                    id:horizontal_line
                    anchors.left: first_image.right
                    anchors.verticalCenter: first_image.verticalCenter
                    source: "qrc:images/line.png"
                }
                Image{
                    id:horizontal_line_1
                    anchors.left: horizontal_line.right
                    anchors.verticalCenter: first_image.verticalCenter
                    source:"qrc:images/line.png"
                }

                Image {
                    id: horizontal_line_2
                    anchors.left: horizontal_line_1.right
                    anchors.verticalCenter: first_image.verticalCenter
                    source: "qrc:images/line_1.png"
                }
                Image {
                    id: horizontal_line_3
                    anchors.left: horizontal_line_2.right
                    anchors.verticalCenter: first_image.verticalCenter
                    source: "qrc:images/line_1.png"
                }

                Image {
                    id: second_image
                    anchors.left: horizontal_line_3.right
                    anchors.verticalCenter: horizontal_line_1.verticalCenter
                    source: "qrc:images/second.png"
                }
                Label{
                    text:"租约信息"
                    color: "#5787e7"
                    anchors.top: first_image.bottom
                    anchors.horizontalCenter: first_image.horizontalCenter
                }
                Label{
                    text:"设置费用项"
                    color: "#97a8be"
                    anchors.top: second_image.bottom
                    anchors.horizontalCenter: second_image.horizontalCenter
                }
            }

            Rectangle{
                id:input
                anchors.left: parent.left
                anchors.top: image_rectangle.bottom
//                anchors.topMargin: 20
                width: parent.width
                anchors.bottom: parent.bottom
                Label{
                    id:house_id
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: parent.top
                    anchors.topMargin: 20
                    text:"入住房号"
                }
                TextField{
                    id:house_id_text
                    anchors.left: house_id.right
                    anchors.leftMargin: 30
                    anchors.verticalCenter:house_id.verticalCenter
//                    anchors.right: parent.right
//                    anchors.rightMargin: 50
                    placeholderText: qsTr("请选择")
                    height: 30
                    width: textFieldwidth
                }
                Label{
                    id:tenants_name
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: house_id.bottom
                    anchors.topMargin: 40
                    text:"租客姓名"
                }
                TextField{
                    id:tenants_name_text
                    anchors.verticalCenter: tenants_name.verticalCenter
                    anchors.left: tenants_name.right
                    anchors.leftMargin: 30
//                    anchors.right: parent.right
//                    anchors.rightMargin: textFieldrightMargin
                    placeholderText: qsTr("请输入租客姓名")
                    height: 30
                    width: textFieldwidth
                }

                Label{
                    id:tel
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: tenants_name.bottom
                    anchors.topMargin: 40
                    text:"电话号码"
                }

                TextField{
                    id:tel_text
                    anchors.verticalCenter: tel.verticalCenter
                    anchors.left: tel.right
                    anchors.leftMargin: 30
//                    anchors.right: parent.right
//                    anchors.rightMargin: textFieldrightMargin
                    placeholderText: qsTr("请输入租客电话")
                    height: 30
                    width: textFieldwidth
                }
                Label{
                    id:id_number
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: tel.bottom
                    anchors.topMargin: 40
                    text:"身份证"
                }
                TextField{
                    id:text_number
                    anchors.verticalCenter: id_number.verticalCenter
                    anchors.left: id_number.right
                    anchors.leftMargin: 45
//                    anchors.right: parent.right
//                    anchors.rightMargin: textFieldrightMargin
                    placeholderText: qsTr("请输入身份证号码")
                    height: 30
                    width: textFieldwidth
                }

                Label{
                    id:image_
                    text:"相册"
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: id_number.bottom
                    anchors.topMargin: 40
                }

                Rectangle{
                    id:select_image
                    anchors.left: image_.right
                    anchors.leftMargin:55
                    anchors.top:text_number.bottom
                    anchors.topMargin: 20
                    width: 100
                    radius: 3
                    height: 100
                    color: "white"
                    Image {
                        id: add_image
                        source: "qrc:images/add_image.png"
                        anchors.centerIn: parent
                    }
                }

                Label{
                    id:add_person
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: image_.bottom
                    anchors.topMargin: 100
                    text:"同住人(添加多个身份证或手机号)"
                }

                Rectangle{  //自定义按钮
                    id:add_button
                    width: 100
                    height: 30
                    anchors.left: add_person.right
                    anchors.leftMargin: 20
                    anchors.verticalCenter: add_person.verticalCenter
                    radius: 3
                    color:"#5787e7"
                    Image {
                        id:up_and_down_3
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        source: "qrc:images/add_tennant.png"
                    }
                    Text{
                        id:add_text
                        anchors.left: up_and_down_3.right
                        anchors.verticalCenter: up_and_down_3.verticalCenter
                        text:qsTr("添加同住人")
                        color:"white"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onPressed: {
                            console.log("click")

                        }
                    }
                }

                Label{
                    id:month_
                    text:"租期"
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: add_person.bottom
                    anchors.topMargin: 40
                }
                TextField{
                    id:current_data
                    anchors.left: month_.right
                    anchors.leftMargin: 60
                    anchors.verticalCenter: month_.verticalCenter
                    height: 30
                    width: 200
                }
                Label{
                    id:zhi
                    text:"至"
                    anchors.left:current_data.right
                    anchors.leftMargin: 5
                    anchors.verticalCenter: current_data.verticalCenter
                }
                TextField{
                    id:end_data
                    anchors.left: zhi.right
                    anchors.leftMargin: 5
                    anchors.verticalCenter: zhi.verticalCenter
                    height: 30
                    width: 200
                }
                Label{
                    id:cycle
                    text:"收租周期"
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: month_.bottom
                    anchors.topMargin: 40
                }
                TextField{
                    id:lease
                    anchors.left:cycle.right
                    anchors.leftMargin: 30
                    anchors.verticalCenter: cycle.verticalCenter
                    height: 30
                    width: 200
                }
                TextField{
                    id:cycle_text
                    anchors.left: lease.right
                    anchors.leftMargin: 5
                    anchors.verticalCenter: cycle.verticalCenter
                    height: 30
                    width: 200
                }

                Label{
                    id:month_rent
                    text:"每期交租"
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: cycle.bottom
                    anchors.topMargin: 40
                }
                TextField{
                    id:month_rent_text
                    anchors.left: month_rent.right
                    anchors.leftMargin: 30
                    anchors.verticalCenter: month_rent.verticalCenter
                    height: 30
                    width: textFieldwidth
                    text:"0"
//                    anchors.right: parent.right
//                    anchors.rightMargin: textFieldrightMargin
                }
                Label{
                    id:add_money
                    text:"递增设置"
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: month_rent.bottom
                    anchors.topMargin: 40
                }
                TextField{
                    anchors.left: add_money.right
                    anchors.leftMargin: 30
                    anchors.verticalCenter: add_money.verticalCenter
                    height: 30
                    width: textFieldwidth
                    text: "无递增提醒设置"
//                    anchors.right: parent.right
//                    anchors.rightMargin: textFieldrightMargin
                }
                Label{
                    id:deposit
                    anchors.left: parent.left
                    anchors.leftMargin: 40
                    anchors.top: add_money.bottom
                    anchors.topMargin: 40
                    text:"押金总计"
                }
                TextField{
                    id:deposit_text
                    anchors.left: deposit.right
                    anchors.leftMargin: 30
                    anchors.verticalCenter: deposit.verticalCenter
                    height: 30
                    width: textFieldwidth
                    text:"0"
//                    anchors.right: parent.right
//                    anchors.rightMargin: textFieldrightMargin
                }
                Rectangle{  //自定义按钮
                    id:save
                    width: 80
                    height: 40
                    anchors.left: parent.left
                    anchors.leftMargin: 370
                    anchors.top: deposit.bottom
                    anchors.topMargin: 40
                    radius: 3
//                    anchors.verticalCenter: date.verticalCenter
                    color:"#5787e7"

                    Text{
                        id:save_text
                        anchors.left: parent.left
                        anchors.leftMargin: 20
                        anchors.verticalCenter: parent.verticalCenter
                        text:qsTr("保存")
                        color:"white"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onPressed: {
                            console.log("click")
                            //添加租客        房产 房号  姓名  电话号码  ID number  开始日期  结束日期 收租周期 月租金 押金
                            worker.add_tennants(house_id_text.text,house_id_text.text,
                                                tenants_name_text.text,tel_text.text,
                                                text_number.text,current_data.text,
                                                end_data.text,lease.text+cycle_text.text,
                                                month_rent_text.text,deposit_text.text)
                            worker.showTennants("")
                        }
                    }
                }
            }
        }
    }
}
