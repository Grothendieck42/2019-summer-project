#include <QImage>
#include <opencv2/opencv.hpp>

QImage MatToQImage(const cv::Mat& mat);
cv::Mat QImageToMat(QImage image);
