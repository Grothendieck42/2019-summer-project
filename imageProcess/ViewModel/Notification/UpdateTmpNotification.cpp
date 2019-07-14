#include "UpdateTmpNotification.h"
#include "../ViewModel.h"

UpdateTmpNotification::UpdateTmpNotification(ViewModel* viewModel) : viewModel(viewModel)
{

}

UpdateTmpNotification::~UpdateTmpNotification()
{

}

void UpdateTmpNotification::notify()
{
    *(viewModel->getQImage()) = image.getQImage();
    viewModel->notify();
}

void UpdateTmpNotification::setParameter(std::any params)
{
    this->image = *std::any_cast<Image>(&params);
}

