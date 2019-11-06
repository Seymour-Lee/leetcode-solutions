class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // int count = 0; 
        // for (int i = 0; i < nums.size(); i++){ 
        //     int odd = 0; 
        //     for (int j = i; j < nums.size(); j++){ 
        //         if (nums[j] % 2) odd++; 
        //         if (odd == k) count++; 
        //     } 
        // } 
        // return count; 
        int count = 0; 
        int n = nums.size();
        vector<int> prefix(n, 0);
        int odd = 0; 
        for (int i = 0; i < n; i++){ 
            prefix[odd]++; 
            if (nums[i] & 1) odd++; 
            if (odd >= k) count += prefix[odd - k]; 
        } 
        return count; 
    }
};