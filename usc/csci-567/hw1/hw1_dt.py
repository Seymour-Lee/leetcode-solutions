import numpy as np
import utils as Util


class DecisionTree():
    def __init__(self):
        self.clf_name = "DecisionTree"
        self.root_node = None

    def train(self, features, labels):
        # features: List[List[float]], labels: List[int]
        # init
        assert (len(features) > 0)
        self.feature_dim = len(features[0])
        num_cls = np.unique(labels).size

        # build the tree
        self.root_node = TreeNode(features, labels, num_cls)
        if self.root_node.splittable:
            self.root_node.split()

        return

    def predict(self, features):
        # features: List[List[any]]
        # return List[int]
        y_pred = []
        for idx, feature in enumerate(features):
            pred = self.root_node.predict(feature)
            y_pred.append(pred)
            # print ("feature: ", feature)
            # print ("pred: ", pred)
        return y_pred


class TreeNode(object):
    def __init__(self, features, labels, num_cls):
        # features: List[List[any]], labels: List[int], num_cls: int
        self.features = features
        self.labels = labels
        self.children = []
        self.num_cls = num_cls
        # find the most common labels in current node
        count_max = 0
        for label in np.unique(labels):
            if self.labels.count(label) > count_max:
                count_max = labels.count(label)
                self.cls_max = label
                # splitable is false when all features belongs to one class
        if len(np.unique(labels)) < 2:
            self.splittable = False
        else:
            self.splittable = True

        self.dim_split = None  # the index of the feature to be split

        self.feature_uniq_split = None  # the possible unique values of the feature to be split

    #TODO: try to split current node
    def split(self):
        if self.features is None or len(self.features[0]) == 0:
            self.splittable = False
            return
        # print(self.features)
        # print(self.labels)
        from copy import deepcopy
        feature_copy = deepcopy(self.features)
        root_entropy = 0.0
        for label in np.unique(self.labels):
            if self.labels.count(label) == 0:
                continue
            root_entropy = root_entropy - float(self.labels.count(label)) / float(len(self.labels)) * np.log2(float(self.labels.count(label))/float(len(self.labels)))
        max_info_gain = -float('inf')
        max_attr_vals = 0
        best_dim = None
        dim_count = len(feature_copy[0])
        for dim in range(dim_count):
            val_to_labels = {}
            attr_vals_counter = 0
            for i in range(len(feature_copy)):
                if feature_copy[i][dim] in val_to_labels:
                    val_to_labels[feature_copy[i][dim]].append(self.labels[i])
                else:
                    val_to_labels[feature_copy[i][dim]] = [self.labels[i]]
                    attr_vals_counter = attr_vals_counter + 1
            branches = []
            for val, lbls in val_to_labels.items():
                branch = []
                for label in np.unique(self.labels):
                    branch.append(lbls.count(label))
                branches.append(branch)
            info_gain = Util.Information_Gain(root_entropy, branches)
            if info_gain == max_info_gain:
                print('info_gain == max_info_gain', info_gain)
            if info_gain > max_info_gain or (info_gain == max_info_gain and attr_vals_counter > max_attr_vals):
                max_info_gain = info_gain
                max_attr_vals = attr_vals_counter
                best_dim = dim
        
        # if best_dim is None:
        #     print(feature_copy)
        #     print(self.labels)

        self.dim_split = best_dim
        val_to_features = {}
        val_to_labels = {}
        for i in range(len(feature_copy)):
            if feature_copy[i][best_dim] in val_to_features:
                val_to_features[feature_copy[i][best_dim]].append(list(feature_copy[i]))
            else:
                val_to_features[feature_copy[i][best_dim]] = [list(feature_copy[i])]
            if feature_copy[i][best_dim] in val_to_labels:
                val_to_labels[feature_copy[i][best_dim]].append(self.labels[i])
            else:
                val_to_labels[feature_copy[i][best_dim]] = [self.labels[i]]
        for k in val_to_features:
            for i in range(len(val_to_features[k])):
                val_to_features[k][i].pop(best_dim)
        keys = list(val_to_features.keys())
        keys.sort()
        self.feature_uniq_split = []
        for k in keys:
            child_features = val_to_features[k]
            child_labels = val_to_labels[k]
            child_num_cls = np.unique(child_labels).size
            self.children.append(TreeNode(child_features, child_labels, child_num_cls))
            self.feature_uniq_split.append(k)

        for i in range(len(self.children)):
            if self.children[i].splittable:
                self.children[i].split()

    # TODO: predict the branch or the class
    def predict(self, feature):
        # feature: List[any]
        # return: int
        if (self.num_cls == 1) or (self.splittable is False) or (self.dim_split is None) or (len(self.features[0]) == 0):
            return self.cls_max
        if len(self.features) == 0:
            return self.cls_max
        
        dim_val = feature[self.dim_split]
        for i in range(len(self.feature_uniq_split)):
            if self.feature_uniq_split[i] == dim_val:
                from copy import deepcopy
                feature_copy = list(deepcopy(feature))
                feature_copy.pop(self.dim_split)
                ans = self.children[i].predict(feature_copy)
                if ans == -1:
                    return self.cls_max
                return ans
        return -1
