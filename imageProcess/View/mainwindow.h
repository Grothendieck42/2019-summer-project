#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QFileDialog>
#include <QString>
#include <QPixmap>
#include <QGraphicsScene>
#include <memory>
#include "../Common/myImage.h"
#include "../Common/ImageList.h"
#include "../Common/Command.h"
#include "Notification/UpdateNotification.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void update();
    void setQImage(std::shared_ptr<QImage> qImage);
    ~MainWindow();
    void setOpenFileCommand(std::shared_ptr<Command> openFileCommand);
    void setSaveFileCommand(std::shared_ptr<Command> saveFileCommand);
    void setToGrayCommmand(std::shared_ptr<Command> toGrayCommand);
    void setToBinaryCommmand(std::shared_ptr<Command> toBinaryCommand);
    std::shared_ptr<Notification> getNotification();
private slots:

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionToGray_triggered();

    void on_actionToBinary_triggered();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QImage> qImage;
    QGraphicsView* graphView;
    QGraphicsScene *scene;

    std::shared_ptr<UpdateNotification> updateNotification;
    std::shared_ptr<Command> openFileCommand;
    std::shared_ptr<Command> saveFileCommand;
    std::shared_ptr<Command> toGrayCommand;
    std::shared_ptr<Command> toBinaryCommand;
};

#endif // MAINWINDOW_H
