#pragma once
#include <memory>
#include <QImage>
#include "../Common/ImageList.h"
#include "Command/OpenFileCommand.h"
#include "../Common/Notification.h"
#include "Notification/UpdateDataNotification.h"

class Model;

class ViewModel
{
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<OpenFileCommand> openFileCommand;
    std::shared_ptr<QImage> qImage;
    std::shared_ptr<Notification> notification;
    std::shared_ptr<UpdateDataNotification> updateNotification;
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> model_ptr);
    std::shared_ptr<OpenFileCommand> getOpenFileCommand();
    void openImage(const std::string &file_name);
    std::shared_ptr<QImage> getQImage();
    std::shared_ptr<UpdateDataNotification> getUpdateDataNotification();
    void setUpdateNotification(std::shared_ptr<Notification> notification);
    void notify();
};
