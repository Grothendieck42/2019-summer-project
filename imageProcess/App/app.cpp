#include "app.h"
#include <QDebug>

ImageApp::ImageApp() : view(std::make_shared<MainWindow>()), model(std::make_shared<Model>()), viewModel(std::make_shared<ViewModel>())
{
    // view model绑定model
    viewModel->setModel(model);
    // model绑定view model
    model->setViewModel(viewModel);
    // view model绑定命令
    viewModel->setOpenFileCommand(viewModel);
    // view model绑定view
    viewModel->setView(view);
    // 绑定底层图片
    view->setImageList(model->getImageList());
    // view绑定命令
    view->setOpenFileCommand(viewModel->getOpenFileCommand());
}

ImageApp::~ImageApp()
{

}

void ImageApp::run()
{
    view->show();
}
