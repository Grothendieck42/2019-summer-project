#pragma once
#include <vector>
#include "myImage.h"
class ImageList
{
private:
	std::vector<Image> image_list;
public:
	ImageList();
	~ImageList();
	QImage getQImage();

    // 返回引用
    // 目的是为了修改相关的image
    Image getImage();
    void addImage(const Image& image);
	void deleteImage();
    void clearList();
};
