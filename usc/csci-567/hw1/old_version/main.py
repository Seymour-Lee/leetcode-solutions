import numpy as np
from hw1_knn import KNN
from utils import euclidean_distance, gaussian_kernel_distance, inner_product_distance, cosine_sim_distance
from utils import f1_score
from data import data_processing

distance_funcs = {
    'euclidean': euclidean_distance,
    'gaussian': gaussian_kernel_distance,
    'inner_prod': inner_product_distance,
    'cosine_dist': cosine_sim_distance,
}

from utils import NormalizationScaler, MinMaxScaler

scaling_classes = {
    'min_max_scale': MinMaxScaler,
    'normalize': NormalizationScaler,
}

if __name__ == "__main__":
    Xtrain, ytrain, Xval, yval, Xtest, ytest = data_processing()
    print(type(yval))
    best_k, best_model = KNN.model_selection_without_normalization(distance_funcs, Xtrain, ytrain, f1_score, Xval, yval, Xtest, ytest)
    print(best_k, best_model)
    best_k, best_model = KNN.model_selection_with_transformation(distance_funcs,scaling_classes, Xtrain, ytrain, f1_score, Xval, yval, Xtest, ytest)
    # KNN.test_classify(best_model)



