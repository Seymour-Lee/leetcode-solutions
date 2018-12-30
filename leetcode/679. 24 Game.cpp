class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        while(true){
            if(dfs(nums)) return true;
            if(next_permutation(nums.begin(), nums.end()) == false) break;
        }
        return false;
    }
    
private:
    bool dfs(vector<int>& nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (three(a+b, c, d) || three(a-b, c, d) || three(a*b, c, d) || three(a/b, c, d)) return true;
        if (three(a, b+c, d) || three(a, b-c, d) || three(a, b*c, d) || three(a, b/c, d)) return true;
        if (three(a, b, c+d) || three(a, b, c-d) || three(a, b, c*d) || three(a, b, c/d)) return true;
        return false;
    }
    bool three(double a, double b, double c) {
        if (two(a+b, c) || two(a-b, c) || two(a*b, c) || b&&two(a/b, c)) return true;
        if (two(a, b+c) || two(a, b-c) || two(a, b*c) || c&&two(a, b/c)) return true;
        return false;
    }
    bool two(double a, double b) {
        if (abs(a+b-24.0) < 0.0001 || abs(a-b-24.0) < 0.0001 || abs(a*b-24.0) < 0.0001 || b&&abs(a/b-24.0) < 0.0001) 
            return true;
        return false;
    }
};