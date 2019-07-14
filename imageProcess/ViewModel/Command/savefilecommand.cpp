#include "SaveFileCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

SaveFileCommand::SaveFileCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

SaveFileCommand::~SaveFileCommand()
{
    // nothing
}

bool SaveFileCommand::exec()
{
    return viewModel->saveImage(file_name);
}

void SaveFileCommand::setParameter(std::any params)
{
    file_name = *std::any_cast<std::string>(&params);
}
