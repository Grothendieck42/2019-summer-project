#include "myImage.h"
#include "../Utility/utility.h"

Image::Image()
{

}

Image::~Image()
{

}

void Image::openImage(const std::string &file_path)
{
    image = cv::imread(file_path);
}

void Image::saveImage(const std::string &file_path)
{
    cv::imwrite(file_path, image);
}

QImage Image::getQImage()
{
    return MatToQImage(image);
}
