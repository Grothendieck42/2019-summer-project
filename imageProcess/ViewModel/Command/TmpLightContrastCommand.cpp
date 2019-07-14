#include "TmpLightContrastCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

TmpLightContrastCommand::TmpLightContrastCommand(ViewModel* view_model) : viewModel(view_model)
{

}

TmpLightContrastCommand::~TmpLightContrastCommand()
{

}

bool TmpLightContrastCommand::exec()
{
    return viewModel->changeTmpImageLightContrast(light, contrast);
}

void TmpLightContrastCommand::setParameter(std::any params)
{
    auto light_contrast = std::any_cast<struct lightContrast>(&params);
    contrast = light_contrast->contrast;
    light = light_contrast->light;
}
