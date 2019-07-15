#include "BeautifyFacesCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

BeautifyFacesCommand::BeautifyFacesCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

BeautifyFacesCommand::~BeautifyFacesCommand()
{
    // nothing
}

bool BeautifyFacesCommand::exec()
{
    return viewModel->beautifyFaces();
}

void BeautifyFacesCommand::setParameter(std::any params)
{

}
