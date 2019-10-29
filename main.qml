import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.12
//import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2
import Qt.labs.folderlistmodel 2.12


ApplicationWindow  {
    visible: true
    width: 1366
    height: 768
    title: qsTr("Picture Viewer")

    property var imagenamefilters: ["*.png", "*.jpg", "*.gif"]
    property int imageindex: 0
    property var selpath
    property var folder


    BusyIndicator{
        id:busy;
        running: false;
        anchors.centerIn: parent;
        z:4;
    }

    Image {
        id: pathImg
        asynchronous: true
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 30
        source: "resources/folder.png"

        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onClicked: choseDir.open()
        }
    z: 5
    }

    Image {
        id: showImg
        cache: false
        fillMode: Image.PreserveAspectFit
        anchors.fill: parent
        anchors.centerIn: parent.center
        asynchronous: true
        width: implicitWidth
        height: implicitHeight
        z: 3
        MouseArea{
                id:getimg
                anchors.fill: showImg
                visible: showImg.source != 0
                width: showImg.implicitWidth
                height: showImg.implicitHeight
                onClicked: {
                    if(Image.Null != showImg.status && mouseX <= showImg.width / 2)
                    {
                            showImg.source = "file:///"+selpath + IMAGEHANDLE.get_previous_image_path()


//                            console.log("Image left area is pressed.", showImg.source)
                    }
                    else if(Image.Null != showImg.status)
                    {
                            showImg.source = "file:///"+selpath + IMAGEHANDLE.get_next_image_path();

//                            console.log("Image right area is pressed.",showImg.source, "Image.width:", showImg.width, showImg.implicitWidth)
                    }

                }
            }
    }

    FileDialog{
        id: choseDir
        folder: shortcuts.pictures
        title: "Choose a folder with some images"
        selectFolder: true
        nameFilters: imagenamefilters
        onAccepted: {
            folder = fileUrl + "/";
            selpath = new String(folder).slice(8)
            IMAGEHANDLE.set_image_file_path(selpath);
            showImg.source = folder + IMAGEHANDLE.get_image_name();
//            console.log(selpath, showImg.source)
        }
    }
}
