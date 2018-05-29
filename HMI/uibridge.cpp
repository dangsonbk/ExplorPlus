#include "uibridge.h"

UIBridge::UIBridge(QObject *uiWindows) : QObject(uiWindows) {
    connect(this, SIGNAL(uiEvent(QString, QString)), uiWindows, SLOT(handleUIEvent(QString, QString)));
}
