#pragma once
#include <memory>
#include <QImage>
#include "../Common/ImageList.h"
#include "Command/OpenFileCommand.h"
#include "Command/SaveFileCommand.h"
#include "Command/ToGrayCommand.h"
#include "Command/ToBibaryCommand.h"
#include "../Common/Notification.h"
#include "Notification/UpdateDataNotification.h"

class Model;

class ViewModel
{
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<OpenFileCommand> openFileCommand;
    std::shared_ptr<SaveFileCommand> saveFileCommand;
    std::shared_ptr<ToGrayCommand> toGrayCommand;
    std::shared_ptr<ToBinaryCommand> toBinaryCommand;
    std::shared_ptr<QImage> qImage;
    std::shared_ptr<Notification> notification;
    std::shared_ptr<UpdateDataNotification> updateNotification;
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> model_ptr);
    std::shared_ptr<Command> getOpenFileCommand();
    std::shared_ptr<Command> getSaveFileCommand();
    std::shared_ptr<Command> getToGrayCommand();
    std::shared_ptr<Command> getToBinaryCommand();
    void openImage(const std::string &file_name);
    void saveImage(const std::string &file_name);
    void toGray();
    void toBinary(int& threshold);
    std::shared_ptr<QImage> getQImage();
    void setUpdateNotification(std::shared_ptr<Notification> notification);
    void notify();
};
