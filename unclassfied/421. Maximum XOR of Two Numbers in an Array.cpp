class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        TrieNode *root = buildTrieTree(nums);
        TrieNode * node = root;
        for(auto num: nums){
            int cur = 0;
            for(int i = 31; i >= 0; i--){
                int bit = num & (1 << i);
                if(node->left && node->right){
                    node = bit == 0? node->left: node->right;
                }
                else{
                    node = node->left == nullptr? node->right: node->left;
                }
                cur += bit ^ (node->val << i);
            }
            node = root;
            result = max(result, cur);
        }
        return result;
    }
    
private:
    struct TrieNode{
        int val;
        TrieNode *left;
        TrieNode *right;
        TrieNode(int x) : val(x), left(nullptr), right(nullptr){}
    };
    
    TrieNode *buildTrieTree(vector<int> nums){
        TrieNode *root = new TrieNode(0);
        TrieNode *cur = root;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 31; j >=0; j--){
                int bit = nums[i] & (1 << j);
                if(bit == 0){
                    if(cur->right == nullptr){
                        cur->right = new TrieNode(0);
                    }
                    cur = cur->right;
                }
                else{
                    if(cur->left == nullptr){
                        cur->left = new TrieNode(1);
                    }
                    cur = cur->left;
                }
            }
            cur = root;
        }
        return root;
    }
};

class Trie{
public:
    Trie(){
        children = vector<Trie *>(2, nullptr);
    }
    
    void insert(int num){
        Trie *node = this;
        for(int pos = 31; pos >= 0; pos--){
            int i = 1 & (num >> pos);
            if(node->children[i] == nullptr) node->children[i] = new Trie();
            node = node->children[i];
        }
    }
    
    int maxdiff(int num){
        Trie *node = this;
        int ans = 0;
        for(int pos = 31; pos >= 0; pos--){
            int i = 1 & (num >> pos);
            if(node->children[i^1] != nullptr) i = i^1;
            if(node->children[i] == nullptr){
                ans = ans | ((~0) >> (31-pos));
                break;
            }
            ans = ans | (i << pos);
            node = node->children[i];
        }
        return ans ^ num;
    }
    
private:
    vector<Trie *> children;
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *trie = new Trie();
        for(auto num: nums) trie->insert(num);
        int ans = 0;
        for(auto num: nums) ans = max(ans, trie->maxdiff(num));
        return ans;
    }
};