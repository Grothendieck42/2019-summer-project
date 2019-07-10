#include "Model.h"

Model::Model() : imageList(std::make_shared<ImageList>())
{

}

Model::~Model()
{

}

void Model::openImage(const std::string &file_name)
{
    Image image;
    image.openImage(file_name);
    imageList->addImage(image);
    notify();
}

void Model::saveImage(const std::string &file_name)
{
    imageList->getImage().saveImage(file_name);
}

std::shared_ptr<ImageList> Model::getImageList()
{
    return imageList;
}

void Model::notify()
{
    viewModel->update();
}

void Model::setViewModel(std::shared_ptr<ViewModel> view_model)
{
    viewModel = view_model;
}

