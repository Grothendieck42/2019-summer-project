#include "ColorEqualizeHistCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

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
   //file_name = *std::any_cast<std::string>(&params);
}
