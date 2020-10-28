#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

/**
 * Star検出器を用いた特徴量抽出を行う
 * @param img 特徴量を抽出したい画像
 * @param keypoint 特徴量を保持する配列
 * @param descriptors 計算後のdescriptors?
 */
// WARNING: descriptorsがよくわからない. 要調査
void StarAlgorithm(cv::Mat &img, std::vector<cv::KeyPoint> &keypoint, cv::Mat &descriptors)
{
    cv::Ptr<cv::xfeatures2d::StarDetector> detector = cv::xfeatures2d::StarDetector::create();
    detector->detect(img, keypoint);
    // detector->compute(img, keypoint, descriptors);
    // detector->detectAndCompute(img, cv::noArray(), keypoint, descriptors);
}

/**
 * 引数の特徴量を画像に描画して表示する
 * @param img 描画先の画像(画像に書き込む為値渡し)
 * @param keypoint 描画したい特徴量
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

/**
 * 引数の特徴量を画像に描画して保存する
 * @param img 描画先の画像(画像に書き込む為値渡し)
 * @param keypoint 描画したい特徴量
 * @param fileName 保存名
 */
void SaveImageWithDetector(cv::Mat img,
                           std::vector<cv::KeyPoint> *keypoint,
                           std::string fileName)
{
    cv::drawKeypoints(img,
                      *keypoint,
                      img,
                      cv::Scalar::all(-1),
                      cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    cv::imwrite(fileName, img);
}
