import QtQuick 2.12
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
Rectangle {
    color: "gray"
    radius:10
    Image {
        id:background_image
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "http://cube.elemecdn.com/6/94/4d3ea53c084bad6931a56d5158a48jpeg.jpeg"
        antialiasing: true
        objectName: "image_test_obj"//能在Qt元对象中查找的关键
        function updateSource(text) {
            source=text;
            console.log("updateSource=" + source);
        }
        property int enable_see: 5
        function updateSay(value) {
            console.log("updateSay=" + value);
        }
    }
}

