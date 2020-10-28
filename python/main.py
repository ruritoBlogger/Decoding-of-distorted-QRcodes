from typing import List
import numpy as np
import cv2

from read_data import read_data
from detector import star_algorithm, akaze_algorithm, show_detector_point
from match_detector import bf_match

def main():
    # 教師データ
    teacher_path: str = '../qrcode.png'
    teacher_image = cv2.imread(teacher_path)
    teacher_keypoint, teacher_descriptor = akaze_algorithm(teacher_image)

    # 位置検出したい画像を取得する
    path: str = '../data'
    images: List[np.ndarray] = read_data(path)

    # 画像から特徴量を抽出する
    # keypoint = star_algorithm(images[0])
    keypoint, descriptor = akaze_algorithm(images[0])
    # show_detector_point(images[0], keypoint)

    # 教師画像と比較して一致する特徴量を求める
    good_matches = bf_match(teacher_descriptor, descriptor)

    img = cv2.drawMatchesKnn(images[0], keypoint, teacher_image, teacher_keypoint, good_matches, None, flags=2)
    cv2.imshow("result", img)
    cv2.waitKey(0)



if __name__ == "__main__":
    main()