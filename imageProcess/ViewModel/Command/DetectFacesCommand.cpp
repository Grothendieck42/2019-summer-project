#include "AnnotateFacesCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

DetectFacesCommand::DetectFacesCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

DetectFacesCommand::~DetectFacesCommand()
{
    // nothing
}

bool DetectFacesCommand::exec()
{
    return viewModel->detectFaces(classifierPath);
}

void DetectFacesCommand::setParameter(std::any params)
{
    classifierPath = *std::any_cast<std::string>(&params);
}
