#include "ToGrayCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>

ToGrayCommand::ToGrayCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ToGrayCommand::~ToGrayCommand()
{
    // nothing
}

bool ToGrayCommand::exec()
{
    return viewModel->toGray();
}

void ToGrayCommand::setParameter(std::any params)
{
   //file_name = *std::any_cast<std::string>(&params);
}
