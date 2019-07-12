#pragma once
#include <memory>
#include <QImage>
#include "../Common/ImageList.h"
#include "Command/OpenFileCommand.h"
#include "Command/SaveFileCommand.h"
#include "Command/LightContrastCommand.h"
#include "../Common/Notification.h"
#include "Notification/UpdateDataNotification.h"

class Model;

class ViewModel
{
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<OpenFileCommand> openFileCommand;
    std::shared_ptr<SaveFileCommand> saveFileCommand;
    std::shared_ptr<LightContrastCommand> lightContrastCommand;
    std::shared_ptr<QImage> qImage;
    std::shared_ptr<Notification> notification;
    std::shared_ptr<UpdateDataNotification> updateNotification;
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> model_ptr);
    std::shared_ptr<Command> getOpenFileCommand();
    std::shared_ptr<Command> getSaveFileCommand();
    std::shared_ptr<Command> getLightContrastCommand();
    void openImage(const std::string &file_name);
    void saveImage(const std::string &file_name);
    void changeImageLightContrast(int light, int contrast);
    std::shared_ptr<QImage> getQImage();
    void setUpdateNotification(std::shared_ptr<Notification> notification);
    void notify();
};
