#include"core/FeatureMatcher.h"
#include<algorithm>

FeatureMatcher::FeatureMatcher(int maxFeatures)
	: orbDetector(cv::ORB::create(maxFeatures)), 
	featureMatcher(cv::NORM_HAMMING, true) {}

ImageFeatureData FeatureMatcher::MatchFeatures(const cv::Mat& sourceImage, const cv::Mat& referenceImage)
{
	ImageFeatureData featureData;

	//Detect keypoints (Features) and compute descriptors
	orbDetector->detectAndCompute(sourceImage, cv::noArray(), featureData.sourceKeyPoints, featureData.sourceDescriptors);
	orbDetector->detectAndCompute(referenceImage, cv::noArray(), featureData.referenceKeyPoints, featureData.referenceDescriptors);

	//Match feature descriptors
	featureMatcher.match(featureData.sourceDescriptors, featureData.referenceDescriptors, featureData.matches);

	//Sort matches by distance (best matches first)
	std::sort(featureData.matches.begin(), featureData.matches.end(), [](const cv::DMatch& a, const cv::DMatch& b)
	{
		return a.distance < b.distance;
	});

	return featureData;
}