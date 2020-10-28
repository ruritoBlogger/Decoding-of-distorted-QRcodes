import cv2
import numpy as np
from typing import List

# TODO: any型を使うのをやめる
def bf_match(teacherDescriptors: np.ndarray, targetDescriptors: np.ndarray) -> List[any]:
    """BFMatchを用いた特徴量一致を行う
    :param: teacherDescriptors 教師画像の特徴量ベクトル
    :param: targetDescriptors 教師画像と比較したい画像の特徴量ベクトル
    :return: 一致した特徴量
    """
    # TODO: BFatcherやknnMatchのパラメータを確認する(手動で調整した方が結果がよくなる可能性があるため)
    matcher = cv2.BFMatcher()
    nn_matches = matcher.knnMatch(teacherDescriptors, targetDescriptors, k=2)
    ratio_thresh = 0.5
    good_matches = []

    for m, n in nn_matches:
        if m.distance < ratio_thresh * n.distance:
            good_matches.append([m])

    return good_matches