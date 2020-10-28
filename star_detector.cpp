#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

/**
 * Star検出器を用いた特徴量抽出を行う
 */
void StarAlgorithm(cv::Mat *img)
{
    cv::Ptr<cv::StarDetector> detector = cv::StarDetector::create();
    std::vector<cv::KeyPoint> keypoint;
    detector->detect(*img, keypoint);
}