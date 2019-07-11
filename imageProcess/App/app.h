#pragma once
#include <QApplication>
#include "../View/mainwindow.h"
#include <iostream>
#include "../Model/Model.h"
#include "../ViewModel/ViewModel.h"
#include "../View/Notification/UpdateNotification.h"

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
