#pragma once
#include <memory>
#include "Command/OpenFileCommand.h"
#include "../Common/Notification.h"

class Model;

class ViewModel
{
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<OpenFileCommand> openFileCommand;
    std::shared_ptr<ImageList> image_list;
    std::shared_ptr<Notification> notification;
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> model_ptr);
    std::shared_ptr<ImageList> getImageList();
    std::shared_ptr<OpenFileCommand> getOpenFileCommand();
    void openImage(const std::string &file_name);
    void setUpdateNotification(std::shared_ptr<Notification> notification);
    std::shared_ptr<Notification> getUpdateNotification();
};
