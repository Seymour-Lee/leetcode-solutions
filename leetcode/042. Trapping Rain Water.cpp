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

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int i = 0, j = 1;
        while(i < height.size() && j < height.size()){
            if(height[i] > height[j]) j++;
            else{
                int l = height[i];
                while(i < j) ans += l-height[i++];
                j++;
            }
        }
        reverse(height.begin(), height.end());
        i = 0, j = 1;
        while(i < height.size() && j < height.size()){
            if(height[i] >= height[j]) j++;
            else{
                int l = height[i];
                while(i < j) ans += l-height[i++];
                j++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& h) {
        if(h.size() <= 1) return 0;
        vector<int> l(h.size(), h[0]);
        vector<int> r(h.size(), h.back());
        for(int i = 1; i < h.size(); i++) l[i] = max(l[i-1], h[i]);
        for(int i = h.size()-2; i >= 0; i--) r[i] = max(r[i+1], h[i]);
        int ans = 0;
        for(int i = 0; i < h.size(); i++)
            if(l[i] > h[i] && r[i] > h[i]) ans += min(l[i], r[i])-h[i];
        return ans;
    }
};