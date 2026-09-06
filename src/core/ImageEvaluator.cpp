#include"core/ImageEvaluator.h"
#include<iostream>

double ImageEvaluator::CalculateRMSE(const cv::Mat& referenceImage, const cv::Mat& alignedImage)
{
	cv::Mat diff;
	cv::absdiff(referenceImage, alignedImage, diff);

	cv::Scalar meanSquaredError = cv::mean(diff.mul(diff)); //MSE
	double rootMeanSquaredError = std::sqrt(meanSquaredError[0]); //RMSE

	return rootMeanSquaredError;
}