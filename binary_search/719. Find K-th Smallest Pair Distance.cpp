class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back()-nums[0];
        while(l < r){
            int m = l + (r - l) / 2;
            int count = 0, i = 0;
            for(int j = 0; j < nums.size(); j++){
                while(nums[j]-nums[i] > m) i++;
                count += j-i;
            }
            if(count >= k) r = m;
            else l = m+1;
        }
        return l;
    }
};

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back()-nums[0];
        while(l < r){
            int m = l + (r - l) / 2;
            int count = 0, i = 0;
            for(int j = 0; j < nums.size(); j++){
                while(nums[j]-nums[i] > m) i++;
                count += j-i;
            }
            if(count >= k) r = m;
            else l = m+1;
        }
        return l;
    }
};