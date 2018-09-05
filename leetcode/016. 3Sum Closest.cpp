class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, j, k;
        int sum, result;
        int smallest = INT_MAX;
        while(i < nums.size() - 2){
            j = i + 1;
            k = nums.size() - 1;
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                if(diff < smallest){
                    result = sum;
                    smallest = diff;
                }
                if(sum - target == 0) return sum;
                else if(sum < target) j++;
                else k--;
            }
            i++;
        }
        return result;
    }
};