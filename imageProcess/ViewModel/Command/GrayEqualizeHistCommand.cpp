#include "GrayEqualizeHistCommand.h"
#include "../ViewModel.h"
#include <any>

GrayEqualizeHistCommand::GrayEqualizeHistCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

GrayEqualizeHistCommand::~GrayEqualizeHistCommand()
{
    // nothing
}

bool GrayEqualizeHistCommand::exec()
{
    return viewModel->grayEqualizeHist();
}

void GrayEqualizeHistCommand::setParameter(std::any params)
{
}
