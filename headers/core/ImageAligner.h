#pragma once
#ifndef IMAGEALIGNER_H
#define IMAGEALIGNER_H

#include<opencv2/opencv.hpp>

class ImageAligner
{
	public:
		cv::Mat AlignImages(const cv::Mat& sourceImage, const cv::Mat& referenceImage, cv::Size alignedImageSize);
};

#endif // !IMAGEALIGNER_H
