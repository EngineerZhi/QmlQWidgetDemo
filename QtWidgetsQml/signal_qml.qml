import QtQuick 2.12
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import test.conrtrol 1.1
Rectangle {
    color: "gray"
    radius:10
    CppTestData {
        id: cpp_data
        onNameChanged: {
            console.log("onNameChanged ", name)
            background_image.source=name
        }
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
            cpp_data.NameChanged("http://image.nbd.com.cn/uploads/articles/images/673466/500352700_banner.jpg")
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
            cpp_data.name="http://image.zhangxinxu.com/image/study/s/s256/mm8.jpg"
            console.log("我被点击了"+text)
        }
    }
}

