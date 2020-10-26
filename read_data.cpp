#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

/**
 * ディレクトリ内に存在するファイル名を全て取得する
 * @param[in] folderPath: 捜索したいディレクトリ名
 * @param[out] fileNames: 捜索に成功した際に取得したファイル名
 * @return ファイル名の取得に成功したかどうか
 */
bool getFileNames(std::string folderPath, std::vector<std::string> &fileNames)
{
    using namespace std::filesystem;
    directory_iterator iter(folderPath), end;
    std::error_code err;

    for (; iter != end && !err; iter.increment(err)) {
        const directory_entry entry = *iter;

        fileNames.push_back( entry.path().string() );
        printf("%s\n", fileNames.back().c_str());
    }

    // エラー処理
    if (err)
    {
        std::cout << "{read_data.cpp}[file load] " <<  err.value() << std::endl;
        std::cout << "{read_data.cpp}[file load] " << err.message() << std::endl;
        return false;
    }
    return true;
}

/**
 * ファイル名の画像を読み込んでCV::Matとして返す
 * @param[in] filePath: 読み込みたい画像のパス
 * @param[out] img: 読み込みたい画像を格納する
 * @return 読み込みに成功したかどうか
 */
bool getFileImage(std::string filePath, cv::Mat &img) {
    img = cv::imread(filePath);

    if( img.empty() )
    {
        std::cout << "{read_data.cpp}[img load] " << "cannot read img" << std::endl;
         return false;
    }
    else return true;
}