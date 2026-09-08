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

InlinerData ImageEvaluator::CalculateInlinerData(const cv::Mat& mask)
{
	InlinerData data;

	data.inliners = cv::countNonZero(mask);
	data.inlinerRatio = static_cast<double>(data.inliners) / mask.rows;

	return data;
}

double ImageEvaluator::CalculatePSNR(const cv::Mat& referenceImage, const cv::Mat& alignedImage)
{
	return cv::PSNR(referenceImage, alignedImage);
}

double ImageEvaluator::CalculateSSIM(const cv::Mat& referenceImage, const cv::Mat& alignedImage)
{
	//Convert to 32 bit matrix float 
	cv::Mat referenceScalar, alignedScalar;
	referenceImage.convertTo(referenceScalar, CV_32F);
	alignedImage.convertTo(alignedScalar, CV_32F);

	//Add gaussian blur to calc local coordinate mean value
	cv::Mat referenceMean, alignedMean;
	cv::GaussianBlur(referenceScalar, referenceMean, cv::Size(11, 11), 1.5);
	cv::GaussianBlur(alignedScalar, alignedMean, cv::Size(11, 11), 1.5);

	cv::Mat referenceMeanSquare = referenceMean.mul(referenceMean); //Reference * Reference
	cv::Mat alignedMeanSquare = alignedMean.mul(alignedMean); //Aligned * Aligned
	cv::Mat combinedMean = referenceMean.mul(alignedMean); //Reference * Aligned

	//Combines = Reference and Alligned
	cv::Mat referenceVariance, alignedVariance, combinedCovariance; 

	cv::GaussianBlur(referenceScalar.mul(referenceScalar), referenceVariance, cv::Size(11, 11), 1.5);
	referenceVariance -= referenceMeanSquare;

	cv::GaussianBlur(alignedScalar.mul(alignedScalar), alignedVariance, cv::Size(11, 11), 1.5);
	alignedVariance -= alignedMeanSquare;

	cv::GaussianBlur(referenceScalar.mul(alignedScalar), combinedCovariance, cv::Size(11, 11), 1.5);
	combinedCovariance -= combinedMean;

	//Constants to stabilize division
	const double C1 = 6.5025, C2 = 58.5225;

	//SSIM calculation
	cv::Mat numerator = (2 * combinedMean + C1).mul(2 * combinedCovariance + C2);
	cv::Mat denominator = (referenceMeanSquare + alignedMeanSquare + C1).mul(referenceVariance + alignedVariance + C2);

	cv::Mat ssimMap;
	cv::divide(numerator, denominator, ssimMap);

	return cv::mean(ssimMap)[0];
}