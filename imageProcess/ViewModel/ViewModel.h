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
#include "../Common/Notification.h"
#include "Notification/UpdateDataNotification.h"
#include "Notification/UpdateTmpNotification.h"

class Model;

class ViewModel
{
private:
    std::shared_ptr<Model> model;
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
    std::shared_ptr<QImage> qImage;
    std::shared_ptr<Notification> notification;
    std::shared_ptr<UpdateDataNotification> updateNotification;
    std::shared_ptr<UpdateTmpNotification> updateTmpNotification;
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> model_ptr);
    std::shared_ptr<Command> getOpenFileCommand();
    std::shared_ptr<Command> getSaveFileCommand();
    std::shared_ptr<Command> getLightContrastCommand();
    std::shared_ptr<Command> getTmpLightContrastCommand();
    void openImage(const std::string &file_name);
    void saveImage(const std::string &file_name);
    void averBlur();
    void midBlur();
    void gaussBlur();
    void bilaterBlur();
    void changeTmpImageLightContrast(int light, int contrast);
    void changeImageLightContrast(int light, int contrast);
    std::shared_ptr<Command> getAverBlurCommand();
    std::shared_ptr<Command> getMidBlurCommand();
    std::shared_ptr<Command> getGaussBlurCommand();
    std::shared_ptr<Command> getBilaterBlurCommand();
    std::shared_ptr<Command> getToGrayCommand();
    std::shared_ptr<Command> getToBinaryCommand();
    void toGray();
    void toBinary(int& threshold);
    std::shared_ptr<QImage> getQImage();
    void setUpdateNotification(std::shared_ptr<Notification> notification);
    void convert();
    void notify();
};
