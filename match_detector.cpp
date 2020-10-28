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

    std::vector<cv::DMatch> good_matches;
    const float ratio_thresh = 0.5f;
    for (size_t i = 0; i < nn_matches.size(); i++)
    {
        if (nn_matches[i][0].distance < ratio_thresh * nn_matches[i][1].distance)
        {
            good_matches.push_back(nn_matches[i][0]);
        }
    }
}