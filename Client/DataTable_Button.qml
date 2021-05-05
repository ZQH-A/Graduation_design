import QtQuick 2.9
import QtQuick.Controls 2.2

ListView {
    id: listView
    clip: true
    header: headerView  //表头
    headerPositioning: ListView.OverlayHeader  //The header is positioned in the beginning of the view.
    flickableDirection: Flickable.AutoFlickDirection
    contentWidth: headerList.length*columnsWidth
    ScrollBar.horizontal: ScrollBar {}
    ScrollBar.vertical: ScrollBar { }
    property var headerList: model.isSqlModel?model.getHeaderList():Object.keys(model.get(0)).reverse()
    property int columnsWidth: parent.width/model.number()
    property int headerHeight: 50
    property int rowsHeight: 48
    property color headerTextColor:"black"
    property color headerBackgroundColor: "#ececec"
    property int headerTextSize: 11
    property string headerFontFamily: "微软雅黑"
    property color backgroundColor: "white"
    property color alternateBackgroundColor: "white"
    property color gridColor: "#99999999"
    property int gridPoint: 1
    property color textColor: "gray"
    property int textSize: 11
    property string textFontFamily: "微软雅黑"
    boundsBehavior: Flickable.StopAtBounds
    property int parent_width
    move: Transition {
        NumberAnimation { properties: "x,y"; duration: 1000 }
    }

    Component{
        id:headerView
        Rectangle{
            id:header_rectangle
            width: parent_width
            height: headerHeight
            color: headerBackgroundColor
            z:15
            property var headerRepeater: headerRepeater
            Row{
                id:header_row
                Repeater{
                    id:headerRepeater
                    model:headerList
                    Label{
                        width: columnsWidth
                        height: headerHeight
                        color: headerTextColor
                        text:headerList[index]
                        font.bold: true
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.family: headerFontFamily
                        font.pointSize: headerTextSize
                    }
                }
            }
        }
    }
    Component{
        id:listDelegate
        Rectangle{
            width: parent_width
            height: rowsHeight
            color: "white"
            border.color: "#ececec"
            border.width: 1
            property var myModel: model
            property var modelColumnsList: listView.model.isSqlModel?listView.model.getHeaderList():Object.keys(listView.model.get(0)).reverse()
            Row{
                id:content_row
                width: contentWidth
                Repeater{
                    id:delegateRepeater
                    model:headerList
                    Label{
                        width: listView.headerItem.headerRepeater.itemAt(index).width
                        height: rowsHeight
                        color: textColor
                        text:myModel[modelColumnsList[index]]
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.family: textFontFamily
                        font.pointSize: textSize
                        elide:Text.ElideRight
                    }
                }
            }

            Rectangle{  //自定义按钮
                id:details
                width: 60
                height: 30
                anchors.left: content_row.right
                anchors.leftMargin: 20
                anchors.verticalCenter: content_row.verticalCenter
                color:"#5787e7"
                radius: 3
                Text{
                    id:details_text
                    anchors.centerIn: parent
                    text:qsTr("详情")
                    color:"white"
                }
                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        console.log("click")
                        console.log(myModel[modelColumnsList[0]])
                        console.log(myModel[modelColumnsList[1]])
                        console.log(myModel[modelColumnsList[2]])
                        console.log(myModel[modelColumnsList[3]])
                        console.log(myModel[modelColumnsList[4]])
                        console.log(myModel[modelColumnsList[5]])

                        rent_detail.show()
                    }
                }
            }
            Rectangle{  //自定义按钮
                id:bill
                width: details.width
                height: details.height
                anchors.left: details.right
                anchors.verticalCenter: content_row.verticalCenter
                anchors.leftMargin: 10
                radius: details.radius
                color:"#5787e7"
                Text{
                    id:bill_text
                    anchors.centerIn: parent
                    text:qsTr("账单")
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
                id:more
                radius: details.radius
                width: details.width
                height: details.height
                anchors.left: bill.right
                anchors.verticalCenter: content_row.verticalCenter
                anchors.leftMargin: 10
                color:"#5787e7"
                Text{
                    id:more_text
                    anchors.centerIn: parent
                    text:qsTr("更多")
                    color:"white"
                }
                Image{
                    anchors.left: more_text.right
                    anchors.verticalCenter: more_text.verticalCenter
                    source: "qrc:images/more.png"
                }

                MouseArea{
                    anchors.fill: parent
                    onPressed: {
                        console.log("click")
                    }
                }
            }
        }
    }

    delegate:listDelegate
    Detail{
        id:rent_detail
        visible: false
    }

    function setColumnWidth(index,width){
        var headerItem = listView.headerItem.headerRepeater.itemAt(index)
        contentWidth = contentWidth - headerItem.width+width
        headerItem.width = width
    }

    function getColumnWidth(index){
        var headerItem = listView.headerItem.headerRepeater.itemAt(index)
        return headerItem.width
    }
}

