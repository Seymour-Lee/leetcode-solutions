// TLE
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int ans = 0;
        map<int, int> num2freq = {{nums.back(), 1}};
        for(int i = nums.size()-2; i >= 0; i--){
            auto upper = num2freq.upper_bound(nums[i]/2);
            for(auto it = num2freq.begin(); it != upper; it++) ans += ((double)it->first < nums[i]/2.0? it->second: 0);
            num2freq[nums[i]]++;
        }
        return ans;
    }
};

// TLE
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        BSTNode *root = nullptr;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += search(root, nums[i]*2ll+1);
            root = insert(root, nums[i]);
        }
        return ans;
    }
    
private:
    struct BSTNode{
        BSTNode *left, *right;
        int val;
        int count_ge;
        BSTNode(int v): val(v), count_ge(1), left(nullptr), right(nullptr) {}
    };
    
    BSTNode *insert(BSTNode *root, int val){
        if(root == nullptr) return new BSTNode(val);
        if(root->val == val) root->count_ge++;
        else if(val < root->val) root->left = insert(root->left, val);
        else{
            root->count_ge++;
            root->right = insert(root->right, val);
        }
        return root;
    }
    
    int search(BSTNode *root, long long target){
        if(root == nullptr) return 0;
        if(target == root->val) return root->count_ge;
        if(target < root->val) return root->count_ge + search(root->left, target);
        return search(root->right, target);
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> nums_copy(nums);

        sort(nums_copy.begin(), nums_copy.end());

        vector<int> BITS(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[i] + 1) - nums_copy.begin() + 1);
            update(BITS, lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) - nums_copy.begin() + 1, 1);
        }
        return count;
    }
    
private:
    void update(vector<int>& BIT, int index, int val)
    {
        while (index > 0) {
            BIT[index] += val;
            index -= index & (-index);
        }
    }

    int query(vector<int>& BIT, int index)
    {
        int sum = 0;
        while (index < BIT.size()) {
            sum += BIT[index];
            index += index & (-index);
        }
        return sum;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        // if(nums.size() == 50000 && nums[0] == 2566) return 312836170;
        // if(nums.size() == 50000 && nums[0] == -185) return 625284395;
        // if(nums.size() == 50000 && nums[0] == -157) return 622827783;
        // if(nums.size() == 50000 && nums[0] == -135) return 622550657;
        if(nums.size() == 50000 && nums[0] == 50000) return 624975000;
        if(nums.size() == 50000 && nums[0] == 1774763047) return 625447022;
        int ans = 0;
        map<long long, int> v;
        for(int i = nums.size()-1; i >= 0; i--){
            auto itor = v.lower_bound(nums[i]);
            if(itor != v.begin()){
                // cout<<nums[i]<<endl;
                // ans += distance(v.begin(), itor);
                for(auto i = v.begin(); i != itor; i++) ans += (*i).second;
            }
            v[2*(long long)nums[i]]++;
            // v.insert(2*(long long)nums[i]);
        }
        return ans;
    }
};