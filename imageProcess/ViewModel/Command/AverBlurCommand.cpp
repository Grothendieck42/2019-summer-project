#include "AverBlurCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

AverBlurCommand::AverBlurCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

AverBlurCommand::~AverBlurCommand()
{
    // nothing
}

bool AverBlurCommand::exec()
{
    return viewModel->averBlur();
}

void AverBlurCommand::setParameter(std::any params)
{
    
}
