#include"core/FeatureMatcher.h"

ImageFeatureData FeatureMatcher::MatchFeatures(const cv::Mat& sourceImage, const cv::Mat& referenceImage)
{
	ImageFeatureData featureData;

	//ORB detector
	cv::Ptr<cv::ORB> orb = cv::ORB::create();

	//Detect keypoints (Features) and compute descriptors
	orb->detectAndCompute(sourceImage, cv::noArray(), featureData.sourceKeyPoints, featureData.sourceDescriptors);
	orb->detectAndCompute(referenceImage, cv::noArray(), featureData.referenceKeyPoints, featureData.referenceDescriptors);

	//Match feature descriptors
	cv::BFMatcher matcher(cv::NORM_HAMMING, true); //Cross-check, true
	matcher.match(featureData.sourceDescriptors, featureData.referenceDescriptors, featureData.matches);

	//Sort matches by distance (best matches first)
	std::sort(featureData.matches.begin(), featureData.matches.end(), [](const cv::DMatch& a, const cv::DMatch& b)
	{
		return a.distance < b.distance;
	});

	return featureData;
}