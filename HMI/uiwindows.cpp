#include "uiwindows.h"

UIWindows* UIWindows::m_instance = nullptr;

UIWindows::UIWindows() : QObject()
{
    this->initWindow();
}

UIWindows* UIWindows::getInstance() {
    if (!m_instance) {
        m_instance = new UIWindows();
    }
   return m_instance;
}

int UIWindows::initWindow() {

    m_uiBridge = new UIBridge(this);

    m_qmlEngine.rootContext()->setContextProperty("UIBridge", m_uiBridge);
    m_qmlEngine.load(QUrl(QLatin1String("qrc:/Qmls/main.qml")));
    if (m_qmlEngine.rootObjects().isEmpty())
        return -1;
    return 0;
}

void UIWindows::handleUIEvent(QString objectName, QString callBack) {
    Q_UNUSED(objectName);
    Q_UNUSED(callBack);
    qDebug("get message");
}
