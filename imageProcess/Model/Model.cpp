#include "Model.h"
#include <QDebug>

Model::Model() : imageList(std::make_shared<ImageList>())
{

}

Model::~Model()
{

}

// Model对于当前图片的操作需要这样来完成
// 首先获取当前图片的拷贝
// Image image = imageList->getImage();
// 进行操作后需要通知更改
// notification->notify();
// 具体操作写在myImage.cpp Image对象中
// Model层调用底层的方法

bool Model::openImage(const std::string &file_name)
{
    imageList->clearList();
    Image image;
    image.openImage(file_name);
    if(image.empty())
        return false;
    imageList->addImage(image);
    notification->notify();
    return true;
}

bool Model::saveImage(const std::string &file_name)
{
    if(imageList->empty())
        return false;
    if(imageList->getImage().empty())
        return false;
    imageList->getImage().saveImage(file_name);
    return true;
}

bool Model::toGray()
{
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    if(newImage.checkGray())
        return false;
    newImage.toGray();
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::toBinary(int &threshold)
{
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.toBinary(threshold);
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::detectEdge(int &threshold)
{
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    if(!newImage.checkGray())
        return false;
    newImage.detectEdge(threshold);
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

std::shared_ptr<ImageList> Model::getImageList()
{
    return imageList;
}

bool Model::changeImageLightContrast(int light, int contrast)
{
    if(imageList->empty())
        return false;
	Image image = imageList->getImage();
    if(image.empty())
        return false;
    image.changeImageLightContrast(light, contrast);
	imageList->addImage(image);
	notification->notify();
    return true;
}

bool Model::changeTmpImageLightContrast(int light, int contrast)
{
    if(imageList->empty())
        return false;
    Image image = imageList->getImage();
    if(image.empty())
        return false;
    image.changeImageLightContrast(light, contrast);
    tmpNotification->setParameter(image);
    tmpNotification->notify();
    return true;
}

bool Model::averBlur()
{
    if(imageList->empty())
        return false;
    Image image = imageList->getImage();
    if(image.empty())
        return false;
    image.averBlur();
    imageList->addImage(image);
    notification->notify();
    return true;
}

bool Model::midBlur()
{
    if(imageList->empty())
        return false;
    Image image = imageList->getImage();
    if(image.empty())
        return false;
    image.midBlur();
    imageList->addImage(image);
    notification->notify();
    return true;
}

bool Model::display()
{
    notification->notify();
    return true;
}

bool Model::undo()
{
    if(imageList->empty())
        return false;
    imageList->deleteImage();
    notification->notify();
    return true;
}

bool Model::gaussBlur()
{
    if(imageList->empty())
        return false;
    Image image = imageList->getImage();
    if(image.empty())
        return false;
    image.gaussBlur();
    imageList->addImage(image);
    notification->notify();
    return true;
}

bool Model::bilaterBlur()
{
    if(imageList->empty())
        return false;
    Image image = imageList->getImage();
    if(image.empty())
        return false;
    imageList->addImage(image.bilaterBlur());
    notification->notify();
    return true;
}

bool Model::grayEqualizeHist()
{
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    if(!newImage.checkGray())
        return false;
    newImage.grayEqualizeHist();
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::colorEqualizeHist()
{
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    if(!newImage.checkColor())
        return false;
    newImage.colorEqualizeHist();
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::laplace(){
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.laplace();
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::logEnhance(){
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.logEnhance();
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::gammaCorrect(float &fGamma){
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.gammaCorrect(fGamma);
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::addGaussNoise(){
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.addGaussNoise();
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::addSaltNoise(int &n){
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.addSaltNoise(n);
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::imageSegmentation(int &threshold){
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    if(!newImage.checkColor())
        return false;
    newImage.imageSegmentation(threshold);
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::imageEnlarge(){
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.imageEnlarge();
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::imageReduct(){
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.imageReduct();
    imageList->addImage(newImage);
    notification->notify();
    return true;
}


bool Model::trainModel(const std::string &dataPath){
    std::cout<<"Train data in path: "+dataPath<<std::endl;
    QProgressDialog *m_pConnectProBar = new QProgressDialog();
    m_pConnectProBar->setRange(0,100);
    m_pConnectProBar->setOrientation(Qt::Horizontal);
    m_pConnectProBar->setValue(0);
    m_pConnectProBar->setVisible(true);
    m_pConnectProBar->setModal(true);
    m_pConnectProBar->setWindowTitle("Please Wait");
    m_pConnectProBar->setLabelText("Starting...");
    m_pConnectProBar->setCancelButtonText("cancel");
    progressGo(0, 10, m_pConnectProBar);
    train_eigen_face(dataPath, m_pConnectProBar);
    m_pConnectProBar->setVisible(false);
    return true;
}

bool Model::detectFaces(const std::string &classfierPath){
    std::cout<<"Model data in path: "+classfierPath<<std::endl;
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.setMat(detecte_faces(classfierPath, newImage.getMat()));
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::annotateFaces(const std::string &modelPath){
    std::cout<<"Model data in path: "+modelPath<<std::endl;
    if(imageList->empty())
        return false;
    Image newImage=imageList->getImage();
    if(newImage.empty())
        return false;
    newImage.setMat(annotate_faces(modelPath, newImage.getMat()));
    imageList->addImage(newImage);
    notification->notify();
    return true;
}

bool Model::beautifyFaces(){
    return true;
}

bool Model::generateHeadshots(const std::string &outputPath){
    return true;
}

void Model::setUpdateNotification(std::shared_ptr<Notification> notification)
{
    this->notification = notification;
}

void Model::setUpdateTmpNotification(std::shared_ptr<Notification> notification)
{
    tmpNotification = notification;
}

