#include "OpenFileCommand.h"
#include "../ViewModel/ViewModel.h"
#include <any>
#include <string>

OpenFileCommand::OpenFileCommand(std::shared_ptr<ViewModel> view_model) : viewModel(view_model)
{
    // nothing
}

OpenFileCommand::~OpenFileCommand()
{
    // nothing
}

void OpenFileCommand::exec()
{
    auto p = parameter->get(0);
    auto file_name = *std::any_cast<std::string>(&p);
    viewModel->openImage(file_name);
}

void OpenFileCommand::setParameter(std::shared_ptr<Parameter> &param)
{
    parameter = param;
}
