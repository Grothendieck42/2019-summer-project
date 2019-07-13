#include "ViewModel.h"
#include "../Model/Model.h"

ViewModel::ViewModel() 
    : openFileCommand(std::make_shared<OpenFileCommand>(this)),
      saveFileCommand(std::make_shared<SaveFileCommand>(this)),
      lightContrastCommand(std::make_shared<LightContrastCommand>(this)),
      tmpLightContrastCommand(std::make_shared<TmpLightContrastCommand>(this)),
      toGrayCommand(std::make_shared<ToGrayCommand>(this)),
      toBinaryCommand(std::make_shared<ToBinaryCommand>(this)),
      averBlurCommand(std::make_shared<AverBlurCommand>(this)),
      qImage(std::make_shared<QImage>()),
      updateNotification(std::make_shared<UpdateDataNotification>(this)),
      updateTmpNotification(std::make_shared<UpdateTmpNotification>(this))
{

}

ViewModel::~ViewModel()
{

}

void ViewModel::setModel(std::shared_ptr<Model> model_ptr)
{
    model = model_ptr;
    model->setUpdateNotification(updateNotification);
    model->setUpdateTmpNotification(updateTmpNotification);
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

std::shared_ptr<Command> ViewModel::getTmpLightContrastCommand()
{
  return tmpLightContrastCommand;
}

std::shared_ptr<Command> ViewModel::getToGrayCommand()
{
    return toGrayCommand;
}

std::shared_ptr<Command> ViewModel::getToBinaryCommand()
{
    return toBinaryCommand;
}

std::shared_ptr<Command> ViewModel::getAverBlurCommand()
{
  return averBlurCommand;
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

void ViewModel::changeTmpImageLightContrast(int light, int contrast)
{
    model->changeTmpImageLightContrast(light, contrast);
}

void ViewModel::averBlur()
{
  model->averBlur();
}

void ViewModel::toGray()
{
    model->toGray();
}

void ViewModel::toBinary(int& threshold)
{
    model->toBinary(threshold);
}

std::shared_ptr<QImage> ViewModel::getQImage()
{
    return qImage;
}

void ViewModel::setUpdateNotification(std::shared_ptr<Notification> notification)
{
    this->notification = notification;
}

void ViewModel::convert()
{
    *qImage = model->getImageList()->getImage().getQImage();
    notify();
}

void ViewModel::notify()
{
    notification->notify();
}
