#include"core/ImageLoader.h"

cv::Mat ImageLoader::LoadImage(const std::string& imagePath, ImageType type)
{
	cv::Mat image = cv::imread(imagePath, static_cast<int>(type));
	if (image.empty())
	{
		throw std::runtime_error("Could not open or find the image: " + imagePath);
	}
	return image;
}
