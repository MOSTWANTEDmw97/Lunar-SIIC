#include"core/ImageAligner.h"


cv::Mat ImageAligner::AlignImages(const cv::Mat& sourceImage, const cv::Mat& referenceImage, cv::Size alignedImageSize)
{
	cv::Mat alignedImage;

	cv::warpPerspective(sourceImage, alignedImage, referenceImage, alignedImageSize);

	return alignedImage;
}