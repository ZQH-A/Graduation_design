import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3


//登录界面
ApplicationWindow{
    id:login
    visible:true
    width:538
    height:315;
    title:qsTr("房屋管理系统")

    Loader {
        id: pageLoader_
    }
    //================================================
    //最上面的部分
    Rectangle{//加载顶部背景图片
        id:top_image
        height:103
        anchors.left: parent.left
        anchors.top:parent.top
        anchors.leftMargin: 20
        anchors.topMargin: 20
        Image{
            id:picture_back
            source: "qrc:images/back.png"
            x:0
            y:0
        }
    }

    //================================================
    //中间部分
    //账号、密码框、注册等按钮
    Rectangle{
        id:rect_count_pass
        width:498
        height:140
//        color:"gainsboro"
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: top_image.bottom
        anchors.topMargin: 2
        border.color: "gainsboro"
        border.width: 1

        Label{
            id:count_label
            anchors.left: parent.left
            anchors.leftMargin: 40
            anchors.top:parent.top
            anchors.topMargin: 25
            font.bold: true //字体加粗
            text:"账 号："
        }

        TextField{ //账号输入框
            id:count_text
            width: 250
            height: 30
            visible: true
            anchors.left: count_label.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 20
        }

        Button{ //立即注册按钮
            id:count_button
            height:30
            anchors.left: count_text.right
            anchors.leftMargin: 20
            anchors.top:parent.top
            anchors.topMargin: 20
            text:"立即注册"
            onClicked: {
                login.close()
                pageLoader_.source="Register.qml"

            }
        }

        Label{
            id:password_label
            anchors.left: parent.left
            anchors.leftMargin: 40
            anchors.top: count_label.bottom
            anchors.topMargin: 30
            text:"密 码:"
            font.bold: true //字体加粗
        }

        TextField{//密码输入框
            id:password_text
            width: 250
            height: 30
            anchors.left: password_label.right
            anchors.leftMargin: 17
            anchors.top: count_text.bottom
            anchors.topMargin: 10
        }

        CheckBox{  //自动登录复选框
            id:bottom_Automatic_Lonin
            anchors.left: parent.left
            anchors.leftMargin: 40
            anchors.top: password_label.bottom
            anchors.topMargin: 10
            text:"自动登录"
        }

        CheckBox{//记住密码复选框
            id:bottom_Remember_Password
            anchors.left: bottom_Automatic_Lonin.right
            anchors.leftMargin: 10
            anchors.top: password_label.bottom
            anchors.topMargin: 10
            text:"记住密码"
        }

        CheckBox{//使用本地账号登录复选框
            id:bottom_Automatic_Lonin_Native
            anchors.left: bottom_Remember_Password.right
            anchors.leftMargin: 10
            anchors.top: password_label.bottom
            anchors.topMargin: 10
            text:"使用本地账号登录"
        }
    }
    //================================================
    //最后部分
    Rectangle{ //登录 、取消按钮
        id:rect_button_login
        anchors.left: parent.left
        anchors.leftMargin:300
        anchors.top: rect_count_pass.bottom
        anchors.topMargin: 10


        Button{
            id:login_button
            height:30
            text:"登录"
            onClicked: {
                if(dataEncapsulation.login_manger(count_text.text,password_text.text))
                {
                    login.close()
                    pageLoader_.source="MainPage.qml"
                }else{
                    console.log("请重新输入，账户或密码错误")
                }
            }
        }
        Button{
            id:cancel_button
            height:30;
            text:"取消"
            anchors.left: login_button.right
            anchors.leftMargin: 10
            onClicked: {
                Qt.quit()
            }
        }
    }
}
