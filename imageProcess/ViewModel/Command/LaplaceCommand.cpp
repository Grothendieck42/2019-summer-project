#include "LaplaceCommand.h"
#include "../ViewModel.h"
#include <any>

LaplaceCommand::LaplaceCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

LaplaceCommand::~LaplaceCommand()
{
    // nothing
}

bool LaplaceCommand::exec()
{
    return viewModel->laplace();
}

void LaplaceCommand::setParameter(std::any params)
{
   //file_name = *std::any_cast<std::string>(&params);
}
