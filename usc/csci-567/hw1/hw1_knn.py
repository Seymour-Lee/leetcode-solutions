from __future__ import division, print_function

from typing import List

import numpy as np
import scipy

############################################################################
# DO NOT MODIFY ABOVE CODES
############################################################################

class KNN:

    def __init__(self, k: int, distance_function):
        self.k = k
        self.distance_function = distance_function

    #TODO: save features and lable to self
    def train(self, features: List[List[float]], labels: List[int]):
        # features: List[List[float]] a list of points
        # labels: List[int] labels of features
        self.xs = features
        self.ys = labels

    #TODO: predict labels of a list of points
    def predict(self, features: List[List[float]]) -> List[int]:
        # features: List[List[float]] a list of points
        # return: List[int] a list of predicted labels
        labels = []
        for p in features:
            k_neighbors = self.get_k_neighbors(p)
            zeros = k_neighbors.count(0)
            ones = k_neighbors.count(1)
            labels.append(0 if zeros > ones else 1)
        return labels

    #TODO: find KNN of one point
    def get_k_neighbors(self, point: List[float]) -> List[int]:
        # point: List[float] one example
        # return: List[int] labels of K nearest neighbor

        distances = []
        for i in range(len(self.xs)):
            dist = self.distance_function(self.xs[i], point)
            distances.append([dist, i, self.ys[i]])
        distances.sort(key = lambda x: (x[0], x[1]))
        ans = []
        for i in range(min(self.k, len(self.xs))):
            ans.append(distances[i][2])
        return ans

if __name__ == '__main__':
    print(np.__version__)
    print(scipy.__version__)
