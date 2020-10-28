#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

/**
 * Star検出器を用いた特徴量抽出を行う
 * @param img 特徴量を抽出したい画像
 * @param keypoint 特徴量を保持する配列
 */
void StarAlgorithm(cv::Mat &img, std::vector<cv::KeyPoint> &keypoint)
{
    cv::Ptr<cv::xfeatures2d::StarDetector> detector = cv::xfeatures2d::StarDetector::create();
    detector->detect(img, keypoint);
}

/**
 * 
 */
void ShowDetectorPoint(cv::Mat img, std::vector<cv::KeyPoint> *keypoint)
{
    cv::drawKeypoints(img,
                      *keypoint,
                      img,
                      cv::Scalar::all(-1),
                      cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    cv::imshow("特徴量を描画した画像", img);
    cv::waitKey(0);
}