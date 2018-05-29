#ifndef UIWINDOWS_H
#define UIWINDOWS_H

#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include <QDebug>

#include "HMI/uibridge.h"

class UIWindows : public QObject
{
    Q_OBJECT
public:
    static UIWindows* getInstance();

    Q_INVOKABLE int initWindow();
//    Q_INVOKABLE void displayScreen(int, int);

public slots:

    void handleUIEvent(QString, QString);

private:
    UIWindows();
    static UIWindows       *m_instance;
    QQmlApplicationEngine   m_uiEngine;
    QQmlApplicationEngine   m_qmlEngine;

    UIBridge*               m_uiBridge = nullptr;

signals:

public slots:
};

#endif // UIWINDOWS_H
