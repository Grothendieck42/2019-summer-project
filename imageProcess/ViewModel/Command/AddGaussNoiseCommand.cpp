#include "AddGaussNoiseCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

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
   //file_name = *std::any_cast<std::string>(&params);
}
