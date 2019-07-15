#include "app.h"

ImageApp::ImageApp() : view(std::make_shared<MainWindow>()), model(std::make_shared<Model>()), viewModel(std::make_shared<ViewModel>())
{
    // view model绑定model
    viewModel->setModel(model);
    // view绑定view model中的数据
    view->setQImage(viewModel->getQImage());
    // view绑定命令
    view->setOpenFileCommand(viewModel->getOpenFileCommand());
    view->setDisplayNowCommand(viewModel->getDisplayNowCommand());
    view->setSaveFileCommand(viewModel->getSaveFileCommand());
    view->setLightContrastCommand(viewModel->getLightContrastCommand());
    view->setTmpLightContrastCommand(viewModel->getTmpLightContrastCommand());
    view->setAverBlurCommand(viewModel->getAverBlurCommand());
    view->setMidBlurCommand(viewModel->getMidBlurCommand());
    view->setGaussBlurCommand(viewModel->getGaussBlurCommand());
    view->setBilaterBlurCommand(viewModel->getBilaterBlurCommand());
    view->setToGrayCommand(viewModel->getToGrayCommand());
    view->setToBinaryCommand(viewModel->getToBinaryCommand());
    view->setDetectEdgeCommand(viewModel->getDetectEdgeCommand());
    view->setGrayEqualizeHistCommand(viewModel->getGrayEqualizeHistCommand());
    view->setColorEqualizeHistCommand(viewModel->getColorEqualizeHistCommand());
    view->setLaplaceCommand(viewModel->getLaplaceCommand());
    view->setLogEnhanceCommand(viewModel->getLogEnhanceCommand());
    view->setGammaCorrectCommand(viewModel->getGammaCorrectCommand());
    view->setAddGaussNoiseCommand(viewModel->getAddGaussNoiseCommand());
    view->setAddSaltNoiseCommand(viewModel->getAddSaltNoiseCommand());
    view->setImageSegmentationCommand(viewModel->getImageSegmentationCommand());
    view->setImageEnlargeCommand(viewModel->getImageEnlargeCommand());
    view->setImageReductCommand(viewModel->getImageReductCommand());
    view->setImageGuidedCommand(viewModel->getImageGuidedCommand());
    view->setImageDefogCommand(viewModel->getImageDefogCommand());
    view->setTrainModelCommand(viewModel->getTrainEigenModelCommand());
    view->setDetectFacesCommand(viewModel->getDetectFacesCommand());
    view->setAnnotateFacesCommand(viewModel->getAnnotateFacesCommand());
    view->setBeautifyFacesCommand(viewModel->getBeautifyFacesCommand());
    view->setGenerateHeadshotsCommand(viewModel->getGenerateHeadshotsCommand());
    view->setUndoCommand(viewModel->getUndoCommand());
    // view model绑定notifiacation
    viewModel->setUpdateNotification(view->getNotification());
}

ImageApp::~ImageApp()
{

}

void ImageApp::run()
{
    view->show();
}
