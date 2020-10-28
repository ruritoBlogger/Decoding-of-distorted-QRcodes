#include <iostream>
#include <vector>
#include <string>
#include "read_data.cpp"
#include <opencv2/opencv.hpp>

/**
 * 複数の画像に対してStar検出器を用いて位置検出を行う
 */

int main()
{
    // 画像の保存先ディレクトリ
    std::string folderPath = "./data";

    // 保存先ディレクトリから画像を全て取得する
    std::vector<std::string> fileNames;
    std::vector<cv::Mat*> images;
    getFileNames(folderPath, fileNames);
    getFileImages(fileNames, images);

    
}