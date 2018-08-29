class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() <= 2) return 0;
        int result = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size()-2; i++){
            cout<<i<<endl;
            for(int j = i + 1; j < nums.size()-1; j++){
                int k = j + 1;
                while(k < nums.size() && nums[i] + nums[j] > nums[k]) k++;
                result += k - j - 1;
            }
        }
        return result;
    }
};