#include "BilaterBlurCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

BilaterBlurCommand::BilaterBlurCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

BilaterBlurCommand::~BilaterBlurCommand()
{
    // nothing
}

bool BilaterBlurCommand::exec()
{
    return viewModel->bilaterBlur();
}

void BilaterBlurCommand::setParameter(std::any params)
{

}
