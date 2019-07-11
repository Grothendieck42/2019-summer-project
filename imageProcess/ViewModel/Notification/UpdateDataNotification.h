#pragma once
#include "../../Common/Notification.h"
class ViewModel;
class UpdateDataNotification: public Notification
{
    ViewModel* viewModel;
public:
    UpdateDataNotification(ViewModel* viewModel);
	~UpdateDataNotification();
	void notify();
};
