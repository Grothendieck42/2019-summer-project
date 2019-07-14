#include "DisplayNowCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

DisplayNowCommand::DisplayNowCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

DisplayNowCommand::~DisplayNowCommand()
{
    // nothing
}

bool DisplayNowCommand::exec()
{
    return viewModel->display();
}

void DisplayNowCommand::setParameter(std::any params)
{

}
