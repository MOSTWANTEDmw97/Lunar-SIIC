#pragma once
#ifndef TRANSFORMESTIMATOR_H
#define TRANSFORMESTIMATOR_H

#include<opencv2/opencv.hpp>
#include<vector>
#include"core/FeatureMatcher.h"

class TransformEstimator
{
	public:
		static cv::Mat EstimateTransform(const ImageFeatureData& featureData);
};


#endif // !TRANSFORMESTIMATOR_H
