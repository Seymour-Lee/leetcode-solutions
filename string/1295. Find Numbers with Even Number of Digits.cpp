class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto num: nums){
            string str = to_string(num);
            if(str.size() % 2 == 0) ans++;
        }
        return ans;
    }
};