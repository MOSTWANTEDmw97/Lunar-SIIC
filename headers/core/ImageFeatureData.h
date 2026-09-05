#pragma once
#ifndef IMAGEFEATUREDATA_H
#define IMAGEFEATUREDATA_H

#include<opencv2/opencv.hpp>
#include<vector>

struct ImageFeatureData
{
	std::vector<cv::KeyPoint> sourceKeyPoints;
	std::vector<cv::KeyPoint> referenceKeyPoints;
	cv::Mat sourceDescriptors;
	cv::Mat referenceDescriptors;
	std::vector<cv::DMatch> matches;
};

#endif // !IMAGEFEATUREDATA_H
