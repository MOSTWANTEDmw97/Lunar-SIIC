#include <iostream>

#include"core/ImageEvaluator.h"
#include"core/TransformEstimator.h"
#include"core/FeatureMatcher.h"
#include"core/ImageAligner.h"
#include"core/ImageLoader.h"

//Lunar Scale & Illumination Invariant Correspondance (Lunar-SIIC)
int main()
{
    //In a try so it dosent accidentally shit itself
    try
    {
        cv::Mat sourceImage = ImageLoader::LoadImage("Assets/Images/src.tif");
        cv::Mat referenceImage = ImageLoader::LoadImage("Assets/Images/reff.tif");

        ImageFeatureData features = FeatureMatcher::MatchFeatures(sourceImage, referenceImage);

        cv::Mat H = TransformEstimator::EstimateTransform(features);

        cv::Mat alignedImage = ImageAligner::AlignImages(sourceImage, H, referenceImage.size());

        ImageEvaluator::EvaluateImage(referenceImage, alignedImage);

        cv::imwrite("aligned.png", alignedImage);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}