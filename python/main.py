from read_data import read_data
from typing import List
import numpy as np

def main():
    path: str = '../data'
    images: List[np.ndarray] = read_data(path)

if __name__ == "__main__":
    main()