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
    std::string folderPath = "../data";

    // 教師画像と特徴量
    std::string teacherImagePath = "../qrcode.png";
    cv::Mat teacherImage;
    std::vector<cv::KeyPoint> teacherDetectorKeypoint;
    cv::Mat teacherDescrptors;
    getFileImage(teacherImagePath, teacherImage);
    // TODO: StarAlgorithmを動作するようにする
    // StarAlgorithm(teacherImage, teacherDetectorKeypoint, teacherDescrptors);
    AkazeAlgorithm(teacherImage, teacherDetectorKeypoint, teacherDescrptors);

    // 画像を保存するならコメント外す
    // SaveImageWithDetector(teacherImage, &teacherDetectorKeypoint, "teacher.jpg");

    // 保存先ディレクトリから画像を全て取得する
    std::vector<std::string> fileNames;
    std::vector<cv::Mat> images;
    getFileNames(folderPath, fileNames);
    getFileImages(fileNames, images);

    // 各画像に対して教師画像と比較し、位置検出を行う
    for( auto image : images)
    {
        std::vector<cv::KeyPoint> keypoint;
        cv::Mat descriptors;
        // TODO: StarAlgorithmでも動作するようにする
        // StarAlgorithm(images[0], keypoint, descriptors);
        AkazeAlgorithm(image, keypoint, descriptors);

        // 教師画像の特徴量と比較する
        std::vector<cv::DMatch> good_matches;
        BFMatch(&teacherDescrptors, &descriptors, good_matches);

        // HACK: 機能毎に関数切り分けをやる
        // NOTE: 以下はサンプルコードコピペのため内容を理解する必要あり
        // link https://jitaku.work/it/image-processing/opencv/featurematching/akaze/
        cv::Mat matches_image;
        cv::drawMatches(teacherImage, teacherDetectorKeypoint, image, keypoint, good_matches, matches_image, cv::Scalar::all(-1), cv::Scalar::all(-1), std::vector<char>(), cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

        // 一致した特徴量？から位置情報を抽出する...?
        // XXX: サンプルコピペだから何故動くのか不明
        std::vector<cv::Point2f> obj;
        std::vector<cv::Point2f> scene;
        std::cout << "good_matches.size()=" << good_matches.size() << std::endl;
        for (int i = 0; i < good_matches.size(); i++)
        {
            //-- Get the keypoints from the good matches
            obj.push_back(teacherDetectorKeypoint[good_matches[i].queryIdx].pt);
            scene.push_back(keypoint[good_matches[i].trainIdx].pt);
        }

        // 見つけた場所に四角を描く
        if (good_matches.size() > 2) {

            cv::Mat H = cv::findHomography(obj, scene, cv::RANSAC);

            if (!H.empty()) {
                //-- Get the corners from the image_1 ( the object to be "detected" )
                std::vector<cv::Point2f> obj_corners(4);
                obj_corners[0] = cv::Point2f(0.0, 0.0);
                obj_corners[1] = cv::Point2f((float)teacherImage.cols, 0.0);
                obj_corners[2] = cv::Point2f((float)teacherImage.cols, (float)teacherImage.rows);
                obj_corners[3] = cv::Point2f(0.0, (float)teacherImage.rows);

                // □で囲む
                std::vector<cv::Point2f> scene_corners(4);
                cv::perspectiveTransform(obj_corners, scene_corners, H);

                //-- Draw lines between the corners (the mapped object in the scene - image_2 )
                cv::line(matches_image, scene_corners[0] + cv::Point2f((float)teacherImage.cols, 0.0), scene_corners[1] + cv::Point2f((float)teacherImage.cols, 0.0), cv::Scalar(0, 255, 0), 4);
                cv::line(matches_image, scene_corners[1] + cv::Point2f((float)teacherImage.cols, 0.0), scene_corners[2] + cv::Point2f((float)teacherImage.cols, 0.0), cv::Scalar(0, 255, 0), 4);
                cv::line(matches_image, scene_corners[2] + cv::Point2f((float)teacherImage.cols, 0.0), scene_corners[3] + cv::Point2f((float)teacherImage.cols, 0.0), cv::Scalar(0, 255, 0), 4);
                cv::line(matches_image, scene_corners[3] + cv::Point2f((float)teacherImage.cols, 0.0), scene_corners[0] + cv::Point2f((float)teacherImage.cols, 0.0), cv::Scalar(0, 255, 0), 4);

                // cv::minAreaRectを使えばRotateRectを受け取ることができるのでそちらも検討
                cv::imshow("Good Matches & Object detection", matches_image);
                cv::waitKey(0);
            }
        }
    }
}