#include "ImageGuidedCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

ImageGuidedCommand::ImageGuidedCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ImageGuidedCommand::~ImageGuidedCommand()
{
    // nothing
}

bool ImageGuidedCommand::exec()
{
    return viewModel->imageGuided(eps);
}

void ImageGuidedCommand::setParameter(std::any params)
{
    eps = *std::any_cast<float>(&params);
}
