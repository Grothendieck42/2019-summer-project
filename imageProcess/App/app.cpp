#include "app.h"

ImageApp::ImageApp() : view(std::make_shared<MainWindow>()), model(std::make_shared<Model>()), viewModel(std::make_shared<ViewModel>())
{
    // view model绑定model
    viewModel->setModel(model);
    // view绑定view model中的数据
    view->setQImage(viewModel->getQImage());
    // view绑定命令
    view->setOpenFileCommand(viewModel->getOpenFileCommand());
    view->setSaveFileCommand(viewModel->getSaveFileCommand());
    view->setLightContrastCommand(viewModel->getLightContrastCommand());
    view->setTmpLightContrastCommand(viewModel->getTmpLightContrastCommand());
    view->setToGrayCommmand(viewModel->getToGrayCommand());
    view->setToBinaryCommmand(viewModel->getToBinaryCommand());
    view->setAverBlurCommand(viewModel->getAverBlurCommand());
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
