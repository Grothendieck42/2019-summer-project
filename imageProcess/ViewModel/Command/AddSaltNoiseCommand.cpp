#include "AddSaltNoiseCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

AddSaltNoiseCommand::AddSaltNoiseCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

AddSaltNoiseCommand::~AddSaltNoiseCommand()
{
    // nothing
}

void AddSaltNoiseCommand::exec()
{
    viewModel->addSaltNoise(n);
}

void AddSaltNoiseCommand::setParameter(std::any params)
{
    n = *std::any_cast<int>(&params);
}
