#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../Common/myImage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void update();
    void setImage(std::shared_ptr<Image> image);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<Image> image;
};

#endif // MAINWINDOW_H
