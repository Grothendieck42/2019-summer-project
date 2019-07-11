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
    void setImageList(std::shared_ptr<ImageList> imageList);
    ~MainWindow();
    void setOpenFileCommand(std::shared_ptr<Command> openFileCommand);
    std::shared_ptr<UpdateNotification> getNotification();
private slots:
    void on_inputImage_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<ImageList> imageList;
    QGraphicsView* graphView;
    QPushButton* inputImageButton;
    QGraphicsScene *scene;

    std::shared_ptr<UpdateNotification> updateNotification;
    std::shared_ptr<Command> openFileCommand;
};

#endif // MAINWINDOW_H
