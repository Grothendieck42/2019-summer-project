#include "Model.h"

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

void Model::openImage(const std::string &file_name)
{
    imageList->clearList();
    Image image;
    image.openImage(file_name);
    imageList->addImage(image);
    notification->notify();
}

void Model::saveImage(const std::string &file_name)
{
    imageList->getImage().saveImage(file_name);
}

void Model::toGray()
{
    Image newImage=imageList->getImage();
    newImage.toGray();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::toBinary(int &threshold)
{
    Image newImage=imageList->getImage();
    newImage.toBinary(threshold);
    imageList->addImage(newImage);
    notification->notify();
}

void Model::detectEdge(int &threshold)
{
    Image newImage=imageList->getImage();
    newImage.detectEdge(threshold);
    imageList->addImage(newImage);
    notification->notify();
}

std::shared_ptr<ImageList> Model::getImageList()
{
    return imageList;
}

void Model::changeImageLightContrast(int light, int contrast)
{
	Image image = imageList->getImage();
    image.changeImageLightContrast(light, contrast);
	imageList->addImage(image);
	notification->notify();
}

void Model::grayEqualizeHist()
{
    Image newImage=imageList->getImage();
    newImage.grayEqualizeHist();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::colorEqualizeHist()
{
    Image newImage=imageList->getImage();
    newImage.colorEqualizeHist();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::laplace(){
    Image newImage=imageList->getImage();
    newImage.laplace();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::logEnhance(){
    Image newImage=imageList->getImage();
    newImage.logEnhance();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::gammaCorrect(float &fGamma){
    Image newImage=imageList->getImage();
    newImage.gammaCorrect(fGamma);
    imageList->addImage(newImage);
    notification->notify();
}

void Model::addGaussNoise(){
    Image newImage=imageList->getImage();
    newImage.addGaussNoise();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::addSaltNoise(int &n){
    Image newImage=imageList->getImage();
    newImage.addSaltNoise(n);
    imageList->addImage(newImage);
    notification->notify();
}

void Model::imageSegmentation(int &threshold){
    Image newImage=imageList->getImage();
    newImage.imageSegmentation(threshold);
    imageList->addImage(newImage);
    notification->notify();
}

void Model::setUpdateNotification(std::shared_ptr<Notification> notification)
{
    this->notification = notification;
}
