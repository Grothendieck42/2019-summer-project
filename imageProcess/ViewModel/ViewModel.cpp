#include "ViewModel.h"
#include "../Model/Model.h"

ViewModel::ViewModel() 
    : openFileCommand(std::make_shared<OpenFileCommand>(this)),
      saveFileCommand(std::make_shared<SaveFileCommand>(this)),
      lightContrastCommand(std::make_shared<LightContrastCommand>(this)),
      toGrayCommand(std::make_shared<ToGrayCommand>(this)),
      toBinaryCommand(std::make_shared<ToBinaryCommand>(this)),
      detectEdgeCommand(std::make_shared<DetectEdgeCommand>(this)),
      grayEqualizeHistCommand(std::make_shared<GrayEqualizeHistCommand>(this)),
      colorEqualizeHistCommand(std::make_shared<ColorEqualizeHistCommand>(this)),
      laplaceCommand(std::make_shared<LaplaceCommand>(this)),
      logEnhanceCommand(std::make_shared<LogEnhanceCommand>(this)),
      gammaCorrectCommand(std::make_shared<GammaCorrectCommand>(this)),
      addGaussNoiseCommand(std::make_shared<AddGaussNoiseCommand>(this)),
      addSaltNoiseCommand(std::make_shared<AddSaltNoiseCommand>(this)),
      imageSegmentationCommand(std::make_shared<ImageSegmentationCommand>(this)),
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

std::shared_ptr<Command> ViewModel::getToGrayCommand()
{
    return toGrayCommand;
}

std::shared_ptr<Command> ViewModel::getToBinaryCommand()
{
    return toBinaryCommand;
}

std::shared_ptr<Command> ViewModel::getDetectEdgeCommand()
{
    return detectEdgeCommand;
}

std::shared_ptr<Command> ViewModel::getGrayEqualizeHistCommand()
{
    return grayEqualizeHistCommand;
}

std::shared_ptr<Command> ViewModel::getColorEqualizeHistCommand()
{
    return colorEqualizeHistCommand;
}

std::shared_ptr<Command> ViewModel::getLaplaceCommand()
{
    return laplaceCommand;
}

std::shared_ptr<Command> ViewModel::getLogEnhanceCommand()
{
    return logEnhanceCommand;
}

std::shared_ptr<Command> ViewModel::getGammaCorrectCommand()
{
    return gammaCorrectCommand;
}

std::shared_ptr<Command> ViewModel::getAddGaussNoiseCommand()
{
    return addGaussNoiseCommand;
}

std::shared_ptr<Command> ViewModel::getAddSaltNoiseCommand()
{
    return addSaltNoiseCommand;
}

std::shared_ptr<Command> ViewModel::getImageSegmentationCommand()
{
    return imageSegmentationCommand;
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

void ViewModel::toGray()
{
    model->toGray();
}

void ViewModel::toBinary(int& threshold)
{
    model->toBinary(threshold);
}

void ViewModel::detectEdge(int &threshold)
{
    model->detectEdge(threshold);
}

void ViewModel::grayEqualizeHist()
{
    model->grayEqualizeHist();
}

void ViewModel::colorEqualizeHist()
{
    model->colorEqualizeHist();
}

void ViewModel::laplace(){
    model->laplace();
}

void ViewModel::logEnhance(){
    model->logEnhance();
}

void ViewModel::gammaCorrect(float &fGamma){
    model->gammaCorrect(fGamma);
}

void ViewModel::addGaussNoise(){
    model->addGaussNoise();
}

void ViewModel::addSaltNoise(int &n){
    model->addSaltNoise(n);
}

void ViewModel::imageSegmentation(int &threshold){
    model->imageSegmentation(threshold);
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
