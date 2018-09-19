class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 1) return 0;
        int ans = 0;
        vector<int> left(height.size(), height[0]);
        vector<int> right(height.size(), height.back());
        for(int i = 1; i < left.size(); i++) 
            left[i] = max(left[i-1], height[i]);
        for(int i = right.size()-2; i >= 0; i--)
            right[i] = max(right[i+1], height[i]);
        for(int i = 0; i < height.size(); i++)
            ans += min(left[i], right[i]) - height[i];
        return ans;
    }
};