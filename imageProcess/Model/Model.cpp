#include "Model.h"

Model::Model() : image(std::make_shared<Image>())
{

}

Model::~Model()
{

}

void Model::openImage(const std::string &file_name)
{
    image->openImage(file_name);
}

void Model::saveImage(const std::string &file_name)
{
    image->saveImage(file_name);
}

std::shared_ptr<Image> Model::getImage()
{
    return image;
}

void Model::notify()
{
    viewModel->update();
}

void Model::setViewModel(std::shared_ptr<ViewModel> view_model)
{
    viewModel = view_model;
}

