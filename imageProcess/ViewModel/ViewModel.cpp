#include "ViewModel.h"
#include "../Model/Model.h"

ViewModel::ViewModel() 
    : undoCommand(std::make_shared<UndoCommand>(this)),
      displayNowCommand(std::make_shared<DisplayNowCommand>(this)),
      openFileCommand(std::make_shared<OpenFileCommand>(this)),
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
      trainEigenModelCommand(std::make_shared<TrainEigenModelCommand>(this)),
      detectFacesCommand(std::make_shared<DetectFacesCommand>(this)),
      annotateFacesCommand(std::make_shared<AnnotateFacesCommand>(this)),
      beautifyFacesCommand(std::make_shared<BeautifyFacesCommand>(this))

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

std::shared_ptr<Command> ViewModel::getDisplayNowCommand()
{
    return displayNowCommand;
}

std::shared_ptr<Command> ViewModel::getUndoCommand()
{
    return undoCommand;
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

bool ViewModel::undo()
{
    return model->undo();
}

bool ViewModel::display()
{
    return model->display();
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

bool ViewModel::openImage(const std::string &file_name)
{
    return model->openImage(file_name);
}

bool ViewModel::saveImage(const std::string &file_name)
{
    return model->saveImage(file_name);
}


bool ViewModel::changeImageLightContrast(int light, int contrast)
{
    return model->changeImageLightContrast(light, contrast);
}

bool ViewModel::changeTmpImageLightContrast(int light, int contrast)
{
    return model->changeTmpImageLightContrast(light, contrast);
}

bool ViewModel::averBlur()
{
    return model->averBlur();
}

bool ViewModel::midBlur()
{
    return model->midBlur();
}

bool ViewModel::gaussBlur()
{
    return model->gaussBlur();
}

bool ViewModel::bilaterBlur()
{
    return model->bilaterBlur();
}


bool ViewModel::toGray()
{
    return model->toGray();
}

bool ViewModel::toBinary(int& threshold)
{
    return model->toBinary(threshold);
}

bool ViewModel::detectEdge(int &threshold)
{
    return model->detectEdge(threshold);
}

bool ViewModel::grayEqualizeHist()
{
    return model->grayEqualizeHist();
}

bool ViewModel::colorEqualizeHist()
{
    return model->colorEqualizeHist();
}

bool ViewModel::laplace(){
    return model->laplace();
}

bool ViewModel::logEnhance(){
    return model->logEnhance();
}

bool ViewModel::gammaCorrect(float &fGamma){
    return model->gammaCorrect(fGamma);
}

bool ViewModel::addGaussNoise(){
    return model->addGaussNoise();
}

bool ViewModel::addSaltNoise(int &n){
    return model->addSaltNoise(n);
}

bool ViewModel::imageSegmentation(int &threshold){
    return model->imageSegmentation(threshold);
}

bool ViewModel::imageEnlarge(){
    return model->imageEnlarge();
}

bool ViewModel::imageReduct(){
    return model->imageReduct();
}

bool ViewModel::trainModel(const std::string &dataPath){
    return model->trainModel(dataPath);
}

bool ViewModel::detectFaces(const std::string &modelPath){
    return model->detectFaces(modelPath);
}

bool ViewModel::annotateFaces(const std::string &modelPath){
    return model->annotateFaces(modelPath);
}

bool ViewModel::beautifyFaces(){
    return model->beautifyFaces();
}

bool ViewModel::generateHeadshots(const std::string &outputPath){
    return model->generateHeadshots(outputPath);
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
