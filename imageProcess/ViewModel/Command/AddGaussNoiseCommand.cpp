#include "AddGaussNoiseCommand.h"
#include "../ViewModel.h"
#include <any>

AddGaussNoiseCommand::AddGaussNoiseCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

AddGaussNoiseCommand::~AddGaussNoiseCommand()
{
    // nothing
}

bool AddGaussNoiseCommand::exec()
{
    return viewModel->addGaussNoise();
}

void AddGaussNoiseCommand::setParameter(std::any params)
{
}
