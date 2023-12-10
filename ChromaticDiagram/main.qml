import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

Window {
    id: mainWindow
    visible: true
    
    //width: 1100
    //height: 540
    width: 1100
    height: 580
    title: qsTr("Chromatic diagram")
    color: "lavender"
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    Connections {
        target : windowController
         function onImageChanged() {
            image.reload()
        }
        function onControlPointMoved(){
            image.reload()
        }
    }
    GridLayout{
        id: mainGrid
        anchors.fill : parent
        columns : 2
        rows : 1
        height: mainWindow.height
        Rectangle {
            Layout.column : 0
            Layout.row : 0
            Layout.fillHeight : true
            Layout.fillWidth : true
            color: "lavender"
            Rectangle{
                x: 30
                y: 30
                width: 480
                height: 480
                color: "lavenderblush"
                Rectangle {
                    // x axis 
                    width: parent.width
                    height: 1
                    color: "dimgray"
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Rectangle {
                    // y axis
                    width: 1
                    height: parent.height
                    color: "dimgray"
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                }
                // Circle 1
                 Rectangle {
                     id: circle1
                     width: 10
                     height: 10
                     color: "navy"
                     radius: width / 2 
                     x: 0
                     y: 400
                     Drag.active: dragArea1.drag.active
                     Drag.hotSpot.x: 0
                     Drag.hotSpot.y: 384

                     MouseArea {
                         id: dragArea1
                         anchors.fill: parent
                         drag.target: parent
                         drag.axis: Drag.XAndYAxis
                         onPositionChanged: {
                             if (dragArea1.drag.active) {
                                 windowController.moveControlPoint(1, circle1.x, circle1.y)
                                 PathManager.changePath(1, circle1.x, circle1.y)
                             }
                         }
                     }
                 }
                 // Circle 2
                 Rectangle {
                     id: circle2
                     width: 10
                     height: 10
                     color: "navy"
                     radius: width / 2 
                     x: 144
                     y: 96
                     Drag.active: dragArea2.drag.active
                     Drag.hotSpot.x: 144
                     Drag.hotSpot.y: 96
                     MouseArea {
                         id: dragArea2
                         anchors.fill: parent
                         drag.target: parent
                         drag.axis: Drag.XAndYAxis
                         onPositionChanged: {
                             if (dragArea2.drag.active) {
                                 windowController.moveControlPoint(2, circle2.x, circle2.y)
                                 PathManager.changePath(2, circle2.x, circle2.y)
                             }
                         }
                     }
                     
                 }
                 
                 // Circle 3
                 Rectangle {
                     id: circle3
                     width: 10
                     height: 10
                     color: "navy"
                     radius: width / 2 
                     x: 336
                     y: 96
                     Drag.active: dragArea3.drag.active
                     Drag.hotSpot.x: 336
                     Drag.hotSpot.y: 96

                     MouseArea {
                         id: dragArea3
                         anchors.fill: parent
                         drag.target: parent
                         drag.axis: Drag.XAndYAxis
                         onPositionChanged: {
                             if (dragArea3.drag.active) {
                                 windowController.moveControlPoint(3, circle3.x, circle3.y)
                                 PathManager.changePath(3, circle3.x, circle3.y)
                             }
                         }
                     }
                 }
                 // Circle 4
                 Rectangle {
                     id: circle4
                     width: 10
                     height: 10
                     color: "navy"
                     radius: width / 2 
                     x: 470
                     y: 374
                     Drag.active: dragArea4.drag.active
                     Drag.hotSpot.x: 470
                     Drag.hotSpot.y: 374

                     MouseArea {
                         id: dragArea4
                         anchors.fill: parent
                         drag.target: parent
                         drag.axis: Drag.XAndYAxis
                         onPositionChanged: {
                             if (dragArea4.drag.active) {
                                 windowController.moveControlPoint(4, circle4.x, circle4.y)
                                 PathManager.changePath(4, circle4.x, circle4.y)
                             }
                         }
                     }

                 }

                PathView {
                    id: conrPaV;
                    anchors.fill: parent;
                    model: 9000;
                    enabled: false
                    delegate: Rectangle {
                        id: dot;
                        width: 1; height: 1;
                        color: "navy";
                    }
                    path: Path {
                        //id: ph;
                        //startX: conrPaV.width/2.0;
                        //startY: conrPaV.height/2.0;
                        PathSvg {path: PathManager.path}
                    }
                }
            }
            
        }
        Rectangle {
            Layout.column : 1
            Layout.row : 0
            Layout.fillHeight : true
            Layout.fillWidth : true
            height: mainWindow.height
            color: "lavender"
            enabled: false
            
            Image {
                id : image
                x : 5
                y : 5
                width : 530 
                height : 530 

                source : "image://ImageSource/image"
                cache : false
                focus : true
                
                function reload() {
                    var oldSource = source
                    source = ""
                    source = oldSource
                }
            } 
            
                CheckBox{
                    enabled: true
                    x: 270
                    y: 540
                    //checked: true
                    text: qsTr("Points")
                }
            
        }
    }
}
