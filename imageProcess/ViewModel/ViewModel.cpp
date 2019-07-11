#include "ViewModel.h"
#include "../Model/Model.h"

ViewModel::ViewModel() 
    : openFileCommand(std::make_shared<OpenFileCommand>(this))
{

}

ViewModel::~ViewModel()
{

}

void ViewModel::setModel(std::shared_ptr<Model> model_ptr)
{
    model = model_ptr;
}

std::shared_ptr<OpenFileCommand> ViewModel::getOpenFileCommand()
{
    return openFileCommand;
}

void ViewModel::openImage(const std::string &file_name)
{
    model->openImage(file_name);
}

void ViewModel::setImageList(std::shared_ptr<ImageList> image_list)
{
    this->image_list = image_list;
}

std::shared_ptr<ImageList> ViewModel::getImageList()
{
    return image_list;
}

void ViewModel::setUpdateNotification(std::shared_ptr<Notification> notification)
{
    this->notification = notification;
}

std::shared_ptr<Notification> ViewModel::getUpdateNotification()
{
    return notification;
}
