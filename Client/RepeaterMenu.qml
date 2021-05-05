import QtQuick 2.7
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.0


Item {
    id:menu
    visible: true

    property real maxHeight
    property real maxWidth
    property alias listModel: _repeater.model

    signal getListIndex(int idx);
    signal pageSig(int idx);

    Column{//列
        id:colunmItem
        anchors.margins: 4
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.topMargin: 20
        height: parent.height
//        spacing: 20  //间距
        Repeater{
            id:_repeater
            anchors.left: parent.left
            delegate: listDelegate
        }
    }

    Component{
        id:listDelegate
        Rectangle{
            id:listItem
            property bool checked: false
            property bool oldChecked: false
            property int clickCnt: 0

//            width: name.width
            width:maxWidth
            height: 30
//            color: "red"

            Connections{
                target: menu
                onGetListIndex:{
                    //idx:click item ---- index:every item
                    if(idx === index)
                    {//与前一次互斥事件
                        if(idx !==3)
                        {
                            if(!listItem.oldChecked)
                            {
                                listItem.checked = true
                                pageSig(idx)
                            }else
                            {
                                listItem.checked = false
                                pageSig(9)  //关闭此目录，回到主页
                            }
                        }else
                        {//可添加：连续点击事件
                            listItem.checked = true
                            pageSig(idx)
                        }
                    }else
                    {//所有的子Item 互斥
                        listItem.checked = false
                    }
                    listItem.oldChecked = listItem.checked
                }
            }

            property var myModel: model
            property var modelColumnsList:  _repeater.model.isSqlModel?_repeater.model.getHeaderList():Object.keys(_repeater.model.get(0)).reverse()
            //水平线性渐变
            Label{
                id:name
                anchors.left: parent.left
                anchors.leftMargin: 20
                text:myModel[modelColumnsList[1]]
                font.pointSize: 12
                width:100
                height:80
            }

            MouseArea{
                anchors.fill: name
                hoverEnabled: true
                onClicked: {  //树状栏颜色变化
                    _repeater.itemAt(index).color = "#edf2f5"
                    for(var i=0;i<_repeater.count;i++)
                    {
                        if(i!=index)
                        {
                            _repeater.itemAt(i).color = "white"
                        }
                    }
                    getListIndex(index)
                }
            }
        }
    }
}
