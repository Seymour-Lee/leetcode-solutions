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

    #TODO: Complete the training function
    def train(self, features: List[List[float]], labels: List[int]):
        #raise NotImplementedError
        
    
    #TODO: Complete the prediction function
    def predict(self, features: List[List[float]]) -> List[int]:
        #raise NotImplementedError
        
    #TODO: Complete the get k nearest neighbor function
    def get_k_neighbors(self, point):
        #raise NotImplementedError
        
    #TODO: Complete the model selection function where you need to find the best k     
    def model_selection_without_normalization(distance_funcs, Xtrain, ytrain, f1_score, Xval, yval, Xtest, ytest):
        
            
            #Dont change any print statement
            print('[part 1.1] {name}\tk: {k:d}\t'.format(name=name, k=k) + 
                      'train: {train_f1_score:.5f}\t'.format(train_f1_score=train_f1_score) +
                      'valid: {valid_f1_score:.5f}'.format(valid_f1_score=valid_f1_score))
    
            print()
            print('[part 1.1] {name}\tbest_k: {best_k:d}\t'.format(name=name, best_k=best_k) +
                  'test f1 score: {test_f1_score:.5f}'.format(test_f1_score=test_f1_score))
            print()
            return best_k, model
    
    #TODO: Complete the model selection function where you need to find the best k with transformation
    def model_selection_with_transformation(distance_funcs,scaling_classes, Xtrain, ytrain, f1_score, Xval, yval, Xtest, ytest):
        
                #Dont change any print statement
                print('[part 1.2] {name}\t{scaling_name}\tk: {k:d}\t'.format(name=name, scaling_name=scaling_name, k=k) +
                          'train: {train_f1_score:.5f}\t'.format(train_f1_score=train_f1_score) + 
                          'valid: {valid_f1_score:.5f}'.format(valid_f1_score=valid_f1_score))
    
                print()
                print('[part 1.2] {name}\t{scaling_name}\t'.format(name=name, scaling_name=scaling_name) +
                      'best_k: {best_k:d}\ttest: {test_f1_score:.5f}'.format(best_k=best_k, test_f1_score=test_f1_score))
                print()
        
        
    #TODO: Do the classification 
    def test_classify(model):
        

if __name__ == '__main__':
    print(numpy.__version__)
    print(scipy.__version__)
