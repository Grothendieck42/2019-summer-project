#include "MidBlurCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

MidBlurCommand::MidBlurCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

MidBlurCommand::~MidBlurCommand()
{
    // nothing
}

bool MidBlurCommand::exec()
{
    return viewModel->midBlur();
}

void MidBlurCommand::setParameter(std::any params)
{

}
