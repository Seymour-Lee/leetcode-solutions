import numpy as np
import matplotlib.pyplot as plt
from typing import List

#TODO: Information Gain function
def Information_Gain(S, branches):
    # S: float
    # branches: List[List[any]]
    # return: float
    pass


# TODO: implement reduced error pruning
def reduced_error_pruning(decisionTree, X_test, y_test):
    # decisionTree
    # X_test: List[List[any]]
    # y_test: List[any]
    pass


# print current tree
# Do not change this function
def print_tree(decisionTree, node=None, name='branch 0', indent='', deep=0):
    if node is None:
        node = decisionTree.root_node
    print(name + '{')

    print(indent + '\tdeep: ' + str(deep))
    string = ''
    for idx_cls in range(node.num_cls):
        string += str(node.labels.count(idx_cls)) + ' : '
    print(indent + '\tnum of samples for each class: ' + string[:-2])

    if node.splittable:
        print(indent + '\tsplit by dim {:d}'.format(node.dim_split))
        for idx_child, child in enumerate(node.children):
            print_tree(decisionTree, node=child, name='\t' + name + '->' + str(idx_child), indent=indent + '\t', deep=deep+1)
    else:
        print(indent + '\tclass:', node.cls_max)
    print(indent + '}')


#KNN Utils

#TODO: implement F1 score
def f1_score(real_labels, predicted_labels) -> float:
    """
    f1 score: https://en.wikipedia.org/wiki/F1_score
    """
    assert len(real_labels) == len(predicted_labels)
    # print(len(real_labels), len(predicted_labels))
    tp = sum([x == 1.0 and y == 1.0 for x, y in zip(real_labels, predicted_labels)])# 0.0
    fn = sum([x == 1.0 and y == 0.0 for x, y in zip(real_labels, predicted_labels)])# 0.0
    fp = sum([x == 0.0 and y == 1.0 for x, y in zip(real_labels, predicted_labels)])# 0.0
    tn = sum([x == 0.0 and y == 0.0 for x, y in zip(real_labels, predicted_labels)])# 0.0
    # for i in range(len(real_labels)):
    #     print(int(real_labels[i]), int(np.float64(predicted_labels[i])))
    #     if int(real_labels[i]) is int(np.float64(predicted_labels[i])):
    #         print(int(real_labels[i]) == 1, '-----------------')
    #         if int(real_labels[i]) is 1:
    #             tp += 1.0
    #         else:
    #             tn += 1.0
    #     else:
    #         if int(real_labels[i]) is 1:
    #             fn += 1.0
    #         else:
    #             fp += 1.0
    # print(tp, fn, fp, tn)
    precision = tp / (tp + fp + np.finfo(float).eps)
    recall = tp / (tp + fn + np.finfo(float).eps)
    # print(precision, recall)
    return 2.0 * precision * recall / (precision + recall + np.finfo(float).eps)
    # raise NotImplementedError
    
#TODO: Euclidean distance, inner product distance, gaussian kernel distance and cosine similarity distance

def euclidean_distance(point1: List[float], point2: List[float]) -> float:
    return np.sqrt(np.inner(np.subtract(point1, point2), np.subtract(point1, point2)))
    # raise NotImplementedError

def inner_product_distance(point1: List[float], point2: List[float]) -> float:
    return np.inner(point1, point2)
    # raise NotImplementedError

def gaussian_kernel_distance(point1: List[float], point2: List[float]) -> float:
    one_minus_two = np.subtract(point1, point2)
    return -np.exp(-(1/2)*np.inner(one_minus_two, one_minus_two))
    # raise NotImplementedError

def cosine_sim_distance(point1: List[float], point2: List[float]) -> float:
    return np.dot(point1, point2)/(np.linalg.norm(point1)*(np.linalg.norm(point2)))
    # raise NotImplementedError
    
class NormalizationScaler:
    def __init__(self):
        pass

    def __call__(self, features: List[List[float]]) -> List[List[float]]:
        """
        normalize the feature vector for each sample . For example,
        if the input features = [[3, 4], [1, -1], [0, 0]],
        the output should be [[0.6, 0.8], [0.707107, -0.707107], [0, 0]]
        """
        inners = []
        for f in features:
            inners.append(np.sqrt(np.inner(f, f)))
        return np.divide(features, f)


class MinMaxScaler:
    """
    You should keep some states inside the object.
    You can assume that the parameter of the first __call__
        must be the training set.
    Note:
        1. you may assume the parameters are valid when __call__
            is being called the first time (you can find min and max).
    Example:
        train_features = [[0, 10], [2, 0]]
        test_features = [[20, 1]]
        scaler = MinMaxScale()
        train_features_scaled = scaler(train_features)
        # now train_features_scaled should be [[0, 1], [1, 0]]
        test_features_sacled = scaler(test_features)
        # now test_features_scaled should be [[10, 0.1]]
        new_scaler = MinMaxScale() # creating a new scaler
        _ = new_scaler([[1, 1], [0, 0]]) # new trainfeatures
        test_features_scaled = new_scaler(test_features)
        # now test_features_scaled should be [[20, 1]]
    """

    def __init__(self):
        pass

    def __call__(self, features: List[List[float]]) -> List[List[float]]:
        """
        normalize the feature vector for each sample . For example,
        if the input features = [[2, -1], [-1, 5], [0, 0]],
        the output should be [[1, 0], [0, 1], [0.333333, 0.16667]]
        """
        raise NotImplementedError
