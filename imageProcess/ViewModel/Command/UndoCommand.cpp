#include "UndoCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

UndoCommand::UndoCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

UndoCommand::~UndoCommand()
{
    // nothing
}

bool UndoCommand::exec()
{
    return viewModel->undo();
}

void UndoCommand::setParameter(std::any params)
{

}
