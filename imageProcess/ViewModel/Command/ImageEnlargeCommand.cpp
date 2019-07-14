#include "ImageEnlargeCommand.h"
#include "../ViewModel.h"
#include <any>

ImageEnlargeCommand::ImageEnlargeCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ImageEnlargeCommand::~ImageEnlargeCommand()
{
    // nothing
}

bool ImageEnlargeCommand::exec()
{
    return viewModel->imageEnlarge();
}

void ImageEnlargeCommand::setParameter(std::any params)
{

}
