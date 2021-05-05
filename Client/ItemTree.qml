import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQml.Models 2.2

Rectangle{
    visible: true
    width:200
    height:800

    signal mclicked(int index); //自定义信号

    Rectangle{
        id:root
        height:parent.height
        width:parent.width
        color: "#32323a"

        property var treeModel: mControl.getTreeModel()

        //用于节点选中
        //实例化一个QItemSelectionModel，与一个QAbstractItemModel和任何支持它的视图一起使用
        ItemSelectionModel{
            id:sel
            model:root.treeModel
        }

        TreeView{
            id:myTree
            anchors.fill: parent
            headerVisible:false
            backgroundVisible: false
            style: treeViewStyle
            model:root.treeModel
            selection:sel

            TableViewColumn{
                width:myTree.width
                title:"Name"
                role:"name"
            }

            itemDelegate: Item{

                Image {//显示的图标
                    id:logo
                    height: 20
                    width: 20
                    anchors.left: parent.left
//                    anchors.leftMargin: 5
                    anchors.verticalCenter: parent.verticalCenter
                    source:{
                        if(styleData.value ==="首页")
                        {
                            "qrc:images/Home.png"
                        }
                        else if(styleData.value === "房屋管理")
                        {
                            "qrc:images/House.png"
                        }else if(styleData.value === "人员管理")
                        {
                            "qrc:images/personnel.png"
                        }else if(styleData.value === "安装维修")
                        {
                            "qrc:images/maintenance.png"
                        }else if(styleData.value === "运维管理")
                        {
                            "qrc:images/operations.png"
                        }else if(styleData.value === "数据分析")
                        {
                            "qrc:images/Analysis.png"
                        }else if(styleData.value === "系统管理")
                        {
                            "qrc:images/management.png"
                        }
                    }
                }

                Text{  // 显示的字体
                    id:nameText
                    anchors.left: logo.right
                    anchors.leftMargin: 15
                    anchors.verticalCenter: parent.verticalCenter
                    color:"white"
                    elide:styleData.elideMode
                    text:styleData.value
                    font.pointSize: 10
                }

                MouseArea{
                    id:itemMouse
                    anchors.fill:parent
                    hoverEnabled: true
                    drag.target: nameText

                    property bool isExpand: true //点击展开树节点
                    onClicked: {//当前的选择将被更新
                        sel.setCurrentIndex(styleData.index,0x0010) //点击Item，设置选中当前节点
                        if(styleData.depth)
                        {
                            if(styleData.value === "基本管理")
                            {                               
                                mclicked(1);
                            }else if(styleData.value === "系统用户管理")
                            {                                
                                mclicked(2);
                            }else if(styleData.value === "租客档案")
                            {
                                mclicked(3);
                            }else if(styleData.value === "业主管理")
                            {
                                mclicked(4);
                            }
                        }else{
                            if(styleData.value === "首页")
                            {                                
                                mclicked(0);
                            }
                            if(isExpand)
                            {
                                emit: myTree.expand(styleData.index) //展开索引指定项
                                isExpand = false;
                            }else{
                                emit: myTree.collapse(styleData.index) //折叠索引指定项
                                isExpand = true;
                            }
                        }
                    }
                }
            }
        }
    }

    Component{
        id:treeViewStyle
        TreeViewStyle{
            padding.left: 2
            padding.right: 2
            indentation: 10 //节点间缩进
//            branchDelegate: Image { //字前面的图片
//                id:image
//                width: 20
//                height: 20
//                source: styleData.isExpanded ? "qrc:images/expansion.png": "qrc:images/collapse.png"
//            }
            rowDelegate: Rectangle{
                color:styleData.selected ? "#007DFF" : "transparent" //选中节点后的颜色和背景色
                height: 40
            }
        }
    }
}
