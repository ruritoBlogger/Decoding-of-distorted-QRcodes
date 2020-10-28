import cv2
import os
from typing import List
import numpy as np

def read_data(path: str) -> List[np.ndarray]:
    """pathに存在する画像を読み取り返す

    :param path 画像が保存されている相対パス:
    :return images 読み出した画像が格納されている配列:
    """

    images = []
    print("[{}] data path is {}".format(os.path.basename(__file__), path))

    for data in os.listdir(path):
        data = path + '/' + data
        images.append(cv2.imread(data))

    return images