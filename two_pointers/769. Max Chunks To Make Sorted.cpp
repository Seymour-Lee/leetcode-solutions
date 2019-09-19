class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result = 0;
        int largest = 0;
        for(int i = 0; i < arr.size(); i++){
            largest = max(arr[i], largest);
            if(largest == i) result++;
        }
        return result;
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int l = 0, r = 0;
        int maxval = INT_MIN, minval = INT_MAX;
        int ans = 0;
        while(l <= r && r < arr.size()){
            maxval = max(maxval, arr[r]);
            minval = min(minval, arr[r]);
            // cout<<l<<" "<<r<<" "<<minval<<" "<<maxval<<endl;
            if(l == minval && r == maxval){
                ans++;
                maxval = INT_MIN, minval = INT_MAX;
                l = r+1;
            }
            r++;
        }
        return ans;
    }
};