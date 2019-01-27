import numpy as np
from typing import List
from hw1_knn import KNN

# TODO: Information Gain function
def Information_Gain(S, branches):
    # S: float
    # branches: List[List[int]] num_branches * num_cls
    # return: float
    base = 0
    num_hsa = []
    for l in branches:
        num = sum(l)
        base = base + sum
        hsa = 0.0
        for e in l:
            hsa = hsa - float(e)/num * np.log2(float(e)/num)
        num_hsa.append([num, hsa])
    ans = 0.0
    for p in num_hsa:
        ans = ans - p[0]/base * p[1]
    return S - ans
    raise NotImplementedError


# TODO: implement reduced error prunning function, pruning your tree on this function
def reduced_error_prunning(decisionTree, X_test, y_test):
    # decisionTree
    # X_test: List[List[any]]
    # y_test: List
    raise NotImplementedError


# print current tree
def print_tree(decisionTree, node=None, name='branch 0', indent='', deep=0):
    if node is None:
        node = decisionTree.root_node
    print(name + '{')

    print(indent + '\tdeep: ' + str(deep))
    string = ''
    label_uniq = np.unique(node.labels).tolist()
    for label in label_uniq:
        string += str(node.labels.count(label)) + ' : '
    print(indent + '\tnum of samples for each class: ' + string[:-2])

    if node.splittable:
        print(indent + '\tsplit by dim {:d}'.format(node.dim_split))
        for idx_child, child in enumerate(node.children):
            print_tree(decisionTree, node=child, name='\t' + name + '->' + str(idx_child), indent=indent + '\t', deep=deep+1)
    else:
        print(indent + '\tclass:', node.cls_max)
    print(indent + '}')


#TODO: implement F1 score
def f1_score(real_labels: List[int], predicted_labels: List[int]) -> float:
    assert len(real_labels) == len(predicted_labels)
    tp = sum([x == 1.0 and y == 1.0 for x, y in zip(real_labels, predicted_labels)])# 0.0
    fn = sum([x == 1.0 and y == 0.0 for x, y in zip(real_labels, predicted_labels)])# 0.0
    fp = sum([x == 0.0 and y == 1.0 for x, y in zip(real_labels, predicted_labels)])# 0.0
    tn = sum([x == 0.0 and y == 0.0 for x, y in zip(real_labels, predicted_labels)])# 0.0
    precision = tp / (tp + fp + np.finfo(float).eps)
    recall = tp / (tp + fn + np.finfo(float).eps)
    return 2.0 * precision * recall / (precision + recall + np.finfo(float).eps)
    raise NotImplementedError

#TODO:
def euclidean_distance(point1: List[float], point2: List[float]) -> float:
    return np.sqrt(np.inner(np.subtract(point1, point2), np.subtract(point1, point2)))
    raise NotImplementedError


#TODO:
def inner_product_distance(point1: List[float], point2: List[float]) -> float:
    return np.inner(point1, point2)
    raise NotImplementedError


#TODO:
def gaussian_kernel_distance(point1: List[float], point2: List[float]) -> float:
    one_minus_two = np.subtract(point1, point2)
    return -np.exp(-(1/2)*np.inner(one_minus_two, one_minus_two))
    raise NotImplementedError


#TODO:
def cosine_sim_distance(point1: List[float], point2: List[float]) -> float:
    return 1 - np.dot(point1, point2)/(np.linalg.norm(point1)*(np.linalg.norm(point2)))
    raise NotImplementedError

tie_distance = {
    'euclidean': 0,
    'gaussian': 1,
    'inner_prod': 2,
    'cosine_dist': 3,
}

# TODO: select an instance of KNN with the best f1 score on validation dataset
def model_selection_without_normalization(distance_funcs, Xtrain, ytrain, Xval, yval):
    # distance_funcs: dictionary of distance funtion
    # Xtrain: List[List[int]] train set
    # ytrain: List[int] train labels
    # Xval: List[List[int]] validation set
    # yval: List[int] validation labels
    # return best_model: an instance of KNN
    # return best_k: best k choosed for best_model
    # return best_func: best function choosed for best_model
    best_model = None
    best_k = None
    best_func = None
    best_name = None
    best_f1 = -1.0
    
    for k in range(1, min(30, len(Xtrain)), 2):
        for name, func in distance_funcs.items():
            knn = KNN(k, func)
            knn.train(Xtrain, ytrain)
            ypre = knn.predict(Xval)
            f1 = f1_score(yval, ypre)
            if (f1 > best_f1 or
              (f1 == best_f1 and tie_distance[name] < tie_distance[best_name]) or 
              (f1 == best_f1 and tie_distance[name] == tie_distance[best_name] and k < best_k)):
                best_model = knn
                best_k = k
                best_func = func
                best_name = name
                best_f1 = f1
    print(best_model, best_k, best_func, best_f1)
    return best_model, best_k, best_name
    raise NotImplementedError

tie_scaler = {
    'min_max_scale': 0,
    'normalize': 1,
}

# TODO: select an instance of KNN with the best f1 score on validation dataset, with normalized data
def model_selection_with_transformation(distance_funcs, scaling_classes, Xtrain, ytrain, Xval, yval):
    # distance_funcs: dictionary of distance funtion
    # scaling_classes: diction of scalers
    # Xtrain: List[List[int]] train set
    # ytrain: List[int] train labels
    # Xval: List[List[int]] validation set
    # yval: List[int] validation labels
    # return best_model: an instance of KNN
    # return best_k: best k choosed for best_model
    # return best_func: best function choosed for best_model
    # return best_scaler: best function choosed for best_model
    best_model = None
    best_k = None
    best_func = None
    best_func_name = None
    best_scaler = None
    best_scaler_name = None
    best_f1 = -1.0

    for scaler_name, scaler_class in scaling_classes.items():
        Xtrain_scaled = list(Xtrain)
        scaler = scaler_class()
        Xtrain_scaled = scaler(Xtrain_scaled)
        Xval_scaled = list(Xval)
        Xval_scaled = scaler(Xval_scaled)
        for name, func in distance_funcs.items():
            for k in range(1, min(30, len(Xtrain)), 2):
                knn = KNN(k, func)
                knn.train(Xtrain_scaled, ytrain)
                ypre = knn.predict(Xval_scaled)
                f1 = f1_score(yval, ypre)
                if (f1 > best_f1 or 
                (f1 == best_f1 and tie_scaler[scaler_name] < tie_scaler[best_scaler_name]) or
                (f1 == best_f1 and tie_scaler[scaler_name] == tie_scaler[best_scaler_name] and tie_distance[name] < tie_distance[best_func_name]) or 
                (f1 == best_f1 and tie_scaler[scaler_name] == tie_scaler[best_scaler_name] and tie_distance[name] == tie_distance[best_func_name] and k < best_k)):
                    best_model = knn
                    best_k = k
                    best_func = func
                    best_func_name = name
                    best_scaler = scaler
                    best_scaler_name = scaler_name
                    best_f1 = f1
    print(best_model, best_k, best_func, best_scaler, best_f1)
    return best_model, best_k, best_func_name, best_scaler_name
    raise NotImplementedError


class NormalizationScaler:
    def __init__(self):
        pass

    #TODO: normalize data
    def __call__(self, features: List[List[float]]) -> List[List[float]]:
        """
        normalize the feature vector for each sample . For example,
        if the input features = [[3, 4], [1, -1], [0, 0]],
        the output should be [[0.6, 0.8], [0.707107, -0.707107], [0, 0]]
        """
        for i in range(len(features)):
            base = np.sqrt(np.inner(features[i], features[i]))
            for j in range(len(features[i])):
                features[i][j] = float(features[i][j]) / base if base != 0 else 0
        return features
        raise NotImplementedError


class MinMaxScaler:
    """
    You should keep some states inside the object.
    You can assume that the parameter of the first __call__
        must be the training set.

    Hints:
        1. Use a variable to check for first __call__ and only compute
            and store min/max in that case.

    Note:
        1. You may assume the parameters are valid when __call__
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
        self.mins = None
        self.maxs = None
        pass

    def __call__(self, features: List[List[float]]) -> List[List[float]]:
        """
        normalize the feature vector for each sample . For example,
        if the input features = [[2, -1], [-1, 5], [0, 0]],
        the output should be [[1, 0], [0, 1], [0.333333, 0.16667]]
        """
        if self.mins is None and self.maxs is None:
            self.mins = [float('inf')] * len(features[0])
            self.maxs = [-float('inf')] * len(features[0])
            for f in features:
                for i in range(len(f)):
                    self.mins[i] = min(self.mins[i], f[i])
                    self.maxs[i] = max(self.maxs[i], f[i])
        for f in features:
            for i in range(len(f)):
                f[i] = (f[i] - self.mins[i]) / (self.maxs[i] - self.mins[i]) if self.maxs[i] != self.mins[i] else 0
        return features
        raise NotImplementedError





