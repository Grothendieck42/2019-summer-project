#pragma once
#include "../ViewModel/ViewModel.h"
#include "../Common/myImage.h"
#include "../Common/ImageList.h"
#include "../Common/Notification.h"
#include <string>

class Model
{
private:
    std::shared_ptr<ImageList> imageList;
    std::shared_ptr<Notification> notification;
    std::shared_ptr<Notification> tmpNotification;
public:
    Model();
    ~Model();
    void openImage(const std::string &file_name);
    void saveImage(const std::string &file_name);
    void changeImageLightContrast(int light, int contrast);
    void changeTmpImageLightContrast(int light, int contrast);
    void averBlur();
    void midBlur();
    void gaussBlur();
    void bilaterBlur();
    void toGray();
    void toBinary(int& threshold);
    void detectEdge(int& threshold);
    void grayEqualizeHist();
    void colorEqualizeHist();
    void laplace();
    void logEnhance();
    void gammaCorrect(float& fGamma);
    void addGaussNoise();
    void addSaltNoise(int& n);
    void imageSegmentation(int& threshold);
    void imageEnlarge();
    void imageReduct();
    std::shared_ptr<ImageList> getImageList();
    void setUpdateNotification(std::shared_ptr<Notification> notification);
    void setUpdateTmpNotification(std::shared_ptr<Notification> notification);
};
