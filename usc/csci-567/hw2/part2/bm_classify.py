import numpy as np


def binary_train(X, y, loss="perceptron", w0=None, b0=None, step_size=0.5, max_iterations=1000):
    """
    Inputs:
    - X: training features, a N-by-D numpy array, where N is the 
    number of training points and D is the dimensionality of features
    - y: binary training labels, a N dimensional numpy array where 
    N is the number of training points, indicating the labels of 
    training data
    - loss: loss type, either perceptron or logistic
    - step_size: step size (learning rate)
	- max_iterations: number of iterations to perform gradient descent

    Returns:
    - w: D-dimensional vector, a numpy array which is the weight 
    vector of logistic or perceptron regression
    - b: scalar, which is the bias of logistic or perceptron regression
    """
    N, D = X.shape
    assert len(np.unique(y)) == 2


    w = np.zeros(D)
    if w0 is not None:
        w = w0
    
    b = 0
    if b0 is not None:
        b = b0

    if loss == "perceptron":
        ############################################
        # TODO 1 : Edit this if part               #
        #          Compute w and b here            #
        w = np.zeros(D)
        b = 0

        y = 2 * y - 1
        
        for epoch in range(max_iterations):
            preds = w.dot(X.T) + b
            diff = np.multiply(preds, y) <= 0
            sign = [-int(i) for i in diff]
            error = np.multiply(sign, y)
            w -= step_size*np.dot(error, X)/N
            b -= step_size*np.dot(sign, y)/N
        ############################################
        

    elif loss == "logistic":
        ############################################
        # TODO 2 : Edit this if part               #
        #          Compute w and b here            #
        w = np.zeros(D)
        b = 0

        for i in range(max_iterations):
            error = sigmoid(w.dot(X.T) + b) - y
            w -= step_size * error.dot(X) / N
            b -= step_size * np.sum(error) / N
        ############################################
        

    else:
        raise "Loss Function is undefined."

    assert w.shape == (D,)
    return w, b

def sigmoid(z):
    
    """
    Inputs:
    - z: a numpy array or a float number
    
    Returns:
    - value: a numpy array or a float number after computing sigmoid function value = 1/(1+exp(-z)).
    """

    ############################################
    # TODO 3 : Edit this part to               #
    #          Compute value                   #
    value = z
    value = 1.0 / (1.0 + np.exp(-z))
    ############################################
    return value

def binary_predict(X, w, b, loss="perceptron"):
    """
    Inputs:
    - X: testing features, a N-by-D numpy array, where N is the 
    number of training points and D is the dimensionality of features
    - w: D-dimensional vector, a numpy array which is the weight 
    vector of your learned model
    - b: scalar, which is the bias of your model
    - loss: loss type, either perceptron or logistic
    
    Returns:
    - preds: N dimensional vector of binary predictions: {0, 1}
    """
    N, D = X.shape
    
    if loss == "perceptron":
        ############################################
        # TODO 4 : Edit this if part               #
        #          Compute preds                   #
        preds = np.zeros(N)
        preds = w.dot(X.T) + b
        preds = np.array([1.0 if i >= 0.0 else 0.0 for i in preds])
        ############################################
        

    elif loss == "logistic":
        ############################################
        # TODO 5 : Edit this if part               #
        #          Compute preds                   #
        preds = np.zeros(N)
        preds = sigmoid(w.dot(X.T) + b)
        preds = np.array([1 if i >= 0.5 else 0 for i in preds])
        ############################################
        

    else:
        raise "Loss Function is undefined."
    

    assert preds.shape == (N,) 
    return preds



def multiclass_train(X, y, C,
                     w0=None, 
                     b0=None,
                     gd_type="sgd",
                     step_size=0.5, 
                     max_iterations=1000):
    """
    Inputs:
    - X: training features, a N-by-D numpy array, where N is the 
    number of training points and D is the dimensionality of features
    - y: multiclass training labels, a N dimensional numpy array where
    N is the number of training points, indicating the labels of 
    training data
    - C: number of classes in the data
    - gd_type: gradient descent type, either GD or SGD
    - step_size: step size (learning rate)
    - max_iterations: number of iterations to perform gradient descent

    Returns:
    - w: C-by-D weight matrix of multinomial logistic regression, where 
    C is the number of classes and D is the dimensionality of features.
    - b: bias vector of length C, where C is the number of classes
    """

    N, D = X.shape

    w = np.zeros((C, D))
    if w0 is not None:
        w = w0
    
    b = np.zeros(C)
    if b0 is not None:
        b = b0

    np.random.seed(42)

    def softmax_gd(x):
        x = np.exp(x - np.amax(x))
        denom = np.sum(x, axis=1)
        return (x.T / denom).T

    def softmax_sgd(x):
        x = np.exp(x - np.max(x))
        demon = np.sum(x, axis=0)
        return x / demon
    
    if gd_type == "sgd":
        ############################################
        # TODO 6 : Edit this if part               #
        #          Compute w and b                 #
        w = np.zeros((C, D))
        b = np.zeros(C)
        # y = np.eye(C)[y]
        for epoch in range(max_iterations):
            i = np.random.choice(len(X))
            xi = X[i]
            yi = np.zeros(C)
            yi[y[i]] = 1
            error = softmax_sgd((w.dot(xi.T)).T + b) - yi
            w -= step_size * np.outer(error, xi)
            b -= step_size * error
        ############################################
        

    elif gd_type == "gd":
        ############################################
        # TODO 7 : Edit this if part               #
        #          Compute w and b                 #
        w = np.zeros((C, D))
        b = np.zeros(C)
        y = np.eye(C)[y]
        for epoch in range(max_iterations):
            error = softmax_gd((w.dot(X.T)).T + b) - y
            w -= step_size * error.T.dot(X) / N
            b -= step_size * np.sum(error, axis=0) / N
        ############################################
        

    else:
        raise "Type of Gradient Descent is undefined."
    

    assert w.shape == (C, D)
    assert b.shape == (C,)

    return w, b


def multiclass_predict(X, w, b):
    """
    Inputs:
    - X: testing features, a N-by-D numpy array, where N is the 
    number of training points and D is the dimensionality of features
    - w: weights of the trained multinomial classifier, C-by-D 
    - b: bias terms of the trained multinomial classifier, length of C
    
    Returns:
    - preds: N dimensional vector of multiclass predictions.
    Outputted predictions should be from {0, C - 1}, where
    C is the number of classes
    """
    N, D = X.shape
    ############################################
    # TODO 8 : Edit this part to               #
    #          Compute preds                   #
    preds = np.zeros(N)
    def softmax(x):
        x = np.exp(x - np.amax(x))
        denom = np.sum(x, axis=1)
        return (x.T / denom).T
    
    preds = softmax((w.dot(X.T)).T + b)
    preds = np.argmax(preds, axis=1)
    ############################################

    assert preds.shape == (N,)
    return preds




        