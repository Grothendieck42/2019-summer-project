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

void LightContrastCommand::exec()
{
    viewModel->changeImageLightContrast(old_light, old_contrast, light, contrast);
}

void LightContrastCommand::setParameter(std::any params)
{
    auto light_contrast = std::any_cast<struct lightContrast>(&params);
    old_light = light_contrast->old_light;
    old_contrast = light_contrast->old_contrast;
    contrast = light_contrast->contrast;
    light = light_contrast->light;
}
