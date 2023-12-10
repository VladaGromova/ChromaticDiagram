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
        function onBorderPointsShowed() {
            image.reload()
        }
        function onBorderPointsHiden() {
            image.reload()
        }
        function onBackgroundShowed() {
            image.reload()
        }
        function onBackgroundHiden() {
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
            Text{
                x: 10
                y: 25
                text: "1.8"
            }
            Text{
                x: 10
                y: 75
                text: "1.6"
            }
            Text{
                x: 10
                y: 128
                text: "1.4"
            }
            Text{
                x: 10
                y: 180
                text: "1.2"
            }
            Text{
                x: 10
                y: 233
                text: "1.0"
            }
            Text{
                x: 10
                y: 286
                text: "0.8"
            }
            Text{
                x: 10
                y: 343
                text: "0.6"
            }
            Text{
                x: 10
                y: 402
                text: "0.4"
            }
            Text{
                x: 10
                y: 455
                text: "0.2"
            }
            Text{
                x: 10
                y: 497
                text: "0.0"
            }
            Text{
                x: 30
                y: 510
                text: "380"
            }
            Text{
                x: 80
                y: 510
                text: "430"
            }
            Text{
                x: 140
                y: 510
                text: "480"
            }
            Text{
                x: 200
                y: 510
                text: "530"
            }
            Text{
                x: 260
                y: 510
                text: "580"
            }
            Text{
                x: 320
                y: 510
                text: "630"
            }
            Text{
                x: 380
                y: 510
                text: "680"
            }
            Text{
                x: 440
                y: 510
                text: "730"
            }
            Text{
                x: 500
                y: 510
                text: "780"
            }
            Rectangle{
                x: 30
                y: 30
                width: 480
                height: 480
                color: "lavenderblush"
                Rectangle {
                    // on x coords 430
                    width: 1
                    height: 10
                    color: "dimgray"
                    x: 60
                    y: 470
                }
                Rectangle {
                    // on x coords 480
                    width: 1
                    height: 10
                    color: "dimgray"
                    x: 120
                    y: 470
                }
                Rectangle {
                    // on x coords 530
                    width: 1
                    height: 10
                    color: "dimgray"
                    x: 180
                    y: 470
                }
                Rectangle {
                    // on x coords 580
                    width: 1
                    height: 10
                    color: "dimgray"
                    anchors.bottom: parent.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Rectangle {
                    // on x coords 630
                    width: 1
                    height: 10
                    color: "dimgray"
                    x: 300
                    y: 470
                }
                Rectangle {
                    // on x coords 680
                    width: 1
                    height: 10
                    color: "dimgray"
                    x: 360
                    y: 470
                }
                Rectangle {
                    // on x coords 620
                    width: 1
                    height: 10
                    color: "dimgray"
                    x: 420
                    y: 470
                }
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
                Rectangle {
                    // on y coords 
                    width: 10
                    height: 1
                    color: "dimgray"
                    x: 0
                    y: 53
                }
                Rectangle {
                    // on y coords 
                    width: 10
                    height: 1
                    color: "dimgray"
                    x: 0
                    y: 107
                }
                Rectangle {
                    // on y coords 
                    width: 10
                    height: 1
                    color: "dimgray"
                    x: 0
                    y: 160
                }
                Rectangle {
                    // on y coords 
                    width: 10
                    height: 1
                    color: "dimgray"
                    x: 0
                    y: 213
                }
                Rectangle {
                    // on y coords 
                    width: 10
                    height: 1
                    color: "dimgray"
                    x: 0
                    y: 267
                }
                Rectangle {
                    // on y coords 
                    width: 10
                    height: 1
                    color: "dimgray"
                    x: 0
                    y: 320
                }
                Rectangle {
                    // on y coords 
                    width: 10
                    height: 1
                    color: "dimgray"
                    x: 0
                    y: 383
                }
                Rectangle {
                    // on y coords 
                    width: 10
                    height: 1
                    color: "dimgray"
                    x: 0
                    y: 432
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
            //Layout.fillHeight : true
            //Layout.fillWidth : true
            x: 500
            y: 0
            width: 540
            //height: 540
            height: mainWindow.height
            color: "lavender"
            //enabled: false

            CheckBox{
                    enabled: true
                    x: 20
                    y: 540
                    checked: true
                    text: qsTr("Points")
                    onCheckedChanged : {
                        if (checked) {
                            windowController.showBorderPoints() 
                        } else {
                            windowController.hideBorderPoints()
                        }
                    }
             }
             CheckBox{
                    enabled: true
                    x: 100
                    y: 540
                    checked: true
                    text: qsTr("Background")
                    onCheckedChanged : {
                        if (checked) {
                            windowController.showBackground() 
                        } else {
                            windowController.hideBackground()
                        }
                    }
             }

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
            
                
            
        }
    }
}
