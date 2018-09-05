class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lower = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int upper = lower--;
        while(k--){
            if(lower < 0 || (upper < n && abs(arr[upper] - x) < abs(x - arr[lower]))) upper++;
            else lower--;
        }
        return vector<int>(arr.begin()+lower+1, arr.begin()+upper);
    }
};