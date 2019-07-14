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
    Image getImage();
    void addImage(const Image& image);
	void deleteImage();
    int size();
    void clearList();
};
