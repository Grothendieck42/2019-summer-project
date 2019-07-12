#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <QImage>

class Image
{
private:
    cv::Mat image;
public:
    Image();
    ~Image();
    void show();
    QImage getQImage();
    void openImage(const std::string &file_path);
    void saveImage(const std::string &file_path);
    void changeImageLightContrast(int light, int contrast);
    void toGray();
    void toBinary(int& threshold);
};
