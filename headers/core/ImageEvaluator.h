#pragma once
#ifndef IMAGEEVALUATOR_H
#define IMAGEEVALUATOR_H

#include<opencv2/opencv.hpp>

class ImageEvaluator
{
public:
	static void EvaluateImage(const cv::Mat& referenceImage, cv::Mat& alignedImage);
};


#endif // !IMAGEEVALUATOR_H
