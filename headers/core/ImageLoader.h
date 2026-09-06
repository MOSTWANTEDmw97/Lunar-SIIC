#pragma once
#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include<string>
#include<opencv2/opencv.hpp>

enum ImageType
{
	GRAYSCALE = cv::IMREAD_GRAYSCALE,
	COLOR = cv::IMREAD_COLOR
};

class ImageLoader
{
	public:
		cv::Mat LoadImage(const std::string& imagePath, ImageType type = GRAYSCALE);
};

#endif // !IMAGELOADER_H
