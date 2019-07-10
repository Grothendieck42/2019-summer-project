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
	Image& getImage();
    void addImage(const Image& image);
	void deleteImage();
};
