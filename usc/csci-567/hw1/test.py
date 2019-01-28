# import numpy as np
# from hw1_knn import KNN
# from utils import euclidean_distance, gaussian_kernel_distance, inner_product_distance, cosine_sim_distance
# from utils import f1_score, model_selection_without_normalization, model_selection_with_transformation
# distance_funcs = {
#     'euclidean': euclidean_distance,
#     'gaussian': gaussian_kernel_distance,
#     'inner_prod': inner_product_distance,
#     'cosine_dist': cosine_sim_distance,
# }


# from data import data_processing
# Xtrain, ytrain, Xval, yval, Xtest, ytest = data_processing()


# best_model, best_k, best_function = model_selection_without_normalization(distance_funcs, Xtrain, ytrain, Xval, yval)

from utils import Information_Gain

ans = Information_Gain(0.97, [[2, 5], [10, 3]])
print(ans)