from __future__ import division, print_function

from typing import List, Callable

import numpy as np
import scipy
from collections import Counter


############################################################################
# DO NOT MODIFY ABOVE CODES
############################################################################

class KNN:

    def __init__(self, k: int, distance_function):
        self.k = k
        self.distance_function = distance_function
        self.xs = None
        self.ys = None
        self.scaler = None

    #TODO: Complete the training function
    def train(self, features: List[List[float]], labels: List[int]):
        assert len(features) == len(labels)
        self.xs = features
        self.ys = labels
        #raise NotImplementedError
        
    
    #TODO: Complete the prediction function
    def predict(self, features: List[List[float]]) -> List[int]:
        labels = []
        for p in features:
            # calculate distance
            distances = []
            for i in range(len(self.xs)):
                dist = self.distance_function(self.xs[i], p)
                distances.append([dist, self.ys[i]])
            k_neighbors = self.get_k_neighbors(distances)
            # print(k_neighbors)
            zeros = 0
            ones = 0
            for nei in k_neighbors:
                if int(nei) is 0:
                    zeros += 1
                else:
                    ones += 1
            if zeros > ones:
                labels.append(0)
            else:
                labels.append(1)
        return labels
        #raise NotImplementedError
        
    #TODO: Complete the get k nearest neighbor function
    def get_k_neighbors(self, points):
        # points: list(pair<distance, label>)
        points.sort(key = lambda x: x[0])
        ans = []
        for i in range(self.k):
            ans.append(points[i][1])
        return ans
        #raise NotImplementedError
        
    #TODO: Complete the model selection function where you need to find the best k     
    def model_selection_without_normalization(distance_funcs, Xtrain, ytrain, f1_score, Xval, yval, Xtest, ytest):
        model = KNN(None, None)
        model.train(Xtrain, ytrain)

        train_f1_score = f1_score(ytrain, ytrain)
        valid_f1_score = 0
        best_k = 0
        best_distance_func = None
        best_distance_func_name = None

        # find k and dis_func
        for i in range(int(len(model.xs)/2)):
            k = i * 2 + 1
            model.k = k
            for name, func in distance_funcs.items():
                model.distance_function = func
                # valid set
                v_labels = model.predict(Xval)
                cur_f1_score = f1_score(yval, v_labels)
                if cur_f1_score > valid_f1_score:
                    best_k = k
                    best_distance_func = func
                    best_distance_func_name = name
                    valid_f1_score = cur_f1_score
                #Dont change any print statement
                print('[part 1.1] {name}\tk: {k:d}\t'.format(name=name, k=k) + 
                        'train: {train_f1_score:.5f}\t'.format(train_f1_score=train_f1_score) +
                        'valid: {valid_f1_score:.5f}'.format(valid_f1_score=valid_f1_score))
        model.k = best_k
        model.distance_function = best_distance_func
        model.xs = np.append(model.xs, Xval, axis=0)
        model.ys = np.append(model.ys, yval, axis=0)
        t_labels = model.predict(Xtest)
        test_f1_score = f1_score(ytest, t_labels)
        print()
        print('[part 1.1] {name}\tbest_k: {best_k:d}\t'.format(name=best_distance_func_name, best_k=best_k) +
              'test f1 score: {test_f1_score:.5f}'.format(test_f1_score=test_f1_score))
        print()
        return best_k, model
    
    #TODO: Complete the model selection function where you need to find the best k with transformation
    def model_selection_with_transformation(distance_funcs,scaling_classes, Xtrain, ytrain, f1_score, Xval, yval, Xtest, ytest):
        model = KNN(None, None)
        model.train(Xtrain, ytrain)

        train_f1_score = f1_score(ytrain, ytrain)
        valid_f1_score = 0
        best_k = 0
        best_distance_func = None
        best_distance_func_name = None
        best_scaler = None
        best_scaler_name = None

        # find k and dis_func
        for i in range(int(len(model.xs)/2)):
            k = i * 2 + 1
            model.k = k
            for name, func in distance_funcs.items():
                model.distance_function = func
                for scaling_name, scaler in scaling_classes.items():
                    # valid set
                    scaled = scaler(Xval)
                    v_labels = model.predict(scaled)
                    cur_f1_score = f1_score(yval, v_labels)
                    if cur_f1_score > valid_f1_score:
                        best_k = k
                        best_distance_func = func
                        best_distance_func_name = name
                        best_scaler = scaler
                        best_scaler_name - scaling_name
                        valid_f1_score = cur_f1_score
                    #Dont change any print statement
                    print('[part 1.2] {name}\t{scaling_name}\tk: {k:d}\t'.format(name=name, scaling_name=scaling_name, k=k) +
                            'train: {train_f1_score:.5f}\t'.format(train_f1_score=train_f1_score) + 
                            'valid: {valid_f1_score:.5f}'.format(valid_f1_score=valid_f1_score))
        model.k = best_k
        model.distance_function = best_distance_func
        mode.scaler = best_scaler
        model.xs = np.append(model.xs, Xval, axis=0)
        model.ys = np.append(model.ys, yval, axis=0)
        scaled = model.scaler(Xtest)
        t_labels = model.predict(scaled)
        test_f1_score = f1_score(ytest, t_labels)
        print()
        print('[part 1.2] {name}\t{scaling_name}\t'.format(name=best_distance_func_name, scaling_name=best_scaler_name) +
              'best_k: {best_k:d}\ttest: {test_f1_score:.5f}'.format(best_k=best_k, test_f1_score=test_f1_score))
        print()
        return best_k, model

    
                # print()
                # print('[part 1.2] {name}\t{scaling_name}\t'.format(name=name, scaling_name=scaling_name) +
                #       'best_k: {best_k:d}\ttest: {test_f1_score:.5f}'.format(best_k=best_k, test_f1_score=test_f1_score))
                # print()
        
        
    #TODO: Do the classification 
    def test_classify(model):
        from data import test_processing
        x_test = test_processing()
        model.predict(x_test)
        

if __name__ == '__main__':
    print(numpy.__version__)
    print(scipy.__version__)
