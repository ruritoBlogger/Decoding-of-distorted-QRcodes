from typing import List
import numpy as np

from read_data import read_data
from detector import star_algorithm, akaze_algorithm, show_detector_point

def main():
    path: str = '../data'
    images: List[np.ndarray] = read_data(path)
    # keypoint, descriptor = star_algorithm(images[0])
    keypoint = star_algorithm(images[0])
    show_detector_point(images[0], keypoint)
    # keypoint, descriptor = akaze_algorithm(images[0])



if __name__ == "__main__":
    main()