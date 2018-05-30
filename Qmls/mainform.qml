import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.2

Item {
    anchors.fill: parent
    property alias leftPaneView: leftPane
    property alias rightPaneView: leftPane

    SplitView {
        id: splitView
        width: parent.width
        height: parent.height - 30

        TableView {
            id: leftPane
            width: parent.width / 2

            Layout.minimumWidth: splitView.width / 3

            model: leftPaneModel

            TableViewColumn {
                role: "fileName"
                title: qsTr("File name")
                width: leftPane.width / 2
            }

            TableViewColumn {
                role: "fileExt"
                title: qsTr("Ext")
                width: 30
            }
            TableViewColumn {
                role: "fileSize"
                title: qsTr("Size")
                width: 50
            }
            TableViewColumn {
                role: "fileDate"
                title: qsTr("Last Modify")
                width: 100
            }
        }

        TableView {
            id: rightPane
            Layout.fillWidth: true

            property int columnWidth: width / 3
            Layout.minimumWidth: splitView.width / 3

            model: rightPaneModel

            TableViewColumn {
                role: "fileName"
                title: qsTr("File name")
                width: rightPane.width / 2
            }

            TableViewColumn {
                role: "fileExt"
                title: qsTr("Ext")
                width: 30
            }
            TableViewColumn {
                role: "fileSize"
                title: qsTr("Size")
                width: 50
            }
            TableViewColumn {
                role: "fileDate"
                title: qsTr("Last Modify")
                width: 100
            }
        }

        TabView {
            visible: false
            id: tabView

            Tab {
                title: qsTr("Customer Settings")
                source: "qml/Settings.qml"
            }
            Tab {
                title: qsTr("Customer Notes")
                source: "qml/Notes.qml"
            }
            Tab {
                title: qsTr("Customer History")
                source: "qml/History.qml"
            }
        }
    }
}
