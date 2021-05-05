import QtQuick 2.0
import QtQuick 2.4
import QtQuick.Layouts 1.2
import QtQuick.Controls 1.4
import QtQuick.Window 2.2

Window{
    id:tennant_info
    visible: true
    width: 840
    height: 700

    property int leftMargin: 40
    property int pointSize: 13
    property int topMargin: 40
    title: qsTr("租客信息")
    flags: Qt.FramelessWindowHint //添加这一句隐藏了标题栏
    Rectangle{
        id:title_text
        width: parent.width
        height: 50
        anchors.left: parent.left
        anchors.top: parent.top
        MouseArea{ //设置可以拖动没有标题的登录界面.  /*这个要放在上面，放在最下面的话，会把上面全部屏蔽掉的*/
            anchors.fill: parent
            property point clickPos: "0,0"  //定义一个点

            onPressed: {
                clickPos = Qt.point(mouseX, mouseY)
            }

            onPositionChanged: {  //属性的改变
                var delta = Qt.point(mouseX-clickPos.x, mouseY-clickPos.y)
                tennant_info.setX(tennant_info.x+delta.x)
                tennant_info.setY(tennant_info.y+delta.y)
            }
        }

        Label{
            text:"租客信息"
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 14
        }

        Rectangle{
            id:rect_close
            width: 30
            height: 30
            color: "transparent" // 透明颜色
            anchors.right: parent.right
            anchors.top: parent.top
            clip:true //剪切
            state: "close_Gary" // 初始状态，还没有进入会变得灰
            Image {
                id: picture_close
                width:rect_close.width*3
                height:rect_close.height
                fillMode: Image.Stretch  //图片扩展方式填充
                source: "qrc:/images/closeback.png"
                x:0
                y:0
            }

            MouseArea{
                hoverEnabled: true  //悬停使用
                anchors.fill:parent
                onEntered: rect_close.state = "close_Black"  //进入会变得黑
                onExited: rect_close.state = "close_Gary"  //离开会变得灰
                onPressed: rect_close.state = "close_Blue"  //按下不松开会变蓝色
                onReleased: rect_close.state = "close_Gary"  //松开会变灰
                onClicked: tennant_info.visible = false

            }

            states:[  //必须在rectangle里面定义使用
                State {
                    name: "close_Gary"
                    PropertyChanges {
                        target: picture_close
                        x:-0*rect_close.width

                    }
                },

                State {
                    name: "close_Black"
                    PropertyChanges {
                        target: picture_close
                        x:-1*rect_close.width

                    }
                },
                State {
                    name: "close_Blue"
                    PropertyChanges {
                        target: picture_close
                        x:-2*rect_close.width

                    }
                }
            ]
        }
    }
    Rectangle{
        id:head_line
        width: parent.width
        anchors.top: title_text.bottom
        height: 1
        anchors.left: parent.left
        color: "darkgray"
    }
    ScrollView{
        anchors.left: parent.left
        anchors.top: head_line.bottom
        width: 840
        height: 600

        Rectangle{
            width: 840
            height: 900

            Label{
                id:text_house
                text:"入住房号"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: parent.top
                anchors.topMargin: 40
                font.pointSize: pointSize
            }
            Label{
                id:house
                text:"01-01"
                anchors.verticalCenter: text_house.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_house.right
                anchors.leftMargin: 40
            }
            Label{
                id:text_name
                text:"租客姓名"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_house.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:name
                text:"曾强辉"
                anchors.verticalCenter: text_name.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_name.right
                anchors.leftMargin: 40
            }
            Label{
                id:text_tel
                text:"电话号码"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_name.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:tel
                text:"1"
                anchors.verticalCenter: text_tel.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_tel.right
                anchors.leftMargin: 40
            }
            Label{
                id:text_number
                text:"身份证"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_tel.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:number
                text:"1"
                anchors.verticalCenter: text_number.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_number.right
                anchors.leftMargin: 60
            }

            Label{
                id:text_photo
                text:"相册"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_number.bottom
                anchors.topMargin: 30
                font.pointSize: pointSize
            }
            Rectangle{
                anchors.left: text_photo.right
                anchors.leftMargin: 80
                width: 60
                height: 60
                anchors.verticalCenter: text_photo.verticalCenter
                color: "red"
            }

            Label{
                id:rent_date
                text:"租期"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_photo.bottom
                anchors.topMargin: 30
                font.pointSize: pointSize
            }
            Label{
                id:date
                text:"2021-04-25 至 2022-04-24"
                anchors.verticalCenter: rent_date.verticalCenter
                font.pointSize: pointSize
                anchors.left: rent_date.right
                anchors.leftMargin: 80
            }

            Label{
                id:text_ruzhu
                text:"已入住"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: rent_date.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:ruzhu
                text:"2天"
                anchors.verticalCenter: text_ruzhu.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_ruzhu.right
                anchors.leftMargin: 60
            }

            Label{
                id:text_cycle
                text:"收租周期"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_ruzhu.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:cycle
                text:"1 月"
                anchors.verticalCenter: text_cycle.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_cycle.right
                anchors.leftMargin: 40
            }
            Label{
                id:text_month_rent
                text:"每期交租"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_cycle.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:month_rent
                text:"0.00"
                anchors.verticalCenter: text_month_rent.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_month_rent.right
                anchors.leftMargin: 40
            }
            Label{
                id:text_state
                text:"缴费情况"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_month_rent.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:state
                text:"已缴费1次"
                anchors.verticalCenter: text_state.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_state.right
                anchors.leftMargin: 40
            }
            Label{
                id:text_remind
                text:"递增提醒"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_state.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:remind
                text:"无递增提醒设置"
                anchors.verticalCenter: text_remind.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_remind.right
                anchors.leftMargin: 40
            }
            Label{
                id:text_deposit
                text:"押金"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_remind.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:deposit
                text:"0.00"
                anchors.verticalCenter: text_deposit.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_deposit.right
                anchors.leftMargin: 80
            }
            Label{
                id:text_rent_date
                text:"收租日"
                anchors.left: parent.left
                anchors.leftMargin: leftMargin
                anchors.top: text_deposit.bottom
                anchors.topMargin: 20
                font.pointSize: pointSize
            }
            Label{
                id:rent_date_
                text:"提前0天"
                anchors.verticalCenter: text_rent_date.verticalCenter
                font.pointSize: pointSize
                anchors.left: text_rent_date.right
                anchors.leftMargin: 60
            }
        }
    }
    Rectangle{
        anchors.left: parent.left
        width: parent.width
        height: 65
        anchors.bottom: parent.bottom
        color: "white"

        Rectangle{
            id:line
            width: parent.width
            anchors.top: parent.top
            height: 1
            anchors.left: parent.left
            color: "darkgray"
        }
        Rectangle{  //自定义按钮
            id:update_button
            width: 70
            height: 40
            anchors.left:parent.left
            anchors.leftMargin: parent.width/3
            anchors.top: parent.top
            anchors.topMargin: 20
            color:"#5787e7"
            radius: 3
            Text{
                id:update_button_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.centerIn: parent
                text:qsTr("修改")
                color:"white"
            }
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    console.log("搜索")
                }
            }
        }

        Rectangle{  //自定义按钮
            id:electronic_contract
            width: 70
            height: 40
            anchors.right: parent.right
            anchors.rightMargin: parent.width/3
            anchors.top: parent.top
            anchors.topMargin: 20
            color:"#5787e7"
            radius: 3
            Text{
                id:electronic_contract_text
                anchors.verticalCenter: parent.verticalCenter
                anchors.centerIn: parent
                text:qsTr("电子合同")
                color:"white"
            }
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    console.log("搜索")
                }
            }
        }
    }
}

