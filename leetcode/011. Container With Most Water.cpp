class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int l = 0, r = height.size()-1;
        while(l < r){
            result = max(result, min(height[l], height[r]) * (r - l));
            if(height[l] > height[r]) r--;
            else l++;
        }
        return result;
    }
};