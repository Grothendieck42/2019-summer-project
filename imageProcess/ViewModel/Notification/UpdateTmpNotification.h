#pragma once
#include "../../Common/Notification.h"
#include "../../Common/myImage.h"
class ViewModel;
class UpdateTmpNotification: public Notification
{
private:
    ViewModel* viewModel;
    Image image;
public:
    UpdateTmpNotification(ViewModel* viewModel);
    ~UpdateTmpNotification();
    void notify();
    void setParameter(std::any params);
};
