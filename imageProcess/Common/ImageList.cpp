#include "ImageList.h"
#include <cassert>

ImageList::ImageList()
{

}
ImageList::~ImageList()
{

}

Image ImageList::getImage()
{
    assert(image_list.size() != 0);
	return image_list[image_list.size()-1];
}
void ImageList::addImage(const Image& image)
{
	image_list.push_back(image);
}
void ImageList::deleteImage()
{
	image_list.pop_back();
}

int ImageList::size()
{
    return image_list.size();
}

void ImageList::clearList(){
    std::vector<Image>().swap(image_list);
}
