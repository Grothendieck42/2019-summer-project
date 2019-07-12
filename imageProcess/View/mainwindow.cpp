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
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

void MainWindow::update()
{
    scene->addPixmap(QPixmap::fromImage(*qImage));//.scaled(graphView->size(),Qt::KeepAspectRatio)
    graphView->setScene(scene);
    graphView->show();
}

void MainWindow::setOpenFileCommand(std::shared_ptr<Command> openFileCommand)
{
    this->openFileCommand = openFileCommand;
}

void MainWindow::setSaveFileCommand(std::shared_ptr<Command> saveFileCommand)
{
    this->saveFileCommand = saveFileCommand;
}

void MainWindow::setLightContrastCommand(std::shared_ptr<Command> lightContrastCommand)
{
    lightDialog.setLightContrastCommand(lightContrastCommand);
}

void MainWindow::setToGrayCommmand(std::shared_ptr<Command> toGrayCommand)
{
    this->toGrayCommand = toGrayCommand;
}

void MainWindow::setToBinaryCommmand(std::shared_ptr<Command> toBinaryCommand)
{
    this->toBinaryCommand = toBinaryCommand;
}

void MainWindow::setQImage(std::shared_ptr<QImage> qImage)
{
    this->qImage = qImage;
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

std::shared_ptr<Notification> MainWindow::getNotification()
{
    return updateNotification;
}

void MainWindow::on_actionsave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
        saveFileCommand->setParameter(fileName.toStdString());
        saveFileCommand->exec();
    }
}

void MainWindow::on_actionToGray_triggered()
{
    toGrayCommand->exec();
}

void MainWindow::on_actionToBinary_triggered()
{
    int threshold=100;
    toBinaryCommand->setParameter(threshold);
    toBinaryCommand->exec();
}

void MainWindow::on_actionlight_triggered()
{
        lightDialog.show();
}
