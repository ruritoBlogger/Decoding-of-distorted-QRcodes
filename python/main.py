from read_data import getFileNames

def main():
    folderPath: str = "../data"
    fileNames: [str] = getFileNames(folderPath)
    print(fileNames)

if __name__ == "__main__":
    main()