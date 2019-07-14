#include "ToBibaryCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>

ToBinaryCommand::ToBinaryCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ToBinaryCommand::~ToBinaryCommand()
{
    // nothing
}

bool ToBinaryCommand::exec()
{
    return viewModel->toBinary(threshold);
}

void ToBinaryCommand::setParameter(std::any params)
{
   threshold = *std::any_cast<int>(&params);
}
