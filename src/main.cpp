#include <iostream>

#include"core/ImageEvaluator.h"
#include"core/TransformEstimator.h"
#include"core/FeatureMatcher.h"
#include"core/ImageAligner.h"
#include"core/ImageLoader.h"

//Lunar Scale & Illumination Invariant Correspondance (Lunar-SIIC)
int main()
{
    //Init classes
    ImageLoader imageLoader;
    FeatureMatcher featureMatcher(5000);
    TransformEstimator transformEstimator;
    ImageAligner imageAligner;
    ImageEvaluator imageEvaluator;


    //In a try so it dosent accidentally shit itself
    try
    {
		//Load images
		cv::Mat sourceImage = imageLoader.LoadImage("Assets/Images/src.tif", GRAYSCALE);
		cv::Mat referenceImage = imageLoader.LoadImage("Assets/Images/reff.tif", GRAYSCALE);

        //Match features of the 2 images
		ImageFeatureData featureData = featureMatcher.MatchFeatures(sourceImage, referenceImage);
		cv::Mat homographyMatrix = transformEstimator.EstimateTransform(featureData);
		cv::Mat alignedImage = imageAligner.AlignImages(sourceImage, homographyMatrix, referenceImage.size());

		double rmse = imageEvaluator.CalculateRMSE(referenceImage, alignedImage);

		std::cout << "RMSE: " << rmse << std::endl;

        cv::imwrite("aligned.png", alignedImage);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}