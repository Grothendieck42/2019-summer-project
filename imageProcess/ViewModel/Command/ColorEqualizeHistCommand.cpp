#include "ColorEqualizeHistCommand.h"
#include "../ViewModel.h"
#include <any>

ColorEqualizeHistCommand::ColorEqualizeHistCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ColorEqualizeHistCommand::~ColorEqualizeHistCommand()
{
    // nothing
}

bool ColorEqualizeHistCommand::exec()
{
    return viewModel->colorEqualizeHist();
}

void ColorEqualizeHistCommand::setParameter(std::any params)
{

}
