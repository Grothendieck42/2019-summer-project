#include "OpenFileCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>

OpenFileCommand::OpenFileCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

OpenFileCommand::~OpenFileCommand()
{
    // nothing
}

bool OpenFileCommand::exec()
{
    return viewModel->openImage(file_name);
}

void OpenFileCommand::setParameter(std::any params)
{
    file_name = *std::any_cast<std::string>(&params);
}
