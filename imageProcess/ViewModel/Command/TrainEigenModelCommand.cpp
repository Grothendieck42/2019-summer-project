#include "TrainEigenModelCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

TrainEigenModelCommand::TrainEigenModelCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

TrainEigenModelCommand::~TrainEigenModelCommand()
{
    // nothing
}

void TrainEigenModelCommand::exec()
{
    viewModel->trainModel(dataPath);
}

void TrainEigenModelCommand::setParameter(std::any params)
{
    dataPath = *std::any_cast<std::string>(&params);
}
