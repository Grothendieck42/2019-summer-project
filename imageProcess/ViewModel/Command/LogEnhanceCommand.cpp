#include "LogEnhanceCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

LogEnhanceCommand::LogEnhanceCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

LogEnhanceCommand::~LogEnhanceCommand()
{
    // nothing
}

void LogEnhanceCommand::exec()
{
    viewModel->logEnhance();
}

void LogEnhanceCommand::setParameter(std::any params)
{
   //file_name = *std::any_cast<std::string>(&params);
}
