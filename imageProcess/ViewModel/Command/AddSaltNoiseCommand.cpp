#include "AddSaltNoiseCommand.h"
#include "../ViewModel.h"
#include <any>

AddSaltNoiseCommand::AddSaltNoiseCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

AddSaltNoiseCommand::~AddSaltNoiseCommand()
{
    // nothing
}

bool AddSaltNoiseCommand::exec()
{
    return viewModel->addSaltNoise(n);
}

void AddSaltNoiseCommand::setParameter(std::any params)
{
    n = *std::any_cast<int>(&params);
}
