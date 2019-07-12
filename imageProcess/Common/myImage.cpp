#include "myImage.h"
#include "../Utility/utility.h"
#include <QDebug>

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

void Image::toGray(){
    cv::cvtColor(image,image,cv::COLOR_RGB2GRAY);
}

void Image::toBinary(int& threshold){
    cv::threshold(image, image, threshold, 255, cv::THRESH_BINARY);
}

QImage Image::getQImage()
{
    return MatToQImage(image);
}

void Image::show()
{
    cv::imshow("hh", image);
    cv::waitKey(0);
}
