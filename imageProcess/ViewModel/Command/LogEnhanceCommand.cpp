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

bool LogEnhanceCommand::exec()
{
    return viewModel->logEnhance();
}

void LogEnhanceCommand::setParameter(std::any params)
{
   //file_name = *std::any_cast<std::string>(&params);
}
