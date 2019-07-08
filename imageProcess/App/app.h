#include <QApplication>
#include "../Window/mainwindow.h"

class ImageApp
{
private:
    MainWindow mainWindow;
public:
    ImageApp();
    ~ImageApp();
    void run();
};
