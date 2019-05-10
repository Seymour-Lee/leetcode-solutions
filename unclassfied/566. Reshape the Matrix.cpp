class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.size() == 0) return nums;
        if(nums.size() * nums[0].size() != r * c) return nums;
        vector<vector<int>> result(r, vector<int>(c, 0));
        int m = 0;
        int n = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                if(n >= c){
                    n = 0;
                    m++;
                }
                result[m][n++] = nums[i][j];
            }
        }
        return result;
    }
};