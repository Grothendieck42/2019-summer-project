#pragma once
#include <opencv2/opencv.hpp>
#include <QImage>

class Image
{
private:
    cv::Mat image;
public:
    Image();
    ~Image();
    QImage getQImage();
    void openImage(const std::string &file_path);
    void saveImage(const std::string &file_path);
};
