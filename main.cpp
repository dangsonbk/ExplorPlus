#include "main.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    UIWindows::getInstance();

    return app.exec();
}
