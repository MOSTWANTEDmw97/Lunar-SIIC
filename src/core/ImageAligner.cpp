#include"core/ImageAligner.h"

cv::Mat ImageAligner::AlignImages(const cv::Mat& sourceImage, const cv::Mat& H, cv::Size alignedImageSize)
{
    cv::Mat alignedImage;

    if (!H.empty() && (H.type() == CV_32F || H.type() == CV_64F))
    {
        cv::warpPerspective(sourceImage, alignedImage, H, alignedImageSize);
    }
    else
    {
        throw std::runtime_error("Invalid homography matrix passed to warpPerspective");
    }

    return alignedImage;
}