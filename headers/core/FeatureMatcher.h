#pragma once
#ifndef FEATUREMATCHER_H
#define FEATUREMATCHER_H

#include<opencv2/opencv.hpp>
#include<vector>
#include"core/ImageFeatureData.h"

class FeatureMatcher
{
	public:
		static ImageFeatureData MatchFeatures(const cv::Mat& sourceImage, const cv::Mat& referenceImage);

};

#endif // !FEATUREMATCHER_H
