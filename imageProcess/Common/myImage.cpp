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

QImage Image::getQImage()
{
//    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);//图像格式转换
//    QImage disImage = QImage((const unsigned char*)(image.data),image.cols,image.rows,QImage::Format_RGB888);
    return MatToQImage(image);
}

void Image::show()
{
    cv::imshow("hh", image);
    cv::waitKey(0);
}
