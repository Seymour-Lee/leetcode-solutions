class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        for(auto num: nums){
            if(st.find(num) != st.end()){
                return num;
            }
            st.insert(num);
        }
        return -1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return 0;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) if(nums[i-1] == nums[i]) return nums[i];
        return -1;
    }
};