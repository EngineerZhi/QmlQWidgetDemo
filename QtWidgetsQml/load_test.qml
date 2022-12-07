import QtQuick 2.3
import QtQuick.Window 2.0

//Window {
//    color: "red"
//    Image {
//        id:background_image
//        anchors.fill: parent
//        fillMode: Image.PreserveAspectCrop
//        source: "http://cube.elemecdn.com/6/94/4d3ea53c084bad6931a56d5158a48jpeg.jpeg"
//        antialiasing: true
//    }
//}

Item {
    id: item_test
    Image {
        id:background_image
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "http://cube.elemecdn.com/6/94/4d3ea53c084bad6931a56d5158a48jpeg.jpeg"
        antialiasing: true
    }
}

//Rectangle {
//    color: "gray"
//    radius:10
//    Image {
//        id:background_image
//        anchors.fill: parent
//        fillMode: Image.PreserveAspectCrop
//        source: "http://cube.elemecdn.com/6/94/4d3ea53c084bad6931a56d5158a48jpeg.jpeg"
//        antialiasing: true
//    }
//}
