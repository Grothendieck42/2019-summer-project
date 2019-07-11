#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Notification/UpdateNotification.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    updateNotification(std::make_shared<UpdateNotification>(this))
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//图像显示
    graphView = this->findChild<QGraphicsView*>("image1");
    inputImageButton = this->findChild<QPushButton*>("inputImage");
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

void MainWindow::update()
{
    scene->addPixmap(QPixmap::fromImage(imageList->getQImage()).scaled(graphView->size(),Qt::KeepAspectRatio));
    graphView->setScene(scene);
    graphView->show();
}

void MainWindow::setOpenFileCommand(std::shared_ptr<Command> openFileCommand)
{
    this->openFileCommand = openFileCommand;
}

void MainWindow::setImageList(std::shared_ptr<ImageList> imageList)
{
    this->imageList = imageList;
}

void MainWindow::on_actionopen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
        openFileCommand->setParameter(fileName.toStdString());
        openFileCommand->exec();
    }
}

std::shared_ptr<UpdateNotification> MainWindow::getNotification()
{
    return updateNotification;
}
