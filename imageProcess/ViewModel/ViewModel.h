#pragma once
#include <memory>
#include "../View/mainwindow.h"
#include "../Command/OpenFileCommand.h"
#include <iostream>

class Model;

class ViewModel
{
private:
    std::shared_ptr<MainWindow> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<OpenFileCommand> openFileCommand;
public:
    ViewModel();
    ~ViewModel();
    void setModel(std::shared_ptr<Model> &model_ptr);
    void setView(std::shared_ptr<MainWindow> &view);
    std::shared_ptr<OpenFileCommand> getOpenFileCommand();
    void openImage(std::string file_name);
    void setOpenFileCommand(std::shared_ptr<ViewModel> view_model);
    void update();
};
