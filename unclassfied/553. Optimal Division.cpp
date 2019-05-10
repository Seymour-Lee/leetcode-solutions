class Solution {
public:    
    string optimalDivision(vector<int>& nums) {
        vector<vector<T*>> memo(nums.size(), vector<T*>(nums.size(), nullptr));
        T *t = optimal(nums, 0, nums.size()-1, memo);
        return t->max_str;
    }
    
private:
    class T {
    public:
        T(){
            max_val = numeric_limits<double>::min();
            min_val = numeric_limits<double>::max();
            max_str = to_string(max_val);
            min_str = to_string(min_val);
        }
        
        double max_val, min_val;
        string max_str, min_str;
    };
    
    T *optimal(vector<int> nums, int start, int end, vector<vector<T*>> &memo){
        if(memo[start][end] != nullptr) return memo[start][end];
        T *t = new T();
        if(start == end){
            t->max_val = nums[start];
            t->min_val = nums[start];
            t->min_str = to_string(nums[start]);
            t->max_str = to_string(nums[start]);
            memo[start][end] = t;
            return t;
        }
        for (int i = start; i < end; i++) {
            T *left = optimal(nums, start, i, memo);
            T *right = optimal(nums, i + 1, end, memo);
            if (t->min_val > left->min_val / right->max_val) {
                t->min_val = left->min_val / right->max_val;
                t->min_str = left->min_str + "/" + (i + 1 != end ? "(" : "") + right->max_str + (i + 1 != end ? ")" : "");
            }
            if (t->max_val < left->max_val / right->min_val) {
                t->max_val = left->max_val / right->min_val;
                t->max_str = left->max_str + "/" + (i + 1 != end ? "(" : "") + right->min_str + (i + 1 != end ? ")" : "");
            }
        }
        memo[start][end] = t;
        return t;
    }
};