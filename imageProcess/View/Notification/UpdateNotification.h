#pragma once
#include "../../Common/Notification.h"
class MainWindow;
class UpdateNotification: public Notification
{
private:
    MainWindow* view;
public:
    UpdateNotification(MainWindow* view);
	void notify();
	~UpdateNotification();
};
