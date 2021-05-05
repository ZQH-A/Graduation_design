import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

//注册界面
ApplicationWindow{
    id:register
    visible:true
    width:1240
    height:545
    title:qsTr("房屋管理系统")
    Loader{
        id:pageLoader
    }

    Rectangle{
        anchors.fill: parent

        Image{ //背景图片
            id:backgroud_image
            anchors.fill: parent
            source:"qrc:images/backgroud.jpg"
        }

        Rectangle{
            id:register_rect
            anchors.left: parent.left
            anchors.leftMargin: 530
            anchors.top: parent.top
            anchors.topMargin: 50
            width: 520
            height: 440
            color:"white"

            Label{
                id:free_registration
                text:"免费注册"
                anchors.left: parent.left
                anchors.leftMargin: 20
                anchors.top: parent.top
                anchors.topMargin: 20
                font.bold: true
                font.pixelSize: 18
            }
            Label{
                id:exist_count
                text:"已有账号,"
                anchors.right: parent.right
                anchors.rightMargin: 80
                anchors.top: parent.top
                anchors.topMargin: 20
            }

            Rectangle{  //自定义按钮
                id:btn
                width: 30
                height: 20
                anchors.left: exist_count.right
                anchors.leftMargin: 15
                anchors.verticalCenter: exist_count.verticalCenter

                Text{
                    id:btnText
                    anchors.centerIn: parent
                    text:qsTr("马上登录")
                    font.underline: true
                    color:"green"
                }
                MouseArea{
                    anchors.fill: btnText
                    onPressed: {
                        register.close()
                        pageLoader.source="Login.qml"
                    }
                    onReleased: {
                        console.log("release")
                    }
                }
            }


            Label{
                id:username
                text:"姓名:"
                anchors.left: parent.left
                anchors.leftMargin: 60
                anchors.top: free_registration.bottom
                anchors.topMargin: 30
                font.pointSize: 12
            }

            TextField{
                id:username_text
                width: 230
                height: 30
                anchors.left: username.right
                anchors.leftMargin: 15
                anchors.verticalCenter: username.verticalCenter
            }

            Label{
                anchors.left: username_text.right
                anchors.leftMargin: 20
                anchors.verticalCenter: username_text.verticalCenter
                text:"2-5个汉字"
                font.pointSize: 10
            }

            Label{
                id:tel
                anchors.top: username.bottom
                anchors.topMargin: 30
                anchors.left: parent.left
                anchors.leftMargin: 40
                text:"手机号:"
                font.pointSize: 12
            }

            TextField{
                id:tel_text
                width: 230
                height: username_text.height
                anchors.left: tel.right
                anchors.leftMargin: 15
                anchors.verticalCenter: tel.verticalCenter
            }

            Label{
                anchors.left: tel_text.right
                anchors.leftMargin: 20
                anchors.verticalCenter: tel_text.verticalCenter
                text:"请填写手机号"
                font.pointSize: 10
            }

            Label{
                id:count
                anchors.left: parent.left
                anchors.leftMargin: 60
                anchors.top: tel.bottom
                anchors.topMargin: 30
                text:"账号:"
                font.pointSize: 12
            }

            TextField{
                id:count_text
                width: 230
                height: username_text.height
                anchors.left: count.right
                anchors.leftMargin: 15
                anchors.verticalCenter: count.verticalCenter
            }

            Label{
                id:password
                anchors.left: parent.left
                anchors.leftMargin: 60
                anchors.top: count.bottom
                anchors.topMargin: 30
                text:"密码:"
                font.pointSize: 12
            }

            TextField{
                id:password_text
                width: 230
                height: username_text.height
                anchors.left:password.right
                anchors.leftMargin: 15
                anchors.verticalCenter: password.verticalCenter
            }
            Label{
                anchors.left: password_text.right
                anchors.leftMargin: 20
                anchors.verticalCenter: password_text.verticalCenter
                text:"6-20个字符"
                font.pointSize: 10
            }

            Label{
                id:confirm_pass
                anchors.left: parent.left
                anchors.leftMargin: 20
                anchors.top: password.bottom
                anchors.topMargin: 30
                text:"确认密码:"
                font.pointSize: 12
            }

            TextField{
                id:confirm_pass_text
                width: 230
                height: username_text.height
                anchors.left: confirm_pass.right
                anchors.leftMargin: 15
                anchors.verticalCenter: confirm_pass.verticalCenter
            }

            Label{
                anchors.left: confirm_pass_text.right
                anchors.leftMargin: 20
                anchors.verticalCenter: confirm_pass_text.verticalCenter
                text:"必须和密码一致"
                font.pointSize: 10
            }

            CheckBox{
                id:agreement
                anchors.left: parent.left
                anchors.leftMargin: 120
                anchors.top: confirm_pass.bottom
                anchors.topMargin:20
                text:"我已阅读并且同意"
            }

            Rectangle{  //自定义按钮
                id:agreement_content
                width: 30
                height: 20
                anchors.left: agreement.right
                anchors.leftMargin: 20
                anchors.verticalCenter: agreement.verticalCenter

                Text{
                    id:agreement_content_text
                    anchors.centerIn: parent
                    text:qsTr("《使用协议》")
                    color:"green"
                }
                MouseArea{
                    anchors.fill: agreement_content_text
                    onPressed: {
                        console.log("click")
                    }
                    onReleased: {
                        console.log("release")
                    }
                }
            }

            Register_Success{  //注册成功弹出
                id:register_success
                visible:false
            }
            Register_Failure{
                id:register_failure
                visible:false
            }

            Connections{
                target: worker
                onRegister_stateChanged:
                {
                    if(worker.register_state)
                    {
                        console.log("注册成功")
                        register_success.show()
                    }else
                    {
                        register_failure.show()
                        console.log("该账户已被注册")
                    }
                }
            }
            Button{
                id:register_button
                width:230
                height: username_text.height
                anchors.top: agreement.bottom
                anchors.topMargin: 20

                anchors.horizontalCenter: confirm_pass_text.horizontalCenter
                background:Rectangle{
                    color:"orange"
                }
                text:"立即注册"

                onClicked: {
                    worker.manger_register(count_text.text,password_text.text,username_text.text,tel_text.text);
                }
            }
        }
    }
}
