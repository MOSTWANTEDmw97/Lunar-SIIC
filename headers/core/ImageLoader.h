#pragma once
#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include<string>
#include<opencv2/opencv.hpp>

class ImageLoader
{
	public:
		cv::Mat LoadImage(const std::string& imagePath);
};

#endif // !IMAGELOADER_H
