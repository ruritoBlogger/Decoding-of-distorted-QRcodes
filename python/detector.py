import cv2
from cv2 import xfeatures2d
import numpy as np
from typing import List

def star_algorithm(image: np.ndarray) -> np.ndarray:
    """Star検出器を用いた特徴量抽出を行う
    :param: image 抽出したい画像
    :return: 特徴量
    """

    star = xfeatures2d.StarDetector_create()
    return star.detect(image, None)
    # return star.detectAndCompute(image, None)

def akaze_algorithm(image: np.ndarray) -> any:
    """AKAZEを用いた特徴量抽出を行う
    :param: image 抽出したい画像
    :return: 特徴量, 特徴量ベクトル
    """

    akaze = cv2.AKAZE_create()
    return akaze.detectAndCompute(image, None)

def show_detector_point(image: np.ndarray, keypoint: List[any]) -> None:
    """特徴量をプロットする
    :param: image 特徴量を抽出した画像
    :param: keypoint 特徴量
    """
    cv2.drawKeypoints(image, keypoint, image)
    cv2.imshow("特徴量を描画した画像", image)
    cv2.waitKey(0)

def save_image_with_detector(image: np.ndarray, keypoint: List[any], fileName: str) -> None:
    """特徴量をプロットした画像を保存する
    :param: image 特徴量を抽出した画像
    :param: keypoint 特徴量
    :param: fileName 保存名
    """
    cv2.drawKeypoints(image, keypoint, image)
    cv2.imwrite(fileName, image)
