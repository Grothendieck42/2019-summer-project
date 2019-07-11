#include "ViewModel.h"
#include "../Model/Model.h"

ViewModel::ViewModel() 
    : openFileCommand(std::make_shared<OpenFileCommand>(this)),
      qImage(std::make_shared<QImage>()),
      updateNotification(std::make_shared<UpdateDataNotification>(this))
{

}

ViewModel::~ViewModel()
{

}

void ViewModel::setModel(std::shared_ptr<Model> model_ptr)
{
    model = model_ptr;
    model->setUpdateNotification(updateNotification);
}

std::shared_ptr<OpenFileCommand> ViewModel::getOpenFileCommand()
{
    return openFileCommand;
}

void ViewModel::openImage(const std::string &file_name)
{
    model->openImage(file_name);
}

std::shared_ptr<QImage> ViewModel::getQImage()
{
    return qImage;
}

void ViewModel::setUpdateNotification(std::shared_ptr<Notification> notification)
{
    this->notification = notification;
}

void ViewModel::notify()
{
    *qImage = model->getImageList()->getQImage();
    notification->notify();
}

std::shared_ptr<UpdateDataNotification> ViewModel::getUpdateDataNotification()
{
    return updateNotification;
}
