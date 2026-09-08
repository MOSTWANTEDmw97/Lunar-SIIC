#include<opencv2/calib3d.hpp>
#include"core/TransformEstimator.h"

cv::Mat TransformEstimator::EstimateTransform(const ImageFeatureData& featureData)
{
	std::vector<cv::Point2f> sourcePoints, referencePoints;

	for (const auto& match : featureData.matches)
	{
		sourcePoints.push_back(featureData.sourceKeyPoints[match.queryIdx].pt);
		referencePoints.push_back(featureData.referenceKeyPoints[match.trainIdx].pt);
	}

	cv::Mat homographyMatrix = cv::findHomography(sourcePoints, referencePoints, cv::RANSAC);
	return homographyMatrix;
}

cv::Mat TransformEstimator::EstimateTransform(const ImageFeatureData& featureData, cv::Mat& mask)
{

	std::vector<cv::Point2f> sourcePoints, referencePoints;

	for (const auto& match : featureData.matches)
	{
		sourcePoints.push_back(featureData.sourceKeyPoints[match.queryIdx].pt);
		referencePoints.push_back(featureData.referenceKeyPoints[match.trainIdx].pt);
	}

	cv::Mat maskedHomographyMatrix = cv::findHomography(sourcePoints, referencePoints, cv::RANSAC, 3.0, mask);
	return maskedHomographyMatrix;
}