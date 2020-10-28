#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
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
        // std::cout << fileNames.back() << std::endl;
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
 * @param filePath: 読み込みたい画像のパス
 * @return 画像のポインタ or NULL
 */
bool getFileImage(std::string filePath, cv::Mat &img) {
    img = cv::imread(filePath);

    if( img.empty() )
    {
        std::cout << "{read_data.cpp}[img load] " << "cannot read img" << std::endl;
        return false;
    }
    return true;
}

/**
 * ファイル名の画像を読み込んでCV::Matとして返す
 * 複数の画像を取得出来る
 * @param filesPath: 読み込みたい画像のパスが格納されている配列
 * @param images: 読み込みたい画像を格納する
 * @return 読み込みに成功したかどうか
 */
// HACK: 画像のやり取り部分もう少し最適化出来るはず
bool getFileImages(std::vector<std::string> filesPath, std::vector<cv::Mat> &images) {
    for(auto filePath : filesPath )
    {
        cv::Mat image;
        // 画像の読み込みに失敗した際は処理を中断する
        if( getFileImage(filePath, image) ) images.push_back(image);
        else return false;
    }
    return true;
}
