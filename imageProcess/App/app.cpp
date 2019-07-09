#include "app.h"

ImageApp::ImageApp() : view(std::make_shared<MainWindow>()), model(std::make_shared<Model>()), viewModel(std::make_shared<ViewModel>())
{
    // view model绑定model
    viewModel->setModel(model);
    // model绑定view model
    model->setViewModel(viewModel);
    // view model绑定命令
    viewModel->setOpenFileCommand(viewModel);
    // 绑定底层图片
    view->setImage(model->getImage());
}

ImageApp::~ImageApp()
{

}

void ImageApp::run()
{
    view->show();
}
