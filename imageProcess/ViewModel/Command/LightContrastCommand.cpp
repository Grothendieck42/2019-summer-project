#include "LightContrastCommand.h"
#include "../ViewModel.h"
#include "../../Common/Common.h"
#include <any>

LightContrastCommand::LightContrastCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

LightContrastCommand::~LightContrastCommand()
{
    // nothing
}

bool LightContrastCommand::exec()
{
    return viewModel->changeImageLightContrast(light, contrast);
}

void LightContrastCommand::setParameter(std::any params)
{
    auto light_contrast = std::any_cast<struct lightContrast>(&params);
    contrast = light_contrast->contrast;
    light = light_contrast->light;
}
