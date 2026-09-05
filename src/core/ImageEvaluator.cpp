#include"core/ImageEvaluator.h"
#include<iostream>

void ImageEvaluator::EvaluateImage(const cv::Mat& referenceImage, cv::Mat& alignedImage)
{
	cv::Mat diff;
	cv::absdiff(referenceImage, alignedImage, diff);

	
	cv::Scalar meanSquaredError = cv::mean(diff.mul(diff));
	double rootMeanSquaredError = std::sqrt(meanSquaredError[0]);

	std::cout << "Root Mean Squared Error (RMSE): " << rootMeanSquaredError << std::endl;

	cv::imwrite("out_diff.png", diff);
}