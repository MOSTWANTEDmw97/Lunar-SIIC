#include"core/ImageAligner.h"

cv::Mat ImageAligner::AlignImages(const cv::Mat& sourceImage, const cv::Mat& homographyMatrix, cv::Size alignedImageSize)
{
    cv::Mat alignedImage;

    if (!homographyMatrix.empty() && (homographyMatrix.type() == CV_32F || homographyMatrix.type() == CV_64F))
    {
        cv::warpPerspective(sourceImage, alignedImage, homographyMatrix, alignedImageSize);
    }
    else
    {
        throw std::runtime_error("Invalid homography matrix");
    }

    return alignedImage;
}