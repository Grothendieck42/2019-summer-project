#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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
    tool_item = this->findChild<QMenu*>("menu_3");
    adjust_item = this->findChild<QMenu*>("menu_4");
    enlarge_item = this->findChild<QMenu*>("menu_7");
    actionDetectFaces = this->findChild<QAction*>("actionDetectFaces");
    actionAnnotateFaces = this->findChild<QAction*>("actionAnnotateFaces");
    actionBeautifyFaces = this->findChild<QAction*>("actionBeautifyFaces");
    actionGenerateHeadshots = this->findChild<QAction*>("actionGenerateHeadshots");
    tool_item->setEnabled(false);
    adjust_item->setEnabled(false);
    enlarge_item->setEnabled(false);
    actionDetectFaces->setEnabled(false);
    actionAnnotateFaces->setEnabled(false);
    actionBeautifyFaces->setEnabled(false);
    actionGenerateHeadshots->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

void MainWindow::update()
{
    scene->clear();
    scene->addPixmap(QPixmap::fromImage(*qImage));//.scaled(graphView->size(),Qt::KeepAspectRatio)
    graphView->setScene(scene);
    graphView->show();
}

void MainWindow::error(const QString &content)
{
    QMessageBox::critical(this, "错误", content, QMessageBox::Yes);
}

void MainWindow::setDisplayNowCommand(std::shared_ptr<Command> displayNowCommand)
{
    lightDialog.setDisplayNowCommand(displayNowCommand);
}

void MainWindow::setOpenFileCommand(std::shared_ptr<Command> openFileCommand)
{
    this->openFileCommand = openFileCommand;
}

void MainWindow::setSaveFileCommand(std::shared_ptr<Command> saveFileCommand)
{
    this->saveFileCommand = saveFileCommand;
}

void MainWindow::setAverBlurCommand(std::shared_ptr<Command> averBlurCommand)
{
    this->averBlurCommand = averBlurCommand;
}

void MainWindow::setMidBlurCommand(std::shared_ptr<Command> midBlurCommand)
{
    this->midBlurCommand = midBlurCommand;
}

void MainWindow::setGaussBlurCommand(std::shared_ptr<Command> gaussBlurCommand)
{
    this->gaussBlurCommand = gaussBlurCommand;
}

void MainWindow::setBilaterBlurCommand(std::shared_ptr<Command> bilaterBlurCommand)
{
    this->bilaterBlurCommand = bilaterBlurCommand;
}

void MainWindow::setLightContrastCommand(std::shared_ptr<Command> lightContrastCommand)
{
    lightDialog.setLightContrastCommand(lightContrastCommand);
}


void MainWindow::setTmpLightContrastCommand(std::shared_ptr<Command> tmpLightContrastCommand)
{
    lightDialog.setTmpLightContrastCommand(tmpLightContrastCommand);
}


void MainWindow::setToGrayCommand(std::shared_ptr<Command> toGrayCommand)
{
    this->toGrayCommand = toGrayCommand;
}

void MainWindow::setToBinaryCommand(std::shared_ptr<Command> toBinaryCommand)
{
    this->toBinaryCommand = toBinaryCommand;
}

void MainWindow::setDetectEdgeCommand(std::shared_ptr<Command> detectEdgeCommand)
{
    this->detectEdgeCommand = detectEdgeCommand;
}

void MainWindow::setGrayEqualizeHistCommand(std::shared_ptr<Command> grayEqualizeHistCommand)
{
    this->grayEqualizeHistCommand=grayEqualizeHistCommand;
}

void MainWindow::setColorEqualizeHistCommand(std::shared_ptr<Command> colorEqualizeHistCommand)
{
    this->colorEqualizeHistCommand=colorEqualizeHistCommand;
}

void MainWindow::setLaplaceCommand(std::shared_ptr<Command> laplaceCommand)
{
    this->laplaceCommand=laplaceCommand;
}

void MainWindow::setLogEnhanceCommand(std::shared_ptr<Command> logEnhanceCommand)
{
    this->logEnhanceCommand=logEnhanceCommand;
}

void MainWindow::setGammaCorrectCommand(std::shared_ptr<Command> gammaCorrectCommand)
{
    this->gammaCorrectCommand=gammaCorrectCommand;
}

void MainWindow::setAddGaussNoiseCommand(std::shared_ptr<Command> addGaussNoiseCommand){
    this->addGaussNoiseCommand=addGaussNoiseCommand;
}

void MainWindow::setAddSaltNoiseCommand(std::shared_ptr<Command> addSaltNoiseCommand){
    this->addSaltNoiseCommand=addSaltNoiseCommand;
}

void MainWindow::setImageSegmentationCommand(std::shared_ptr<Command> imageSegmentationCommand){
    this->imageSegmentationCommand=imageSegmentationCommand;
}

void MainWindow::setImageEnlargeCommand(std::shared_ptr<Command> imageEnlargeCommand){
    this->imageEnlargeCommand=imageEnlargeCommand;
}

void MainWindow::setImageReductCommand(std::shared_ptr<Command> imageReductCommand){
    this->imageReductCommand=imageReductCommand;
}

void MainWindow::setTrainModelCommand(std::shared_ptr<Command> trainModelCommand){
    this->trainEigenModelCommand=trainModelCommand;
}

void MainWindow::setDetectFacesCommand(std::shared_ptr<Command> detectFacesCommand)
{
    this->detectFacesCommand=detectFacesCommand;
}

void MainWindow::setAnnotateFacesCommand(std::shared_ptr<Command> annotateFacesCommand)
{
    this->annotateFacesCommand=annotateFacesCommand;
}

void MainWindow::setBeautifyFacesCommand(std::shared_ptr<Command> beautifyFacesCommand)
{
    this->beautifyFacesCommand=beautifyFacesCommand;
}

void MainWindow::setGenerateHeadshotsCommand(std::shared_ptr<Command> generateHeadshotsCommand)
{
    this->generateHeadshotsCommand=generateHeadshotsCommand;
}

void MainWindow::setUndoCommand(std::shared_ptr<Command> undoCommand)
{
    this->undoCommand = undoCommand;
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
        error("文件名不能为空");
        return;
    }
    else
    {
        openFileCommand->setParameter(fileName.toStdString());
        if(openFileCommand->exec())
        {
            tool_item->setEnabled(true);
            adjust_item->setEnabled(true);
            enlarge_item->setEnabled(true);
            actionDetectFaces->setEnabled(true);
            actionAnnotateFaces->setEnabled(true);
            actionBeautifyFaces->setEnabled(true);
            actionGenerateHeadshots->setEnabled(true);
        }
        else
        {
            tool_item->setEnabled(false);
            adjust_item->setEnabled(false);
            enlarge_item->setEnabled(false);
            actionDetectFaces->setEnabled(false);
            actionAnnotateFaces->setEnabled(false);
            actionBeautifyFaces->setEnabled(false);
            actionGenerateHeadshots->setEnabled(false);
            error("文件打开失败!");
        }
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
        error("文件名不能为空");
        return;
    }
    else
    {
        saveFileCommand->setParameter(fileName.toStdString());
        if(!saveFileCommand->exec())
        {
            error("文件保存失败!");
        }
    }
}

void MainWindow::on_actionToGray_triggered()
{
    if(!toGrayCommand->exec())
    {
        error("图像灰度化失败!");
    }
}

void MainWindow::on_actionToBinary_triggered()
{
    int threshold=100;
    toBinaryCommand->setParameter(threshold);
    if(!toBinaryCommand->exec())
    {
        error("图像二值化失败!");
    }
}

void MainWindow::on_actionlight_triggered()
{
    lightDialog.show();
}

void MainWindow::on_actionDetectEdge_triggered()
{
    int threshold=30;
    detectEdgeCommand->setParameter(threshold);
    if(!detectEdgeCommand->exec())
    {
        error("边缘检测失败!");
    }
}

void MainWindow::on_actionGrayEqualizeHist_triggered()
{
   if(!grayEqualizeHistCommand->exec())
   {
       error("图像灰度直方图均衡化失败!");
   }
}

void MainWindow::on_actionColorEqualizeHist_triggered()
{
    if(!colorEqualizeHistCommand->exec())
    {
        error("图像彩色直方图均衡化失败!");
    }
}

void MainWindow::on_actionLaplace_triggered()
{
    if(!laplaceCommand->exec())
    {
        error("图像拉普拉斯锐化失败!");
    }
}

void MainWindow::on_actionLogEnhance_triggered()
{
    if(!logEnhanceCommand->exec())
    {
        error("图像对数变换失败!");
    }
}


void MainWindow::on_actionGamma_triggered()
{
    float fGamma=0.4f;
    gammaCorrectCommand->setParameter(fGamma);
    if(!gammaCorrectCommand->exec())
    {
        error("图像伽马校正失败!");
    }
}

void MainWindow::on_actionGaussNoise_triggered()
{
    if(!addGaussNoiseCommand->exec())
    {
        error("图像添加高斯噪声失败!");
    }
}

void MainWindow::on_actionSalt_triggered()
{
    int n=5000;
    addSaltNoiseCommand->setParameter(n);
    if(!addSaltNoiseCommand->exec())
    {
        error("图像添加椒盐噪声失败!");
    }
}

void MainWindow::on_actionImageSegmentation_triggered()
{
    int threshold=50;
    imageSegmentationCommand->setParameter(threshold);
    if(!imageSegmentationCommand->exec())
    {
        error("图像分割失败!");
    }
}

void MainWindow::on_actionjizhilvbo_triggered()
{
    if(!averBlurCommand->exec())
    {
        error("均值滤波失败!");
    }
}

void MainWindow::on_actionzhongzhillvbo_triggered()
{
   if(!midBlurCommand->exec())
   {
       error("中值滤波失败!");
   }
}

void MainWindow::on_actiongaosilvbo_triggered()
{
    if(!gaussBlurCommand->exec())
    {
        error("高斯滤波失败!");
    }
}

void MainWindow::on_actionshuangbianlvbo_triggered()
{
    if(!bilaterBlurCommand->exec())
    {
        error("双边滤波失败!");
    }
}

void MainWindow::on_actionEnlarge_triggered()
{
    if(!imageEnlargeCommand->exec())
    {
        error("图像放大失败!");
    }
}

void MainWindow::on_actionReduct_triggered()
{
    if(!imageReductCommand->exec())
    {
        error("图像缩小失败!");
    }
}

void MainWindow::on_actionTrainEigenModel_triggered()
{
    QString datapath = QFileDialog::getExistingDirectory(this);
    if(datapath.isEmpty())
    {
        return;
    }
    else
    {
        trainEigenModelCommand->setParameter(datapath.toStdString());
        trainEigenModelCommand->exec();
    }
}


void MainWindow::on_actionDetectFaces_triggered()
{
    QString classifierPath = QFileDialog::getOpenFileName(this);
    if(classifierPath.isEmpty())
    {
        return;
    }
    else
    {
        detectFacesCommand->setParameter(classifierPath.toStdString());
        detectFacesCommand->exec();
    }
}

void MainWindow::on_actionAnnotateFaces_triggered(){
    QString modelPath = QFileDialog::getOpenFileName(this);
    if(modelPath.isEmpty())
    {
        return;
    }
    else
    {
        annotateFacesCommand->setParameter(modelPath.toStdString());
        annotateFacesCommand->exec();
    }
}

void MainWindow::on_actionBeautifyFaces_triggered(){
    beautifyFacesCommand->exec();

}

void MainWindow::on_actionGenerateHeadshots_triggered(){
    QString outputdir = QFileDialog::getExistingDirectory(this);
    if(outputdir.isEmpty())
    {
        return;
    }
    else
    {
        generateHeadshotsCommand->setParameter(outputdir.toStdString());
        generateHeadshotsCommand->exec();
    }
}

void MainWindow::on_actionchexiao_triggered()
{
    if(!undoCommand->exec())
    {
        error("撤销失败!");
    }
}
