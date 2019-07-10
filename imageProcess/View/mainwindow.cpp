#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../Parameter/FileParameter.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
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
    scene->addPixmap(QPixmap::fromImage(imageList->getQImage()));
    graphView->setScene(scene);
    graphView->show();
}

void MainWindow::setOpenFileCommand(std::shared_ptr<OpenFileCommand> openFileCommand)
{
    this->openFileCommand = openFileCommand;
}

void MainWindow::setImageList(std::shared_ptr<ImageList> imageList)
{
    this->imageList = imageList;
}

void MainWindow::on_inputImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
        auto param = std::make_shared<FileParameter>(fileName.toStdString());
        openFileCommand->setParameter(param);
        openFileCommand->exec();
    }
}
