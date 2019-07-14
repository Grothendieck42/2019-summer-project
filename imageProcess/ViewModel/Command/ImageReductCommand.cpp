#include "ImageReductCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

ImageReductCommand::ImageReductCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ImageReductCommand::~ImageReductCommand()
{
    // nothing
}

void ImageReductCommand::exec()
{
    viewModel->imageReduct();
}

void ImageReductCommand::setParameter(std::any params)
{

}
