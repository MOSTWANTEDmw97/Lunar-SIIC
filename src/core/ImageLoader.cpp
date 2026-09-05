#include"core/ImageLoader.h"

cv::Mat ImageLoader::LoadImage(const std::string& imagePath)
{
	cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
	if (image.empty())
	{
		throw std::runtime_error("Could not open or find the image: " + imagePath);
	}
	return image;
}
