class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int prev = nums.size()-2;
        while(prev >= 0 && nums[prev] <= nums[prev+1]) prev--;
        if(prev == -1){
            reverse(nums.begin(), nums.end());
            return nums;
        }
        reverse(nums.begin()+prev+1, nums.end());
        int next = prev+1;
        while(nums[prev] <= nums[next]) next++;
        swap(nums[prev], nums[next]);
        return nums;
    }
};