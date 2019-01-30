from __future__ import division, print_function
import numpy as np
import bm_classify as sol

def accuracy_score(true, preds):
    return np.sum(true == preds).astype(float) / len(true)

def run_binary():
    from data_loader import toy_data_binary, \
                            moon_dataset, \
                            data_loader_mnist 

    datasets = [(toy_data_binary(), 'Synthetic data'), 
                (moon_dataset(), 'Two Moon data'),
                (data_loader_mnist(), 'Binarized MNIST data')]

    for data, name in datasets:
        print(name)
        X_train, X_test, y_train, y_test = data

        if name == 'Binarized MNIST data':
            y_train = [0 if yi < 5 else 1 for yi in y_train]
            y_test = [0 if yi < 5 else 1 for yi in y_test]
            y_train = np.asarray(y_train)
            y_test = np.asarray(y_test)

        for loss_type in ["perceptron", "logistic"]:
            w, b = sol.binary_train(X_train, y_train, loss=loss_type)
            train_preds = sol.binary_predict(X_train, w, b, loss=loss_type)
            preds = sol.binary_predict(X_test, w, b, loss=loss_type)
            print(loss_type + ' train acc: %f, test acc: %f' 
                %(accuracy_score(y_train, train_preds), accuracy_score(y_test, preds)))
        print()

def run_multiclass():
    from data_loader import smile_dataset_clear, \
                            smile_dataset_blur, \
                            data_loader_mnist 
    import time
    datasets = [(smile_dataset_clear(), 'Clear smile data', 3) 
                ,(smile_dataset_blur(), 'Blur smile data', 3)
                ,(data_loader_mnist(), 'MNIST', 10)]

    for data, name, num_classes in datasets:
        print('%s: %d class classification' % (name, num_classes))
        X_train, X_test, y_train, y_test = data
        for gd_type in ["sgd", "gd"]:
            s = time.time()
            w, b = sol.multiclass_train(X_train, y_train, C=num_classes, gd_type=gd_type)
            print(gd_type + ' training time: %0.6f seconds' %(time.time()-s))
            train_preds = sol.multiclass_predict(X_train, w=w, b=b)
            preds = sol.multiclass_predict(X_test, w=w, b=b)
            print('train acc: %f, test acc: %f' 
                % (accuracy_score(y_train, train_preds), accuracy_score(y_test, preds)))
        print()
        


if __name__ == '__main__':
    
    import argparse
    import sys

    parser = argparse.ArgumentParser()
    parser.add_argument("--type", )
    parser.add_argument("--output")
    args = parser.parse_args()

    if args.output:
        sys.stdout = open(args.output, 'w')

    if not args.type or args.type == 'binary':
        run_binary()

    if not args.type or args.type == 'multiclass':
        run_multiclass()
