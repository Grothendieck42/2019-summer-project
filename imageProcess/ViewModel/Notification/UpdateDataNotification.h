#pragma once
#include "../../Common/Notification.h"
class ViewModel;
class UpdateDataNotification: public Notification
{
private:
    ViewModel* viewModel;
public:
    UpdateDataNotification(ViewModel* viewModel);
	~UpdateDataNotification();
	void notify();
    void setParameter(std::any params);
};
