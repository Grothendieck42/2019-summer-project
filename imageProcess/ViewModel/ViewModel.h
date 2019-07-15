#pragma once
#include <memory>
#include <QImage>
#include "../Common/ImageList.h"
#include "Command/OpenFileCommand.h"
#include "Command/SaveFileCommand.h"
#include "Command/LightContrastCommand.h"
#include "Command/TmpLightContrastCommand.h"
#include "Command/ToGrayCommand.h"
#include "Command/ToBibaryCommand.h"
#include "Command/AverBlurCommand.h"
#include "Command/MidBlurCommand.h"
#include "Command/GaussBlurCommand.h"
#include "Command/BilaterBlurCommand.h"
#include "Command/DetectEdgeCommand.h"
#include "Command/GrayEqualizeHistCommand.h"
#include "Command/ColorEqualizeHistCommand.h"
#include "Command/LaplaceCommand.h"
#include "Command/LogEnhanceCommand.h"
#include "Command/UndoCommand.h"
#include "Command/GammaCorrectCommand.h"
#include "Command/AddGaussNoiseCommand.h"
#include "Command/AddSaltNoiseCommand.h"
#include "Command/ImageSegmentationCommand.h"
#include "Command/DisplayNowCommand.h"
#include "Command/ImageEnlargeCommand.h"
#include "Command/ImageReductCommand.h"
#include "Command/ImageGuidedCommand.h"
#include "Command/ImageDefogCommand.h"
#include "Command/TrainEigenModelCommand.h"
#include "Command/DetectFacesCommand.h"
#include "Command/AnnotateFacesCommand.h"
#include "Command/BeautifyFacesCommand.h"
#include "Command/GenerateHeadshotsCommand.h"
#include "../Common/Notification.h"
#include "Notification/UpdateDataNotification.h"
#include "Notification/UpdateTmpNotification.h"

class Model;

class ViewModel
{
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<UndoCommand> undoCommand;
    std::shared_ptr<DisplayNowCommand> displayNowCommand;
    std::shared_ptr<OpenFileCommand> openFileCommand;
    std::shared_ptr<SaveFileCommand> saveFileCommand;
    std::shared_ptr<LightContrastCommand> lightContrastCommand;
    std::shared_ptr<TmpLightContrastCommand> tmpLightContrastCommand;
    std::shared_ptr<ToGrayCommand> toGrayCommand;
    std::shared_ptr<ToBinaryCommand> toBinaryCommand;
    std::shared_ptr<AverBlurCommand> averBlurCommand;
    std::shared_ptr<MidBlurCommand> midBlurCommand;
    std::shared_ptr<GaussBlurCommand> gaussBlurCommand;
    std::shared_ptr<BilaterBlurCommand> bilaterBlurCommand;
    std::shared_ptr<DetectEdgeCommand> detectEdgeCommand;
    std::shared_ptr<GrayEqualizeHistCommand> grayEqualizeHistCommand;
    std::shared_ptr<ColorEqualizeHistCommand> colorEqualizeHistCommand;
    std::shared_ptr<LaplaceCommand> laplaceCommand;
    std::shared_ptr<LogEnhanceCommand> logEnhanceCommand;
    std::shared_ptr<GammaCorrectCommand> gammaCorrectCommand;
    std::shared_ptr<AddGaussNoiseCommand> addGaussNoiseCommand;
    std::shared_ptr<AddSaltNoiseCommand> addSaltNoiseCommand;
    std::shared_ptr<ImageSegmentationCommand> imageSegmentationCommand;
    std::shared_ptr<ImageEnlargeCommand> imageEnlargeCommand;
    std::shared_ptr<ImageReductCommand> imageReductCommand;
    std::shared_ptr<ImageGuidedCommand> imageGuidedCommand;
    std::shared_ptr<ImageDefogCommand> imageDefogCommand;
    std::shared_ptr<QImage> qImage;
    std::shared_ptr<Notification> notification;
    std::shared_ptr<UpdateDataNotification> updateNotification;
    std::shared_ptr<UpdateTmpNotification> updateTmpNotification;
    std::shared_ptr<TrainEigenModelCommand> trainEigenModelCommand;
    std::shared_ptr<DetectFacesCommand> detectFacesCommand;
    std::shared_ptr<AnnotateFacesCommand> annotateFacesCommand;
    std::shared_ptr<BeautifyFacesCommand> beautifyFacesCommand;
    std::shared_ptr<GenerateHeadshotsCommand> generateHeadshotsCommand;

public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> model_ptr);
    std::shared_ptr<Command> getOpenFileCommand();
    std::shared_ptr<Command> getSaveFileCommand();
    std::shared_ptr<Command> getLightContrastCommand();
    std::shared_ptr<Command> getTmpLightContrastCommand();
    bool openImage(const std::string &file_name);
    bool saveImage(const std::string &file_name);
    bool averBlur();
    bool midBlur();
    bool gaussBlur();
    bool bilaterBlur();
    bool changeTmpImageLightContrast(int light, int contrast);
    bool changeImageLightContrast(int light, int contrast);
    std::shared_ptr<Command> getUndoCommand();
    std::shared_ptr<Command> getDisplayNowCommand();
    std::shared_ptr<Command> getAverBlurCommand();
    std::shared_ptr<Command> getMidBlurCommand();
    std::shared_ptr<Command> getGaussBlurCommand();
    std::shared_ptr<Command> getBilaterBlurCommand();
    std::shared_ptr<Command> getToGrayCommand();
    std::shared_ptr<Command> getToBinaryCommand();
    std::shared_ptr<Command> getDetectEdgeCommand();
    std::shared_ptr<Command> getGrayEqualizeHistCommand();
    std::shared_ptr<Command> getColorEqualizeHistCommand();
    std::shared_ptr<Command> getLaplaceCommand();
    std::shared_ptr<Command> getLogEnhanceCommand();
    std::shared_ptr<Command> getGammaCorrectCommand();
    std::shared_ptr<Command> getAddGaussNoiseCommand();
    std::shared_ptr<Command> getAddSaltNoiseCommand();
    std::shared_ptr<Command> getImageSegmentationCommand();
    std::shared_ptr<Command> getImageEnlargeCommand();
    std::shared_ptr<Command> getImageReductCommand();
    std::shared_ptr<Command> getImageGuidedCommand();
    std::shared_ptr<Command> getImageDefogCommand();
    std::shared_ptr<Command> getTrainEigenModelCommand();
    std::shared_ptr<Command> getDetectFacesCommand();
    std::shared_ptr<Command> getAnnotateFacesCommand();
    std::shared_ptr<Command> getBeautifyFacesCommand();
    std::shared_ptr<Command> getGenerateHeadshotsCommand();
    bool imageGuided(float& eps);
    bool imageDefog();
    bool display();
    bool undo();
    bool toGray();
    bool toBinary(int& threshold);
    bool detectEdge(int& threshold);
    bool grayEqualizeHist();
    bool colorEqualizeHist();
    bool laplace();
    bool logEnhance();
    bool gammaCorrect(float& fGamma);
    bool addGaussNoise();
    bool addSaltNoise(int& n);
    bool imageSegmentation(int& threshold);
    bool imageEnlarge();
    bool imageReduct();
    std::shared_ptr<QImage> getQImage();
    void setUpdateNotification(std::shared_ptr<Notification> notification);
    void convert();
    void notify();
    bool trainModel(const std::string &dataPath);
    bool detectFaces(const std::string &modelPath);
    bool annotateFaces(const std::string &modelPath);
    bool beautifyFaces();
    bool generateHeadshots(const std::string &outputPath);
};
