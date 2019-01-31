"""
Do not change the input and output format.
If our script cannot run your code or the format is improper, your code will not be graded.

The only functions you need to implement in this template is linear_regression_noreg, linear_regression_invertible，regularized_linear_regression,
tune_lambda, test_error and mapping_data.
"""

import numpy as np
import pandas as pd

###### Q1.1 ######
def mean_square_error(w, X, y):
    """
    Compute the mean squre error on test set given X, y, and model parameter w.
    Inputs:
    - X: A numpy array of shape (num_samples, D) containing test feature.
    - y: A numpy array of shape (num_samples, ) containing test label
    - w: a numpy array of shape (D, )
    Returns:
    - err: the mean square error
    """
    #####################################################
    # TODO 1: Fill in your code here #
    #####################################################
    # err = np.square(np.dot(X.T, w) - y).mean()
    err = np.mean(np.square(np.dot(X, w) - y))
    return err

###### Q1.2 ######
def linear_regression_noreg(X, y):
  """
  Compute the weight parameter given X and y.
  Inputs:
  - X: A numpy array of shape (num_samples, D) containing feature.
  - y: A numpy array of shape (num_samples, ) containing label
  Returns:
  - w: a numpy array of shape (D, )
  """
  #####################################################
  #	TODO 2: Fill in your code here #
  #####################################################		
  w = None
  w = np.linalg.solve(np.dot(X.T, X), np.dot(X.T, y))
  return w

###### Q1.3 ######
def linear_regression_invertible(X, y):
    """
    Compute the weight parameter given X and y.
    Inputs:
    - X: A numpy array of shape (num_samples, D) containing feature.
    - y: A numpy array of shape (num_samples, ) containing label
    Returns:
    - w: a numpy array of shape (D, )
    """
    #####################################################
    # TODO 3: Fill in your code here #
    #####################################################
    w = None
    i = 0
    while min(np.absolute(np.linalg.eigvals(np.add(np.dot(X.T, X), 1e-1*i*np.identity(X.shape[1]))))) < 1e-5:
      i = i+1
    w = np.dot(np.linalg.inv(np.add(np.dot(X.T, X), 1e-1*i*np.identity(X.shape[1]))), np.dot(X.T, y))
    return w


###### Q1.4 ######
def regularized_linear_regression(X, y, lambd):
    """
    Compute the weight parameter given X, y and lambda.
    Inputs:
    - X: A numpy array of shape (num_samples, D) containing feature.
    - y: A numpy array of shape (num_samples, ) containing label
    - lambd: a float number containing regularization strength
    Returns:
    - w: a numpy array of shape (D, )
    """
  #####################################################
  # TODO 4: Fill in your code here #
  #####################################################		
    inverse = np.linalg.inv(np.add(np.dot(X.T, X), lambd*np.identity(X.shape[1])))
    right = np.dot(X.T, y)
    w = np.dot(inverse, right)
    # w = np.linalg.solve(np.add(np.dot(X.T, X), lambd*np.identity(X.shape[1])), np.dot(X.T, y))
    return w

###### Q1.5 ######
def tune_lambda(Xtrain, ytrain, Xval, yval):
    """
    Find the best lambda value.
    Inputs:
    - Xtrain: A numpy array of shape (num_training_samples, D) containing training feature.
    - ytrain: A numpy array of shape (num_training_samples, ) containing training label
    - Xval: A numpy array of shape (num_val_samples, D) containing validation feature.
    - yval: A numpy array of shape (num_val_samples, ) containing validation label
    Returns:
    - bestlambda: the best lambda you find in lambds
    """
    #####################################################
    # TODO 5: Fill in your code here #
    #####################################################		
    bestlambda = None
    besterr = float('inf')
    lambd = 1e-19
    while lambd <= 1e19:
      w = regularized_linear_regression(Xtrain, ytrain, lambd)
      err = mean_square_error(w, Xval, yval)
      if err < besterr:
        print(lambd, err, besterr)
        bestlambda = lambd
        besterr = err
      lambd = lambd * 10
    return bestlambda
    

###### Q1.6 ######
def mapping_data(X, power):
    """
    Mapping the data.
    Inputs:
    - X: A numpy array of shape (num_training_samples, D) containing training feature.
    - power: A integer that indicate the power in polynomial regression
    Returns:
    - X: mapped_X, You can manully calculate the size of X based on the power and original size of X
    """
    #####################################################
    # TODO 6: Fill in your code here #
    #####################################################		
    ans = np.copy(X)
    for i in range(2, power+1):
      # ans = np.hstack((ans, np.power(X, i)))
      p = np.power(X, i)
      ans = np.insert(ans, len(ans[0]), p.T, axis=1)
    return ans


