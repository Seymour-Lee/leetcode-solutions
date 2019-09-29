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

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) for(int j = i+1; j < nums.size(); j++){
            int k = binary(nums, j+1, nums.size(), nums[i]+nums[j]);
            //cout<<k<<" "<<j<<endl;
            ans += k-j;
        }
        return ans;
    }
    
private:
    int binary(vector<int> &nums, int l, int r, int target){
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] < target) l = m+1;
            else r = m;
        }
        return l-1;
    }
};