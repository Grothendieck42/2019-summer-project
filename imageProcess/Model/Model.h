#pragma once
#include "../ViewModel/ViewModel.h"
#include "../Common/myImage.h"
#include "../Common/ImageList.h"
#include "../Common/Notification.h"
#include <string>

class Model
{
private:
    std::shared_ptr<ViewModel> viewModel;
    std::shared_ptr<ImageList> imageList;
    std::shared_ptr<Notification> notification;
public:
    Model();
    ~Model();
    void openImage(const std::string &file_name);
    void saveImage(const std::string &file_name);
    std::shared_ptr<ImageList> getImageList();
    void setUpdateNotification(std::shared_ptr<Notification> notification);
};
