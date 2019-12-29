class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxval = -1;
        for(int i = arr.size()-1; i >= 0; i--){
            int val = arr[i];
            arr[i] = maxval;
            maxval = max(maxval, val);
        }
        return arr;
    }
};