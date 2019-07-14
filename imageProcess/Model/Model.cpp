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

void Model::openImage(const std::string &file_name)
{
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

void Model::changeTmpImageLightContrast(int light, int contrast)
{
    Image image = imageList->getImage();
    image.changeImageLightContrast(light, contrast);
    tmpNotification->setParameter(image);
    tmpNotification->notify();
}

void Model::averBlur()
{
    Image image = imageList->getImage();
    image.averBlur();
    imageList->addImage(image);
    notification->notify();
}

void Model::midBlur()
{
    Image image = imageList->getImage();
    image.midBlur();
    imageList->addImage(image);
    notification->notify();
}

void Model::gaussBlur()
{
    Image image = imageList->getImage();
    image.gaussBlur();
    imageList->addImage(image);
    notification->notify();
}

void Model::bilaterBlur()
{
    Image image = imageList->getImage();
    imageList->addImage(image.bilaterBlur());
    notification->notify();
}

void Model::setUpdateNotification(std::shared_ptr<Notification> notification)
{
    this->notification = notification;
}

void Model::setUpdateTmpNotification(std::shared_ptr<Notification> notification)
{
    tmpNotification = notification;
}
