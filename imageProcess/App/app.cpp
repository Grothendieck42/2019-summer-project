#include "app.h"
#include <QDebug>

ImageApp::ImageApp() : view(std::make_shared<MainWindow>()), model(std::make_shared<Model>()), viewModel(std::make_shared<ViewModel>())
{
    // view model绑定model
    viewModel->setModel(model);
    // view绑定view model中的数据
    view->setImageList(viewModel->getImageList());
    // view绑定命令
    view->setOpenFileCommand(viewModel->getOpenFileCommand());
    // view model绑定notifiacation
    viewModel->setUpdateNotification(view->getNotification());
    // model绑定notification
    model->setUpdateNotification(viewModel->getUpdateNotification());
}

ImageApp::~ImageApp()
{

}

void ImageApp::run()
{
    view->show();
}