#ifndef UIBRIDGE_H
#define UIBRIDGE_H

#include <QQmlApplicationEngine>
#include <QString>

class UIBridge : public QObject {
    Q_OBJECT

public:
    explicit UIBridge(QObject *uiWindows = nullptr);

signals:
    void uiEvent(QString objectName, QString callback);
};

#endif // UIBRIDGE_H
