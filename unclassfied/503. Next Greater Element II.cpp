class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size() == 0) return vector<int>();
        vector<int> result(nums.size(), INT_MIN);
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < nums.size(); i++){
            while(stk.empty() == false && nums[i] > nums[stk.top()]){
                result[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        int i = 0;
        while(stk.size() > 1){
            while(i < nums.size() && nums[stk.top()] >= nums[i]) i++;
            if(i == nums.size()) break;
            while(nums[stk.top()] < nums[i]){
                result[stk.top()] = nums[i];
                stk.pop();
            }
        }
        while(stk.empty() == false){
            result[stk.top()] = -1;
            stk.pop();
        }
        return result;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.size() == 0) return vector<int>();
        vector<int> result(nums.size(), INT_MIN);
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < nums.size(); i++){
            while(stk.empty() == false && nums[i] > nums[stk.top()]){
                result[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        int i = 0;
        while(stk.size() > 1){
            while(i < nums.size() && nums[stk.top()] >= nums[i]) i++;
            if(i == nums.size()) break;
            while(nums[stk.top()] < nums[i]){
                result[stk.top()] = nums[i];
                stk.pop();
            }
        }
        while(stk.empty() == false){
            result[stk.top()] = -1;
            stk.pop();
        }
        return result;
    }
};