#include "ImageDefogCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

ImageDefogCommand::ImageDefogCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ImageDefogCommand::~ImageDefogCommand()
{
    // nothing
}

void ImageDefogCommand::exec()
{
    viewModel->imageDefog();
}

void ImageDefogCommand::setParameter(std::any params)
{

}
