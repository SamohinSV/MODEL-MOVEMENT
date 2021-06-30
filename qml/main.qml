import QtQuick 2.12
import QtQuick.Window 2.12
import space.developers 1.0
import QtQuick.Controls 2.5

Window  {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Monitoring {
        id:monitoring
    }

    MenuBar {
        id: menuBar

        Menu {
            id: fileMenu
            title: qsTr("File")

            MenuItem {
                text: qsTr("Close")
                onClicked: Qt.quit()
            }
        }

        Menu {
            id: editMenu
            title: qsTr("&Run")

            MenuItem {
                text: qsTr("calculation")
                onClicked: monitoring.start()
            }
        }
    }

}
