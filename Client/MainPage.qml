import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

ApplicationWindow{
    visible:true
    width:1560
    height:850
    title:qsTr("房屋出租管理系统")

    Rectangle{
        anchors.fill:parent
        color:"black"

        Rectangle{
            id:header_mainPage
            width: parent.width
            height: 50
            anchors.left: parent.left
            anchors.top: parent.top
            color:"white"

            Rectangle{
                id:head_line
                width: parent.width
                height: 1
                anchors.left: parent.left
                color: "darkgray"
            }

            Image{
                id:header_image
                width: 30
                height: 30
                anchors.top:parent.top
                anchors.topMargin: 5
                anchors.left: parent.left
                anchors.leftMargin: 20
                source: "qrc:images/Header_2.png"
            }

            Label{
                id:header_name
                text:"房屋出租管理服务平台"
                anchors.left: header_image.right
                anchors.leftMargin: 20
                anchors.verticalCenter: header_image.verticalCenter
                font.pointSize: 10
                font.bold: true
            }

            Rectangle {
                id: img_profile
                anchors.right: parent.right
                anchors.rightMargin: 100
                anchors.top: parent.top
                anchors.verticalCenter: header_name.verticalCenter
                width: 40
                height: 40
                radius: width/2
                visible: true
                color: "black"

                Image {
                    id: _image
                    smooth: true
                    visible: false
                    anchors.fill: parent
                    source: "qrc:images/profile_1.jpg"
                    antialiasing: true
                }
                Rectangle {
                    id: _mask
                    anchors.fill: parent
                    radius: width/2
                    visible: false
                    antialiasing: true
                    smooth: true
                }
                OpacityMask {
                    id:mask_image
                    anchors.fill: _image
                    source: _image
                    maskSource: _mask
                    visible: true
                    antialiasing: true
                }
            }
            Label{
                id:manger_id
                anchors.left: img_profile.right
                anchors.leftMargin: 10
                anchors.verticalCenter: img_profile.verticalCenter
                text:"管理员"
                font.pointSize: 10;
                color: "blue"
            }



        }

        //允许用户通过侧滑来导航页面（除导航栏的其他页面）
        SwipeView{//每次只显示一个页面
            id:swipeView
            anchors.left: rootitem.right
            anchors.top:parent.top
            anchors.topMargin: 50
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            currentIndex: 0  //当前的index
            Home_Page{

            }

            Building_Management{

            }

            System_User{

            }

            Rectangle{
                color:"green"
            }
            Rectangle{
                color:"white"
            }
        }

        //导航栏 ===========默认在左侧
        Rectangle{
            id:rootitem
            anchors.left:parent.left
            anchors.top: parent.top
            anchors.topMargin: 50
            width:240
            height:parent.height-50
            color: "black"

            ColumnLayout{//用来创建左侧导航栏
                id:lyout
                width:parent.width
                Layout.fillWidth: true
                spacing:0
            }
        }
        //导航栏 ==============

        function addItem()
        {
            var component = Qt.createComponent("ItemTree.qml");
            if(component.status === Component.Ready)
            {
                var itemrect = component.createObject(lyout);//创建在 lyout组件下
                itemrect.mclicked.connect(mmclicked); //将ItemTree.qml 中的信号与 当前qml文件中的槽相关联
            }
        }

        Component.onCompleted: {// 在程序加载完成时创建导航栏
            addItem();
        }

        function mmclicked(index) //槽函数 点击导航栏后切换页面
        {
            swipeView.currentIndex = index;
        }
    }
}
