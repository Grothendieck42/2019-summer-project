#include "ViewModel.h"
#include "../Model/Model.h"

ViewModel::ViewModel()
{

}

ViewModel::~ViewModel()
{

}

void ViewModel::setModel(std::shared_ptr<Model> &model_ptr)
{
    model = model_ptr;
}

std::shared_ptr<OpenFileCommand> ViewModel::getOpenFileCommand()
{
    return openFileCommand;
}

void ViewModel::setOpenFileCommand(std::shared_ptr<ViewModel> view_model)
{
    openFileCommand = std::make_shared<OpenFileCommand>(view_model);
}

void ViewModel::openImage(std::string file_name)
{
    model->openImage(file_name);
}

void ViewModel::setView(std::shared_ptr<MainWindow> &view)
{
    this->view = view;
}

void ViewModel::update()
{
    view->update();
}
