#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QFileDialog>
#include <QString>
#include <QPixmap>
#include <QGraphicsScene>
#include <memory>
#include "lightconstractdialog.h"
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
    void setLightContrastCommand(std::shared_ptr<Command> lightContrastCommand);
    std::shared_ptr<Notification> getNotification();
private slots:

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionchange_triggered();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QImage> qImage;
    QGraphicsView* graphView;
    QGraphicsScene *scene;

    LightConstractDialog lightDialog;
    std::shared_ptr<UpdateNotification> updateNotification;
    std::shared_ptr<Command> openFileCommand;
    std::shared_ptr<Command> saveFileCommand;
};

#endif // MAINWINDOW_H
