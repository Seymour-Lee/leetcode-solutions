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

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int ans = 0;
        while(i < j){
            ans = max(ans, (j-i)*min(height[i], height[j]));
            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};