#include <vector>
#include "read_data.cpp"
#include <opencv2/opencv.hpp>

int main()
{
    std::string folderPath = "./data";
    std::vector<std::string> fileNames;
    getFileNames(folderPath, fileNames);

    cv::Mat img;
    getFileImage(fileNames[0], img);
}