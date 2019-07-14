#include "ImageEnlargeCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

ImageEnlargeCommand::ImageEnlargeCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ImageEnlargeCommand::~ImageEnlargeCommand()
{
    // nothing
}

void ImageEnlargeCommand::exec()
{
    viewModel->imageEnlarge();
}

void ImageEnlargeCommand::setParameter(std::any params)
{

}
