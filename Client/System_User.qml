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
            text:"当前位置：人员管理> 系统用户管理管理"
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

        Label{
            id:title_user
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.top: line.bottom
            anchors.topMargin: 10
            text:"用户列表"
            font.pointSize: 20
            font.bold: true
        }

        Rectangle{
            id:line_1
            width: parent.width
            height: 1
            anchors.left: parent.left
            anchors.top: title_user.bottom
            anchors.topMargin: 10
            color: "darkgray"
        }

        Rectangle{// 输入框 和按钮
            id:search_box
            anchors.left: parent.left
            anchors.top: line_1.bottom
            width: parent.width
            height: parent.height/4-30
            Label{
                id:user_account
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.top: parent.top
                anchors.topMargin: 30
                text:"用户账号"
                font.pointSize: 12
            }

            TextField{
                id:user_account_text
                anchors.left: user_account.right
                anchors.leftMargin: 20
                width: 180
                height: 30
                anchors.verticalCenter: user_account.verticalCenter
            }

            Label{
                id:user_name
                anchors.left: user_account_text.right
                anchors.leftMargin: 40
                anchors.verticalCenter: user_account_text.verticalCenter
                text:"用户名称"
                font.pointSize: 12
            }

            TextField{
                id:user_name_text
                anchors.left: user_name.right
                anchors.leftMargin: 20
                width: 180
                height: 30
                anchors.verticalCenter: user_account.verticalCenter
            }

            Label{
                id:user_tel
                anchors.left: user_name_text.right
                anchors.leftMargin: 40
                anchors.verticalCenter: user_account_text.verticalCenter
                text:"手机号"
                font.pointSize: 12
            }

            TextField{
                id:user_tel_text
                anchors.left: user_tel.right
                anchors.leftMargin: 20
                width: 180
                height: 30
                anchors.verticalCenter: user_account.verticalCenter
            }

            Label{
                id:user_sex
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.top: user_account.bottom
                anchors.topMargin: 30
                text:"性别"
                font.pointSize: 12
            }

            ComboBox{
                id:com_user_sex
                anchors.left: user_sex.right
                anchors.leftMargin: 20
                anchors.verticalCenter: user_sex.verticalCenter
                width: 140
                height:30
                model: ListModel{
                    id:sex_item
                    ListElement{
                        text:"--请选择--"
                    }
                    ListElement{
                        text:"男"
                    }
                    ListElement{
                        text:"女"
                    }
                }
            }

            Label{
                id:user_identity
                anchors.left: com_user_sex.right
                anchors.leftMargin: 40
                anchors.verticalCenter: user_sex.verticalCenter
                text:"角色身份"
                font.pointSize: 12
            }

            ComboBox{
                id:com_user_identity
                anchors.left: user_identity.right
                anchors.leftMargin: 20
                anchors.verticalCenter: user_sex.verticalCenter
                width: 140
                height:30
                model: ListModel{
                    id:identity_item
                    ListElement{
                        text:"--请选择--"
                    }
                    ListElement{
                        text:"老板"
                    }
                    ListElement{
                        text:"管理员"
                    }
                }
            }

            Button{
                id:search_button
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                anchors.rightMargin: 20
                text:"查询"
                width: 160
                height: 35
                onClicked: {  //管理员查询
                    worker.showMangers(user_account_text.text,user_name_text.text,user_tel_text.text);
                }
            }
        }
        Rectangle{
            id:line_2
            width: parent.width
            height: 1
            anchors.left: parent.left
            anchors.top: search_box.bottom
            color: "darkgray"
        }

        DataTableView{
            id:table_user
            anchors.left: parent.left
            anchors.top: line_2.bottom
            anchors.topMargin: 5
            headerList: ["账号","密码","姓名","联系电话","性别"]//不自己设置时，表头使用model数据列名
            width: columnsWidth*mModel.number()
            columnsWidth:parent.width/(mModel.number()+1)
            anchors.bottom: parent.bottom
            model:mModel
        }

//        Rectangle{
//            id:operation
//            anchors.left: table_user.right
//            anchors.top: line_2.bottom
//            anchors.topMargin: 5
//            anchors.right: parent.right
//            height: table_user.height

//            Rectangle{
//                id:operation_name
//                anchors.left: parent.left
//                width: parent.width
//                height:50
//                color: "#044599"
//                Label{
//                    text:"操作"
//                    anchors.centerIn: parent
//                    font.pointSize:13
//                    color: "white"
//                }
//                border.color: "gray"
//                border.width: 1
//            }

//            Rectangle{
//                id:operation_1
//                anchors.left: parent.left
//                width: parent.width
//                anchors.top: operation_name.bottom
//                height:48
//                Button{
//                    id:operation_1_button
//                    anchors.centerIn: parent
//                    width: 100
//                    text:"编辑"
//                }
//                border.color: "gray"
//                border.width: 1
//            }
//            Rectangle{
//                id:operation_2
//                anchors.left: parent.left
//                width: parent.width
//                anchors.top: operation_1.bottom
//                height:48
//                Button{
//                    id:operation_2_button
//                    anchors.centerIn: parent
//                    width: 100
//                    text:"编辑"
//                }
//                border.color: "gray"
//                border.width: 1
//            }
//            Rectangle{
//                id:operation_3
//                anchors.left: parent.left
//                width: parent.width
//                anchors.top: operation_2.bottom
//                height:48
//                border.color: "gray"
//                border.width: 1
//                Button{
//                    id:operation_3_button
//                    anchors.centerIn: parent
//                    width: 100
//                    text:"编辑"
//                }
//            }
//            Rectangle{
//                id:operation_4
//                anchors.left: parent.left
//                width: parent.width
//                anchors.top: operation_3.bottom
//                height:48
//                border.color: "gray"
//                border.width: 1
//                Button{
//                    id:operation_4_button
//                    anchors.centerIn: parent
//                    width: 100
//                    text:"编辑"
//                }
//            }
//            Rectangle{
//                id:operation_5
//                anchors.left: parent.left
//                width: parent.width
//                anchors.top: operation_4.bottom
//                height:48
//                border.color: "gray"
//                border.width: 1
//                Button{
//                    id:operation_5_button
//                    anchors.centerIn: parent
//                    width: 100
//                    text:"编辑"
//                }
//            }
//            Rectangle{
//                id:operation_6
//                anchors.left: parent.left
//                width: parent.width
//                anchors.top: operation_5.bottom
//                height:48
//                border.color: "gray"
//                border.width: 1
//                Button{
//                    id:operation_6_button
//                    anchors.centerIn: parent
//                    width: 100
//                    text:"编辑"
//                }
//            }
//            Rectangle{
//                id:operation_7
//                anchors.left: parent.left
//                width: parent.width
//                anchors.top: operation_6.bottom
//                height:48
//                border.color: "gray"
//                border.width: 1
//                Button{
//                    id:operation_7_button
//                    anchors.centerIn: parent
//                    width: 100
//                    text:"编辑"
//                }
//            }
//            Rectangle{
//                id:operation_8
//                anchors.left: parent.left
//                width: parent.width
//                anchors.top: operation_7.bottom
//                height:48
//                border.color: "gray"
//                border.width: 1
//                Button{
//                    id:operation_8_button
//                    anchors.centerIn: parent
//                    width: 100
//                    text:"编辑"
//                }
//            }
//            Rectangle{
//                id:operation_9
//                anchors.left: parent.left
//                width: parent.width
//                anchors.top: operation_8.bottom
//                height:48
//                border.color: "gray"
//                border.width: 1
//                Button{
//                    id:operation_9_button
//                    anchors.centerIn: parent
//                    width: 100
//                    text:"编辑"
//                }
//            }
//        }

    }
}
