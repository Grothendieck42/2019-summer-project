#include "LogEnhanceCommand.h"
#include "../ViewModel.h"
#include <any>

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
}
