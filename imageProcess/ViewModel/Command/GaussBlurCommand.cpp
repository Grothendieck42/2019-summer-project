#include "GaussBlurCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

GaussBlurCommand::GaussBlurCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

GaussBlurCommand::~GaussBlurCommand()
{
    // nothing
}

bool GaussBlurCommand::exec()
{
    return viewModel->gaussBlur();
}

void GaussBlurCommand::setParameter(std::any params)
{

}
