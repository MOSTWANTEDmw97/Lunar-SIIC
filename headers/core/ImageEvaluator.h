#pragma once
#ifndef IMAGEEVALUATOR_H
#define IMAGEEVALUATOR_H

#include<opencv2/opencv.hpp>

class ImageEvaluator
{
public:
	double CalculateRMSE(const cv::Mat& referenceImage, const cv::Mat& alignedImage);

};


#endif // !IMAGEEVALUATOR_H
