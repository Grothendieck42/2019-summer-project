#include "OpenFileCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

OpenFileCommand::OpenFileCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

OpenFileCommand::~OpenFileCommand()
{
    // nothing
}

void OpenFileCommand::exec()
{
    viewModel->openImage(file_name);
}

void OpenFileCommand::setParameter(std::any params)
{
    file_name = *std::any_cast<std::string>(&params);
}
