#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

#include "read_data.cpp"
#include "match_detector.cpp"
#include "detector.cpp"

/**
 * 複数の画像に対してStar検出器を用いて位置検出を行う
 */

int main()
{
    // 画像の保存先ディレクトリ
    std::string folderPath = "./data";

    // 教師画像と特徴量
    std::string teacherImagePath = "./qrcode.png";
    cv::Mat teacherImage;
    std::vector<cv::KeyPoint> teacherDetectorKeypoint;
    cv::Mat teacherDescrptors;
    getFileImage(teacherImagePath, teacherImage);
    // StarAlgorithm(teacherImage, teacherDetectorKeypoint, teacherDescrptors);
    AkazeAlgorithm(teacherImage, teacherDetectorKeypoint, teacherDescrptors);

    // 画像を保存するならコメント外す
    // SaveImageWithDetector(teacherImage, &teacherDetectorKeypoint, "teacher.jpg");

    // 保存先ディレクトリから画像を全て取得する
    std::vector<std::string> fileNames;
    std::vector<cv::Mat> images;
    getFileNames(folderPath, fileNames);
    getFileImages(fileNames, images);

    std::vector<cv::KeyPoint> keypoint;
    cv::Mat descriptors;
    // StarAlgorithm(images[0], keypoint, descriptors);
    AkazeAlgorithm(images[0], keypoint, descriptors);
    // ShowDetectorPoint(images[0], &keypoint);

    // 教師画像の特徴量と比較する
    BFMatch(&teacherDescrptors, &descriptors);
}