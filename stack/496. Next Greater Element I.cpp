class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if(nums.size() == 0 || findNums.size() == 0) return vector<int>();
        map<int, int> dict;
        for(int i = 0; i < nums.size(); i++) dict[nums[i]] = i;
        vector<int> result;
        for(auto num: findNums){
            bool find = false;
            for(int i = dict[num]; i < nums.size(); i++){
                if(nums[i] > num){
                    result.push_back(nums[i]);
                    find = true;
                    break;
                }
            }
            if(find == false) result.push_back(-1);
        }
        return result;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> a2b;
        vector<int> ans;
        for(int i = 0; i < nums2.size(); i++){
            while(stk.empty() == false && stk.top() < nums2[i]){
                a2b[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        while(stk.empty() == false){
            a2b[stk.top()] = -1;
            stk.pop();
        }
        for(auto a: nums1) ans.push_back(a2b[a]);
        return ans;
    }
};