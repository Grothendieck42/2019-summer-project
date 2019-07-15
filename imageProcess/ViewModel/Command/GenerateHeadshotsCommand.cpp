#include "GenerateHeadshotsCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

GenerateHeadshotsCommand::GenerateHeadshotsCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

GenerateHeadshotsCommand::~GenerateHeadshotsCommand()
{
    // nothing
}

bool GenerateHeadshotsCommand::exec()
{
    return viewModel->generateHeadshots(outputdir);
}

void GenerateHeadshotsCommand::setParameter(std::any params)
{
    outputdir = *std::any_cast<std::string>(&params);
}
