#include "UpdateNotification.h"
#include "../mainwindow.h"

UpdateNotification::UpdateNotification(MainWindow* view) : view(view){}

void UpdateNotification::setParameter(std::any params)
{
	
}

void UpdateNotification::notify()
{
	view->update();
}

UpdateNotification::~UpdateNotification()
{

}
