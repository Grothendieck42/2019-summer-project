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
    cv::GaussianBlur(image, image, cv::Size(9, 9), 5, 5);
}

Image Image::bilaterBlur()
{
    Image new_image;
    cv::bilateralFilter(image, new_image.image, 15, 50, 10);
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

void Image::imageGuided(float &eps){
    cv::Mat newImage;
    cv::ximgproc::guidedFilter(image,image,newImage,16,eps,-1);
    image=newImage;
}

void Image::minFilter(const cv::Mat src,cv::Mat &dst,int ksize)
{
    //[1] --检测原始图像
    if(src.channels()!=1)
        return;
    if(src.depth()>8)
        return;
    //[1]

    int r=(ksize-1)/2; //核半径
    //初始化目标图像
    dst=cv::Mat::zeros(src.rows,src.cols,CV_8UC1);
    //[3] --最小值滤波
    for(int i=0;i<src.rows;++i)
        for(int j=0;j<src.cols;++j)
        {
            //[1] --初始化滤波核的上下左右边界
            int top=i-r;
            int bottom=i+r;
            int left=j-r;
            int right=j+r;
            //[1]

            //[2] --检查滤波核是否超出边界
            if(i-r<0)
                top=0;
            if(i+r>src.rows)
                bottom=src.rows;
            if(j-r<0)
                left=0;
            if(j+r>src.cols)
                right=src.cols;
            //[2]

            //[3] --求取模板下的最小值
            cv::Mat ImROI=src(cv::Range(top,bottom),cv::Range(left,right));
            double min,max;
            cv::minMaxLoc(ImROI,&min,&max,0,0);
            dst.at<uchar>(i,j)=min;
            //[3]
        }
}

cv::Mat Image::myGuidedFilter(cv::Mat g, cv::Mat p, int ksize)
{
    static const double eps =1.0e-5;//regularization parameter
    //类型转换
    cv::Mat _g;
    g.convertTo(_g,CV_64FC1);
    g=_g;

    cv::Mat _p;
    p.convertTo(_p,CV_64FC1);
    p=_p;

    //[hei, wid] = size(I);
    int hei = g.rows;
    int wid = g.cols;

    //N = boxfilter(ones(hei, wid), r); % the size of each local patch; N=(2r+1)^2 except for boundary pixels.
    cv::Mat N;
    cv::boxFilter(cv::Mat::ones(hei, wid, g.type()), N, CV_64FC1,cv::Size(ksize,ksize));

    //[1] --使用均值模糊求取各项系数
    cv::Mat mean_G;
    cv::boxFilter(g,mean_G,CV_64FC1,cv::Size(ksize,ksize));

    cv::Mat mean_P;
    cv::boxFilter(p,mean_P,CV_64FC1,cv::Size(ksize,ksize));

    cv::Mat GP=g.mul(p);
    cv::Mat mean_GP;
    cv::boxFilter(GP,mean_GP,CV_64FC1,cv::Size(ksize,ksize));

    cv::Mat GG=g.mul(g);
    cv::Mat mean_GG;
    cv::boxFilter(GG,mean_GG,CV_64FC1,cv::Size(ksize,ksize));

    cv::Mat cov_GP;
    cov_GP=mean_GP-mean_G.mul(mean_P);

    cv::Mat var_G;
    var_G=mean_GG-mean_G.mul(mean_G);
    //[1]

    //求系数a a=(mean(GP)-mean(G)mean(p))/(mean(GG)-mean(G)mean(G)+eps)
    cv::Mat a=cov_GP/(var_G+eps);

    //求系数b b=mean(P)-mean(G)*a
    cv::Mat b=mean_P-a.mul(mean_G);

    //求两个系数的均值
    cv::Mat mean_a;
    cv::boxFilter(a,mean_a,CV_64FC1,cv::Size(ksize,ksize));
    //mean_a=mean_a/N;

    cv::Mat mean_b;
    cv::boxFilter(b,mean_b,CV_64FC1,cv::Size(ksize,ksize));
    //mean_b=mean_b/N;

    //输出结果q
    cv::Mat q=mean_a.mul(g)+mean_b;

    return q;
}

cv::Mat Image::grayStretch(cv::Mat src,double lowcut,double highcut)
{
    //[1]--统计各通道的直方图
    //参数
    const int bins = 256;
    int hist_size=bins;
    float range[]={0,255};
    const float* ranges[]={range};
    cv::MatND desHist;
    int channels=0;
    //计算直方图
    cv::calcHist(&src,1,&channels,cv::Mat(),desHist,1,&hist_size,ranges,true,false);
    //[1]

    //[2] --计算上下阈值
    int pixelAmount=src.rows*src.cols; //像素总数
    float Sum=0;
    int minValue,maxValue;
    //求最小值
    for(int i=0;i<bins;++i)
    {
        Sum+=desHist.at<float>(i);
        if(Sum>=pixelAmount*lowcut*0.01)
        {
            minValue=i;
            break;
        }
    }

    //求最大值
    Sum=0;
    for(int i=bins-1;i>=0;--i)
    {
        Sum+=desHist.at<float>(i);
        if(Sum>=pixelAmount*highcut*0.01)
        {
            maxValue=i;
            break;
        }
    }
    //[2]

    //[3] --对各个通道进行线性拉伸
    cv::Mat dst=src;
    //判定是否需要拉伸
    if(minValue>maxValue)
        return src;

    for(int i=0;i<src.rows;++i)
        for(int j=0;j<src.cols;++j)
        {
            if(src.at<uchar>(i,j)<minValue)
                dst.at<uchar>(i,j)=0;
            if(src.at<uchar>(i,j)>maxValue)
                dst.at<uchar>(i,j)=255;
            else
            {
                //注意这里做除法要使用double类型
                double pixelValue=((src.at<uchar>(i,j)-minValue)/
                                   (double)(maxValue-minValue))*255;
                dst.at<uchar>(i,j)=(int)pixelValue;
            }
        }
    //[3]

    return dst;
}

void Image::imageDefog(){
    static const double kernRatio=0.01; //自适应核比例
    static const int minAtomLigth=220; //最小大气光强
    static const double wFactor=0.95; //w系数 用来调节
    static const double min_t =0.1; //最小透射率
    cv::Mat minRgb = cv::Mat::zeros(image.rows,image.cols,CV_8UC1);
    for(int i=0;i<image.rows;++i)
        for(int j=0;j<image.cols;++j)
        {
            uchar g_minvalue =255;
            for(int c=0;c<3;++c)
            {
                if(g_minvalue>image.at<cv::Vec3b>(i,j)[c])
                    g_minvalue=image.at<cv::Vec3b>(i,j)[c];
            }
            minRgb.at<uchar>(i,j)=g_minvalue;
        }
    cv::Mat darkChannelImage;
    int ksize=std::max(3,std::max((int)(image.cols*kernRatio),(int)(image.rows*kernRatio))); //求取自适应核大小
    minFilter(minRgb,darkChannelImage,ksize);
    cv::Mat t=cv::Mat::zeros(image.rows,image.cols,CV_64FC1);
    for(int i=0;i<image.rows;++i)
        for(int j=0;j<image.cols;++j)
        {
            t.at<double>(i,j)=(255.0-
                               (double)darkChannelImage.at<uchar>(i,j)*wFactor)/255;
        }
    double A;
    cv::Point maxLoc;
    cv::minMaxLoc(darkChannelImage,0,&A,0,&maxLoc);
    A=std::max(image.at<cv::Vec3b>(maxLoc.y,maxLoc.x)[0],
            std::max(image.at<cv::Vec3b>(maxLoc.y,maxLoc.x)[1],
            image.at<cv::Vec3b>(maxLoc.y,maxLoc.x)[2]));
    int r=ksize*8;  //导向滤波核  注意：该值一定要取得足够大
    cv::Mat gray;
    cv::cvtColor(image,gray,cv::COLOR_BGR2GRAY);
    cv::Mat guild_t;
    guild_t=myGuidedFilter(gray,t,r);
    cv::Mat deFog=cv::Mat::zeros(image.rows,image.cols,CV_64FC3);
    for(int i=0;i<image.rows;++i)
        for(int j=0;j<image.cols;++j)
            for(int c=0;c<image.channels();++c)
                deFog.at<cv::Vec3d>(i,j)[c]=(image.at<cv::Vec3b>(i,j)[c]-
                                          (1-guild_t.at<double>(i,j))*A)/
                        std::max(guild_t.at<double>(i,j),min_t);
    deFog.convertTo(deFog,CV_8UC3);
    //cv::Mat channels[3];
    //cv::split(deFog,channels);
    //for(int c=0;c<3;++c)
    //    channels[c]= grayStretch(channels[c],0.001,0.5); //根据实验 暗色像素的比例应该设置的较小效果会比较好
    //merge(channels,3,deFog);
    image=deFog;
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
