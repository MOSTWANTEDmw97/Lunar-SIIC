#include<opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include<Eigen/Dense>
#include <iostream>

//Lunar Scale & Illumination Invariant Correspondance (Lunar-SIIC)
int main()
{
    // Create a 2x2 matrix and a vector
    Eigen::Matrix2d mat;
    mat << 1, 2,
        3, 4;
    Eigen::Vector2d vec(5, 6);
    // Multiply
    Eigen::Vector2d result = mat * vec;

    std::cout << "Result:\n" << result << std::endl;

    cv::Mat test(2, 2, CV_8UC1, cv::Scalar(1));
    std::cout << "OpenCV headers found and linked!" << std::endl;
    return 0;
}