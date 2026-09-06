#pragma once
#ifndef FEATUREMATCHER_H
#define FEATUREMATCHER_H

#include<opencv2/opencv.hpp>
#include<vector>
#include"core/ImageFeatureData.h"

class FeatureMatcher
{
	public:
		FeatureMatcher(int maxFeatures = 10000); //Set max features to 10000 by default 
		ImageFeatureData MatchFeatures(const cv::Mat& sourceImage, const cv::Mat& referenceImage);

private:
	cv::Ptr<cv::ORB> orbDetector;
	cv::BFMatcher featureMatcher;
};

#endif // !FEATUREMATCHER_H
