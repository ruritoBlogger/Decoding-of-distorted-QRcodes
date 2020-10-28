#include <vector>
#include "read_data.cpp"

int main()
{
    std::string folderPath = "./data";
    std::vector<std::string> fileNames;
    getFileNames(folderPath, fileNames);
}