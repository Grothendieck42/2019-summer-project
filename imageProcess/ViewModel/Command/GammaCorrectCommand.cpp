#include "GammaCorrectCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

GammaCorrectCommand::GammaCorrectCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

GammaCorrectCommand::~GammaCorrectCommand()
{
    // nothing
}

bool GammaCorrectCommand::exec()
{
    return viewModel->gammaCorrect(fGamma);
}

void GammaCorrectCommand::setParameter(std::any params)
{
    fGamma= *std::any_cast<float>(&params);
}