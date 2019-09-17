/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(root == nullptr || target == nullptr) return {};
        vector<int> result;
        map<TreeNode *, TreeNode *> parents;
        getParents(root, parents);
        set<TreeNode *> visited;
        dfs(target, K, result, parents, visited);
        return result;
    }
    
private:
    void getParents(TreeNode *root, map<TreeNode *, TreeNode *> &p){
        if(root == nullptr) return;
        if(root->left){
            p[root->left] = root;
            getParents(root->left, p);
        }
        if(root->right){
            p[root->right] = root;
            getParents(root->right, p);
        }
    }
    
    void dfs(TreeNode *root, int k, vector<int> &ans,
             map<TreeNode *, TreeNode *> &p, set<TreeNode *> &v){
        if(root == nullptr) return;
        if(v.find(root) != v.end()) return;
        v.insert(root);
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        dfs(root->left, k-1, ans, p, v);
        dfs(root->right, k-1, ans, p, v);
        dfs(p[root], k-1, ans, p, v);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        dfs(root, nullptr);
        // for(auto n: a2b){
        //     cout<<n.first<<": ";
        //     for(auto nei: n.second) cout<<nei<<" ";
        //     cout<<endl;
        // }
        queue<int> q;
        q.push(target->val);
        unordered_set<int> v;
        while(K-- && q.empty() == false){
            int size = q.size();
            while(size--){
                int node = q.front(); q.pop();
                v.insert(node);
                for(auto nei: a2b[node]) if(v.find(nei) == v.end())q.push(nei);
            }
        }
        while(q.empty() == false) ans.push_back(q.front()), q.pop();
        return ans;
    }
    
private:
    unordered_map<int, unordered_set<int>> a2b;
    
    void dfs(TreeNode *root, TreeNode *parent){
        if(root == nullptr) return;
        if(parent){
            a2b[root->val].insert(parent->val);
            // a2b[parent->val].insert(root->val);
        }
        if(root->left){
            a2b[root->val].insert(root->left->val);
            dfs(root->left, root);
        }
        if(root->right){
            a2b[root->val].insert(root->right->val);
            dfs(root->right, root);
        }
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, nullptr);
        deque<int> q;
        q.push_back(target->val);
        unordered_set<int> v = {target->val};
        while(K-- && q.empty() == false){
            int size = q.size();
            while(size--){
                auto node = q.front(); q.pop_front();
                for(auto nei: g[node]) if(v.find(nei) == v.end()){
                    v.insert(nei);
                    q.push_back(nei);
                }
            }
        }
        return vector<int>(q.begin(), q.end());
    }
    
private:
    unordered_map<int, unordered_set<int>> g;
    
    void dfs(TreeNode *root, TreeNode *p){
        if(root == nullptr) return;
        if(p) g[root->val].insert(p->val);
        if(root->left) g[root->val].insert(root->left->val);
        if(root->right) g[root->val].insert(root->right->val);
        dfs(root->left, root);
        dfs(root->right, root);
    }
};