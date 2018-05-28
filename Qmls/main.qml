import QtQuick 2.2
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Controls 1.2

ApplicationWindow {
    visible: true
    title: "Qt Quick UI Forms"

    MessageDialog {
        id: aboutDialog
        icon: StandardIcon.Information
        title: qsTr("About")
        text: "Qt Quick UI Forms"
        informativeText: qsTr("This example demonstrates how to separate the implementation of an application from the UI using ui.qml files.")
    }

    Action {
        id: copyAction
        text: qsTr("&Copy")
        shortcut: StandardKey.Copy
        iconName: "edit-copy"
        enabled: (!!activeFocusItem && !!activeFocusItem["copy"])
        onTriggered: activeFocusItem.copy()
    }

    Action {
        id: cutAction
        text: qsTr("Cu&t")
        shortcut: StandardKey.Cut
        iconName: "edit-cut"
        enabled: (!!activeFocusItem && !!activeFocusItem["cut"])
        onTriggered: activeFocusItem.cut()
    }

    Action {
        id: pasteAction
        text: qsTr("&Paste")
        shortcut: StandardKey.Paste
        iconName: "edit-paste"
        enabled: (!!activeFocusItem && !!activeFocusItem["paste"])
        onTriggered: activeFocusItem.paste()
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("E&xit")
                shortcut: StandardKey.Quit
                onTriggered: Qt.quit()
            }
        }
        Menu {
            title: qsTr("&Edit")
            MenuItem {
                action: cutAction
            }
            MenuItem {
                action: copyAction
            }
            MenuItem {
                action: pasteAction
            }
        }
        Menu {
            title: qsTr("&Help")
            MenuItem {
                text: qsTr("About...")
                onTriggered: aboutDialog.open()
            }
        }
    }

    MainForm {
        id: mainForm
        anchors.fill: parent
        Layout.minimumWidth: 800
        Layout.minimumHeight: 480
        Layout.preferredWidth: 960
        Layout.preferredHeight: 480
    }
}
