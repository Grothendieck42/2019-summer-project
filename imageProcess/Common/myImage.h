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
    Image(const Image& im);
    Image& operator=(const Image &im);
    void show();
    bool empty();
    QImage getQImage();
    void openImage(const std::string &file_path);
    void saveImage(const std::string &file_path);
    void changeImageLightContrast(int light, int contrast);
    void averBlur();
    void midBlur();
    void gaussBlur();
    Image bilaterBlur();
    void toGray();
    void toBinary(int& threshold);
    void detectEdge(int& threshold);
    void grayEqualizeHist();
    void colorEqualizeHist();
    void laplace();
    void logEnhance();
    void gammaCorrect(float& fGamma);
    double generateGaussianNoise(double mu, double sigma);
    void addGaussNoise();
    void addSaltNoise(int& n);
    void imageSegmentation(int& threshold);
    bool checkGray();
    bool checkColor();
};
