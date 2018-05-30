#include "uiwindows.h"

UIWindows* UIWindows::m_instance = nullptr;

UIWindows::UIWindows() : QObject()
{
    this->initWindow();
    this->loadPanes();
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

int UIWindows::loadPanes() {
    QDir dir("C:/");
    QFileInfoList model = dir.entryInfoList();
    QList<QObject*> fileList;

    for(int i = 0; i < model.size(); i++) {
        qDebug() << model.at(i).fileName() << endl;
        fileList.append(new FileObject( "",
                                        model.at(i).isDir() ? "dir" : "file",
                                        model.at(i).completeBaseName(),
                                        model.at(i).suffix(),
                                        QString::number(model.at(i).size()),
                                        model.at(i).lastModified().toString("ddd MMM d yy"),
                                        model.at(i).isExecutable() ? "yes" : "no"));
    }


    m_qmlEngine.rootContext()->setContextProperty("leftPaneModel", QVariant::fromValue(fileList));
    m_qmlEngine.rootContext()->setContextProperty("rightPaneModel", QVariant::fromValue(fileList));
}

void UIWindows::handleUIEvent(QString objectName, QString callBack) {
    Q_UNUSED(objectName);
    Q_UNUSED(callBack);
    qDebug("get message");
}
