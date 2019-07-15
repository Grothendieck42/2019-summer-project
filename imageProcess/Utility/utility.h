#include <QImage>
#include <opencv2/opencv.hpp>
#include "facelib.h"
QImage MatToQImage(const cv::Mat& mat);
cv::Mat QImageToMat(QImage image);
void progressGo(int old, int value, QProgressDialog* ptr);
