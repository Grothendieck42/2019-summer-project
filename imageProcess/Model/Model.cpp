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
    Image image;
    image.openImage(file_name);
    imageList->addImage(image);
    notification->notify();
}



void Model::saveImage(const std::string &file_name)
{
    imageList->getImage().saveImage(file_name);
}

std::shared_ptr<ImageList> Model::getImageList()
{
    return imageList;
}

void Model::setUpdateNotification(std::shared_ptr<Notification> notification)
{
    this->notification = notification;
}
