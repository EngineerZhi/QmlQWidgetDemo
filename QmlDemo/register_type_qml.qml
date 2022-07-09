import QtQuick 2.12
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import test.conrtrol 1.0
Rectangle {
    color: "gray"
    radius:10
 	QmlControl {
       id: qmlctrl
    }
    Image {
        id:background_image
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "http://cube.elemecdn.com/6/94/4d3ea53c084bad6931a56d5158a48jpeg.jpeg"
        antialiasing: true
    }
    Button {
        text: "Left"
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin:50
        background: Rectangle {
            color:"#0b81ff"
            implicitWidth: 100;
            implicitHeight: 50;
            radius: 6;
        }
        //信号槽连接
        onClicked: {
           	qmlctrl.AddData(99,88);
            console.log("我被点击了"+text)
        }
    }
    Button {
        text: "Right"
        anchors.bottom: parent.bottom
        anchors.right:  parent.right
        anchors.rightMargin:50
        background: Rectangle {
            color:"#0b81ff"
            implicitWidth: 100;
            implicitHeight: 50;
            radius: 6;
        }
        //信号槽连接
        onClicked: {
            background_image.source=qmlctrl.UpdateBackground();
            console.log("我被点击了"+text)
        }
    }
}

