#pragma once
#include <QApplication>
#include "../View/mainwindow.h"
#include "../Model/Model.h"
#include "../ViewModel/ViewModel.h"

class ImageApp
{
private:
    std::shared_ptr<MainWindow> view;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewModel;
public:
    ImageApp();
    ~ImageApp();
    void run();
};
