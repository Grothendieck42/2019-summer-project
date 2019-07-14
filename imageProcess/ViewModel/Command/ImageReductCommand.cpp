#include "ImageReductCommand.h"
#include "../ViewModel.h"
#include <any>

ImageReductCommand::ImageReductCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ImageReductCommand::~ImageReductCommand()
{
    // nothing
}

bool ImageReductCommand::exec()
{
    return viewModel->imageReduct();
}

void ImageReductCommand::setParameter(std::any params)
{

}
