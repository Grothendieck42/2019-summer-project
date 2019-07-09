#pragma once
#include "../ViewModel/ViewModel.h"
#include "../Common/myImage.h"
#include <string>

class Model
{
private:
    std::shared_ptr<ViewModel> viewModel;
    std::shared_ptr<Image> image;
public:
    Model();
    ~Model();
    void setViewModel(std::shared_ptr<ViewModel> view_model);
    void openImage(const std::string &file_name);
    void saveImage(const std::string &file_name);
    std::shared_ptr<Image> getImage();
    void notify();
};
