#include "Model.h"
#include <QDebug>

Model::Model() : imageList(std::make_shared<ImageList>())
{

}

Model::~Model()
{

}

// Model对于当前图片的操作需要这样来完成
// 首先获取当前图片的拷贝
// Image image = imageList->getImage();
// 进行操作后需要通知更改
// notification->notify();
// 具体操作写在myImage.cpp Image对象中
// Model层调用底层的方法

void Model::openImage(const std::string &file_name)
{
    imageList->clearList();
    Image image;
    image.openImage(file_name);
    imageList->addImage(image);
    notification->notify();
}

void Model::saveImage(const std::string &file_name)
{
    imageList->getImage().saveImage(file_name);
}

void Model::toGray()
{
    Image newImage=imageList->getImage();
    newImage.toGray();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::toBinary(int &threshold)
{
    Image newImage=imageList->getImage();
    newImage.toBinary(threshold);
    imageList->addImage(newImage);
    notification->notify();
}

void Model::detectEdge(int &threshold)
{
    Image newImage=imageList->getImage();
    newImage.detectEdge(threshold);
    imageList->addImage(newImage);
    notification->notify();
}

std::shared_ptr<ImageList> Model::getImageList()
{
    return imageList;
}

void Model::changeImageLightContrast(int light, int contrast)
{
	Image image = imageList->getImage();
    image.changeImageLightContrast(light, contrast);
	imageList->addImage(image);
	notification->notify();
}

void Model::changeTmpImageLightContrast(int light, int contrast)
{
    Image image = imageList->getImage();
    image.changeImageLightContrast(light, contrast);
    tmpNotification->setParameter(image);
    tmpNotification->notify();
}

void Model::averBlur()
{
    Image image = imageList->getImage();
    image.averBlur();
    imageList->addImage(image);
    notification->notify();
}

void Model::midBlur()
{
    Image image = imageList->getImage();
    image.midBlur();
    imageList->addImage(image);
    notification->notify();
}

void Model::gaussBlur()
{
    Image image = imageList->getImage();
    image.gaussBlur();
    imageList->addImage(image);
    notification->notify();
}

void Model::bilaterBlur()
{
    Image image = imageList->getImage();
    imageList->addImage(image.bilaterBlur());
    notification->notify();
}

void Model::grayEqualizeHist()
{
    Image newImage=imageList->getImage();
    newImage.grayEqualizeHist();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::colorEqualizeHist()
{
    Image newImage=imageList->getImage();
    newImage.colorEqualizeHist();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::laplace(){
    Image newImage=imageList->getImage();
    newImage.laplace();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::logEnhance(){
    Image newImage=imageList->getImage();
    newImage.logEnhance();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::gammaCorrect(float &fGamma){
    Image newImage=imageList->getImage();
    newImage.gammaCorrect(fGamma);
    imageList->addImage(newImage);
    notification->notify();
}

void Model::addGaussNoise(){
    Image newImage=imageList->getImage();
    newImage.addGaussNoise();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::addSaltNoise(int &n){
    Image newImage=imageList->getImage();
    newImage.addSaltNoise(n);
    imageList->addImage(newImage);
    notification->notify();
}

void Model::imageSegmentation(int &threshold){
    Image newImage=imageList->getImage();
    newImage.imageSegmentation(threshold);
    imageList->addImage(newImage);
    notification->notify();
}

void Model::imageEnlarge(){
    Image newImage=imageList->getImage();
    newImage.imageEnlarge();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::imageReduct(){
    Image newImage=imageList->getImage();
    newImage.imageReduct();
    imageList->addImage(newImage);
    notification->notify();
}

void Model::trainModel(const std::string &dataPath){
//    std::cout<<"Train data in path: "+dataPath<<std::endl;
//    QProgressDialog *m_pConnectProBar = new QProgressDialog();
//    m_pConnectProBar->setRange(0,100);
//    m_pConnectProBar->setOrientation(Qt::Horizontal);
//    m_pConnectProBar->setValue(10);
//    m_pConnectProBar->setVisible(true);
//    m_pConnectProBar->setWindowTitle("Please Wait");
//    m_pConnectProBar->setLabelText("Starting...");

    string list_name = dataPath+"/list";
    ifstream info_list(list_name);
    char buf[100];
    while (!info_list.eof() && type_number<maxnum)
    {
        memset(buf, 0, 100);
        info_list.getline(buf, 100);
        const std::string file = train_dir + "/" + string(buf);
        cout << file << endl;
        cv::Mat img,gray;
        vector<Rect> faces;
        img = cv::imread(file);
        Image *image = new Image();
        image->openImage(file);
        cout << image->getMat().size() << endl;
        if (!img.empty()) {
            cout << file << endl;
            addphoto();
            cvtColor(img, gray, CV_BGR2GRAY);
            equalizeHist(gray, gray);
            resize(gray, gray, Size(model_width, model_height));
            addrow(gray);

        }
    }
    train_eigen_face(dataPath, NULL);
//    m_pConnectProBar->setVisible(false);
}

void Model::detectFaces(const std::string &modelPath){

}

void Model::annotateFaces(const std::string &modelPath){

}

void Model::beautifyFaces(){

}

void Model::generateHeadshots(const std::string &outputPath){

}

void Model::setUpdateNotification(std::shared_ptr<Notification> notification)
{
    this->notification = notification;
}

void Model::setUpdateTmpNotification(std::shared_ptr<Notification> notification)
{
    tmpNotification = notification;
}

