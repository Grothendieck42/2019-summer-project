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
      midBlurCommand(std::make_shared<MidBlurCommand>(this)),
      gaussBlurCommand(std::make_shared<GaussBlurCommand>(this)),
      bilaterBlurCommand(std::make_shared<BilaterBlurCommand>(this)),
      detectEdgeCommand(std::make_shared<DetectEdgeCommand>(this)),
      grayEqualizeHistCommand(std::make_shared<GrayEqualizeHistCommand>(this)),
      colorEqualizeHistCommand(std::make_shared<ColorEqualizeHistCommand>(this)),
      laplaceCommand(std::make_shared<LaplaceCommand>(this)),
      logEnhanceCommand(std::make_shared<LogEnhanceCommand>(this)),
      gammaCorrectCommand(std::make_shared<GammaCorrectCommand>(this)),
      addGaussNoiseCommand(std::make_shared<AddGaussNoiseCommand>(this)),
      addSaltNoiseCommand(std::make_shared<AddSaltNoiseCommand>(this)),
      imageSegmentationCommand(std::make_shared<ImageSegmentationCommand>(this)),
      imageEnlargeCommand(std::make_shared<ImageEnlargeCommand>(this)),
      imageReductCommand(std::make_shared<ImageReductCommand>(this)),
      qImage(std::make_shared<QImage>()),
      updateNotification(std::make_shared<UpdateDataNotification>(this)),
      updateTmpNotification(std::make_shared<UpdateTmpNotification>(this)),
      trainEigenModelCommand(std::make_shared<TrainEigenModelCommand>(this))
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

std::shared_ptr<Command> ViewModel::getMidBlurCommand()
{
  return midBlurCommand;
}

std::shared_ptr<Command> ViewModel::getBilaterBlurCommand()
{
  return bilaterBlurCommand;
}

std::shared_ptr<Command> ViewModel::getGaussBlurCommand()
{
  return gaussBlurCommand;
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

std::shared_ptr<Command> ViewModel::getImageEnlargeCommand(){
    return imageEnlargeCommand;
}

std::shared_ptr<Command> ViewModel::getImageReductCommand(){
    return imageReductCommand;
}

std::shared_ptr<Command> ViewModel::getTrainEigenModelCommand(){
    return trainEigenModelCommand;
}

std::shared_ptr<Command> ViewModel::getDetectFacesCommand(){
    return detectFacesCommand;
}

std::shared_ptr<Command> ViewModel::getAnnotateFacesCommand(){
    return annotateFacesCommand;
}

std::shared_ptr<Command> ViewModel::getBeautifyFacesCommand(){
    return beautifyFacesCommand;
}

std::shared_ptr<Command> ViewModel::getGenerateHeadshotsCommand(){
    return generateHeadshotsCommand;
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

void ViewModel::midBlur()
{
  model->midBlur();
}

void ViewModel::gaussBlur()
{
  model->gaussBlur();
}

void ViewModel::bilaterBlur()
{
  model->bilaterBlur();
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

void ViewModel::imageEnlarge(){
    model->imageEnlarge();
}

void ViewModel::imageReduct(){
    model->imageReduct();
}

void ViewModel::trainModel(const std::string &dataPath){
    model->trainModel(dataPath);
}

void ViewModel::detectFaces(const std::string &modelPath){
    model->detectFaces(modelPath);
}

void ViewModel::annotateFaces(const std::string &modelPath){
    model->annotateFaces(modelPath);
}

void ViewModel::beautifyFaces(){
    model->beautifyFaces();
}

void ViewModel::generateHeadshots(const std::string &outputPath){
    model->generateHeadshots(outputPath);
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
