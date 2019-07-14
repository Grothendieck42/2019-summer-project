#include "myImage.h"
#include "../Utility/utility.h"
#include <QDebug>

Image::Image()
{

}

Image::~Image()
{

}

Image::Image(const Image &im)
{
    image = im.image.clone();
}

Image& Image::operator=(const Image &im)
{
    if(this != &im)
    {
        image = im.image.clone();
    }
    return *this;
}

void Image::openImage(const std::string &file_path)
{
    image = cv::imread(file_path);
}

void Image::saveImage(const std::string &file_path)
{
    cv::imwrite(file_path, image);
}

void Image::changeImageLightContrast(int light, int contrast)
{
	for(auto i = 0; i < image.rows; i++)
	{
		for(auto j = 0; j < image.cols; j++)
		{
			// 3通道
			for(auto c = 0; c < 3; c++)
			{
                image.at<cv::Vec3b>(i, j)[c]  = cv::saturate_cast<uchar>((contrast*0.01*(image.at<cv::Vec3b>(i, j)[c])) + light);
			}
		}
	}
}

void Image::averBlur()
{
    cv::blur(image, image, cv::Size(5,5));
}

void Image::midBlur()
{
    cv::medianBlur(image, image, 5);
}

void Image::gaussBlur()
{
    cv::GaussianBlur(image, image, cv::Size(5, 5), 5, 5);
}

Image Image::bilaterBlur()
{
    Image new_image;
    cv::bilateralFilter(image, new_image.image, 15, 150, 3);
    return new_image;
}

void Image::toGray(){
    cv::cvtColor(image,image,cv::COLOR_RGB2GRAY);
}

void Image::toBinary(int& threshold){
    cv::threshold(image, image, threshold, 255, cv::THRESH_BINARY);
}

void Image::detectEdge(int &threshold){
    cv::blur(image, image, cv::Size(3, 3));
    cv::Canny(image, image, threshold, threshold * 3, 3);
}

void Image::grayEqualizeHist(){
    cv::equalizeHist(image,image);
}

void Image::logEnhance(){
    cv::Mat imageLog(image.size(), CV_32FC3);
    for (int i = 0; i < image.rows; ++i)
    {
        for (int j = 0; j < image.cols; ++j)
        {
            imageLog.at<cv::Vec3f>(i, j)[0] = log(1 + image.at<cv::Vec3b>(i, j)[0]);
            imageLog.at<cv::Vec3f>(i, j)[1] = log(1 + image.at<cv::Vec3b>(i, j)[1]);
            imageLog.at<cv::Vec3f>(i, j)[2] = log(1 + image.at<cv::Vec3b>(i, j)[2]);
        }
    }
    //归一化到0~255
    cv::normalize(imageLog, imageLog, 0, 255, cv::NORM_MINMAX);
    cv::convertScaleAbs(imageLog, imageLog);
    image=imageLog;
}

void Image::colorEqualizeHist(){
    std::vector<cv::Mat> channels;
    //R G B三个通道
    cv::Mat imageBlueChannel, imageGreenChannel, imageRedChannel;
    //分离图像
    cv::split(image, channels);
    imageBlueChannel = channels.at(0);
    imageGreenChannel = channels.at(1);
    imageRedChannel = channels.at(2);
    //分别对每一个通道就行直方图均衡化
    cv::equalizeHist(imageBlueChannel, imageBlueChannel);
    cv::equalizeHist(imageGreenChannel, imageGreenChannel);
    cv::equalizeHist(imageRedChannel, imageRedChannel);
    //将直方图均衡化的通道合并起来
    cv::merge(channels, image);
}

void Image::laplace(){
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1);
    cv::filter2D(image, image, CV_8UC3, kernel);
}

void Image::gammaCorrect(float& fGamma){
    unsigned char lut[256];
    for(int i = 0; i < 256; ++i )
    {
        lut[i] = cv::saturate_cast<uchar>(pow((float)(i/255.0), fGamma) * 255.0f);
    }
    const int channels = image.channels();
    switch(channels)
    {
        case 1:   //灰度图的情况
        {
            cv::MatIterator_<uchar> it, end;
            for( it = image.begin<uchar>(), end = image.end<uchar>(); it != end; ++it )
                *it = lut[(*it)];
            break;
        }
        case 3:  //彩色图的情况
        {
            cv::MatIterator_<cv::Vec3b> it, end;
            for( it = image.begin<cv::Vec3b>(), end = image.end<cv::Vec3b>(); it != end; ++it )
            {
                (*it)[0] = lut[((*it)[0])];
                (*it)[1] = lut[((*it)[1])];
                (*it)[2] = lut[((*it)[2])];
            }
            break;
        }
    }
}

double Image::generateGaussianNoise(double mu, double sigma){
    const double epsilon = std::numeric_limits<double>::min();//返回目标数据类型能表示的最逼近1的正数和1的差的绝对值
    static double z0, z1;
    static bool flag = false;
    flag = !flag;
    //flag为假，构造高斯随机变量
    if (!flag)
        return z1*sigma + mu;
    double u1, u2;
    //构造随机变量
    do
    {
        u1 = rand()*(1.0 / RAND_MAX);
        u2 = rand()*(1.0 / RAND_MAX);
    } while (u1 <= epsilon);
    //flag为真构造高斯随机变量X
    z0 = sqrt(-2.0*log(u1))*cos(2 * CV_PI * u2);
    z1 = sqrt(-2.0*log(u1))*sin(2 * CV_PI * u2);
    return z1*sigma + mu;
}

void Image::addGaussNoise(){
    int channels = image.channels();
    int nRows = image.rows;
    int nCols = image.cols*channels;   //图像的总列数
    //判断图像的连续性
    if (image.isContinuous())    //判断矩阵是否连续，若连续，我们相当于只需要遍历一个一维数组
    {
        nCols *= nRows;
        nRows = 1;
    }
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {	//添加高斯噪声
            int val = image.ptr<uchar>(i)[j] + generateGaussianNoise(2, 0.8) * 32;
            if (val < 0)
                val = 0;
            if (val > 255)
                val = 255;
            image.ptr<uchar>(i)[j] = (uchar)val;
        }
    }
}

void Image::addSaltNoise(int &n){
    for (int k = 0; k < n; ++k)
    {
        //随机取值行列
        int i = rand() % image.cols;
        int j = rand() % image.rows;
        //图像通道判定
        if (image.channels() == 1)
            image.at<uchar>(j, i) = 255;
        else
        {
            image.at<cv::Vec3b>(j, i)[0] = 255;
            image.at<cv::Vec3b>(j, i)[1] = 255;
            image.at<cv::Vec3b>(j, i)[2] = 255;
        }
    }
}

void Image::imageSegmentation(int &threshold)
{
    cv::Mat imageGray;
    cv::cvtColor(image,imageGray,cv::COLOR_RGB2GRAY);//灰度转换
    cv::GaussianBlur(imageGray,imageGray,cv::Size(5,5),2);   //高斯滤波
    Canny(imageGray,imageGray,threshold,threshold*3);
    //查找轮廓
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(imageGray,contours,hierarchy,cv::RETR_TREE,cv::CHAIN_APPROX_SIMPLE,cv::Point());
    cv::Mat imageContours=cv::Mat::zeros(image.size(),CV_8UC1);  //轮廓
    cv::Mat marks(image.size(),CV_32S);   //Opencv分水岭第二个矩阵参数
    marks=cv::Scalar::all(0);
    int index = 0;
    int compCount = 0;
    for( ; index >= 0; index = hierarchy[index][0], ++compCount )
    {
        //对marks进行标记，对不同区域的轮廓进行编号，相当于设置注水点，有多少轮廓，就有多少注水点
        cv::drawContours(marks, contours, index, cv::Scalar::all(compCount+1), 1, 8, hierarchy);
        cv::drawContours(imageContours,contours,index,cv::Scalar(255),1,8,hierarchy);
    }
    cv::watershed(image,marks);
    //对每一个区域进行颜色填充
    cv::Mat PerspectiveImage=cv::Mat::zeros(image.size(),CV_8UC3);
    for(int i=0;i<marks.rows;++i)
    {
        for(int j=0;j<marks.cols;++j)
        {
            int index=marks.at<int>(i,j);
            if(marks.at<int>(i,j)==-1)
            {
                PerspectiveImage.at<cv::Vec3b>(i,j)=cv::Vec3b(255,255,255);
            }
            else
            {
                index%=255;
                cv::RNG rng;
                int a=rng.uniform(0,index);
                int b=rng.uniform(0,index);
                int c=rng.uniform(0,index);
                PerspectiveImage.at<cv::Vec3b>(i,j) = cv::Vec3b(a,b,c);
            }
        }
    }
    image=PerspectiveImage;
    //cv::addWeighted(image,0.4,PerspectiveImage,0.6,0,image);
}

void Image::imageEnlarge()
{
    cv::resize(image,image,cv::Size(image.cols*1.1,image.rows*1.1),0,0,cv::INTER_CUBIC);
}

void Image::imageReduct()
{
    cv::resize(image,image,cv::Size(image.cols*0.9,image.rows*0.9),0,0,cv::INTER_AREA);
}

QImage Image::getQImage()
{
    return MatToQImage(image);
}

void Image::show()
{
    cv::imshow("hh", image);
    cv::waitKey(1000);
}
