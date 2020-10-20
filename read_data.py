import cv2
import os

def read_data(path: str):
    """/dataに存在する画像を読み取り返す

    :param path 画像が保存されている相対パス:
    :return img_ary 読み出した画像が格納されている配列:
    """

    img_ary = []
    print("[{}] data path is {}".format(os.path.basename(__file__), path))

    for data in os.listdir(path):
        data = path + '/' + data
        img_ary.append(cv2.imread(data))

    return img_ary