#pragma once
#ifndef TRANSFORMESTIMATOR_H
#define TRANSFORMESTIMATOR_H

#include<opencv2/opencv.hpp>
#include<vector>
#include"core/FeatureMatcher.h"

class TransformEstimator
{
	public:
		cv::Mat EstimateTransform(const ImageFeatureData& featureData);
		cv::Mat EstimateTransform(const ImageFeatureData& featureData, cv::Mat& mask);
};


#endif // !TRANSFORMESTIMATOR_H
