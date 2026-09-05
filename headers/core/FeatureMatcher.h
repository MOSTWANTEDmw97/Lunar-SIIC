#pragma once
#ifndef FEATUREMATCHER_H
#define FEATUREMATCHER_H

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

class FeatureMatcher
{
	public:
		ImageFeatureData MatchFeatures(const cv::Mat& sourceImage, const cv::Mat& referenceImage);

};

#endif // !FEATUREMATCHER_H
