#include "AnnotateFacesCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

AnnotateFacesCommand::AnnotateFacesCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

AnnotateFacesCommand::~AnnotateFacesCommand()
{
    // nothing
}

bool AnnotateFacesCommand::exec()
{
    return viewModel->annotateFaces(modelPath);
}

void AnnotateFacesCommand::setParameter(std::any params)
{
    modelPath = *std::any_cast<std::string>(&params);
}
