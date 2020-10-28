import cv2
import os

def getFileNames(folderPath: str) -> [str]:
    """指定されたディレクトリの中に存在する画像名を全て取得する
    :param: folderPath 画像が保存されているパス
    :return: 複数の画像名をlistで返す
    """
    return os.listdir(folderPath)
