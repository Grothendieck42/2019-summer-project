#include "ViewModel.h"
#include "../Model/Model.h"

ViewModel::ViewModel() 
    : openFileCommand(std::make_shared<OpenFileCommand>(this)),
      saveFileCommand(std::make_shared<SaveFileCommand>(this)),
      lightContrastCommand(std::make_shared<LightContrastCommand>(this)),
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

std::shared_ptr<Command> ViewModel::getOpenFileCommand()
{
    return openFileCommand;
}

std::shared_ptr<Command> ViewModel::getSaveFileCommand()
{
    return saveFileCommand;
}

std::shared_ptr<Command> ViewModel::getLightContrastCommand()
{
  return lightContrastCommand;
}

void ViewModel::openImage(const std::string &file_name)
{
    model->openImage(file_name);
}

void ViewModel::saveImage(const std::string &file_name)
{
    model->saveImage(file_name);
}

void ViewModel::changeImageLightContrast(int light, int contrast)
{
  model->changeImageLightContrast(light, contrast);
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
