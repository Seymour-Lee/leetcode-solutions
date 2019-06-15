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

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX/2;
        for(int i = 0; i < nums.size()-2; i++){
            int j = i+1, k = nums.size()-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum-target) < abs(ans-target)) ans = sum;
                if(sum > target) k--;
                else j++;
            }
        }
        return ans;
    }
};