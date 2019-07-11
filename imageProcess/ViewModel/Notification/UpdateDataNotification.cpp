#include "UpdateDataNotification.h"
#include "../ViewModel.h"
UpdateDataNotification::UpdateDataNotification(ViewModel* viewModel) : viewModel(viewModel)
{

}

UpdateDataNotification::~UpdateDataNotification()
{

}

void UpdateDataNotification::notify()
{
    viewModel->notify();
}
