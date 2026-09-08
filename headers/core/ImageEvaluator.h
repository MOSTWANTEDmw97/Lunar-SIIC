#pragma once
#ifndef IMAGEEVALUATOR_H
#define IMAGEEVALUATOR_H

#include<opencv2/opencv.hpp>

struct InlinerData
{
	int inliners;
	double inlinerRatio;
};

class ImageEvaluator
{
public:
	double CalculateRMSE(const cv::Mat& referenceImage, const cv::Mat& alignedImage);
	InlinerData CalculateInlinerData(const cv::Mat& mask);
	double CalculatePSNR(const cv::Mat& referenceImage, const cv::Mat& alignedImage);
	double CalculateSSIM(const cv::Mat& referenceImage, const cv::Mat& alignedImage);

};


#endif // !IMAGEEVALUATOR_H
