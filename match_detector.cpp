#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/features2d.hpp>

/**
 * BFMatcherを用いた特徴量一致を行う
 * @param teacherKeypoint 教師画像の特徴量
 * @param targetKeypoint 一致させたい画像の特徴量
 */
void BFMatch(cv::Mat *teacherDescriptors, cv::Mat *targetDescriptors)
{
    cv::BFMatcher matcher(cv::NORM_HAMMING);
    std::vector<std::vector<cv::DMatch> > nn_matches;
    matcher.knnMatch(*teacherDescriptors, *targetDescriptors, nn_matches, 2);
}