import cv2
from cv2 import xfeatures2d
import numpy as np

def star_algorithm( image: np.ndarray):
    """Star検出器を用いた特徴量抽出を行う
    :param: image 抽出したい画像
    :return: 特徴量
    """

    star = xfeatures2d.StarDetector_create()
    return star.detect(image, None)
    # return star.detectAndCompute(image, None)

def akaze_algorithm( image: np.ndarray):
    """AKAZEを用いた特徴量抽出を行う
    :param: image 抽出したい画像
    :return: 特徴量, 特徴量ベクトル
    """

    akaze = cv2.AKAZE_create()
    return akaze.detectAndCompute(image, None)
