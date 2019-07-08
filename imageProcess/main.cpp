#include <QApplication>
#include "App/app.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageApp app;
    app.run();
    return a.exec();
}
