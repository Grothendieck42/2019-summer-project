#include "UpdateNotification.h"
#include "../mainwindow.h"

UpdateNotification::UpdateNotification(MainWindow* view) : view(view){}

void UpdateNotification::notify()
{
	view->update();
}

UpdateNotification::~UpdateNotification()
{

}
