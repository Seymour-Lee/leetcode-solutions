class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int minval = INT_MAX;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++){
            if(abs(arr[i]-arr[i-1]) == minval) ans.push_back({arr[i-1], arr[i]});
            if(abs(arr[i]-arr[i-1]) < minval){
                minval = abs(arr[i]-arr[i-1]);
                ans = {{arr[i-1], arr[i]}};
            }
        }
        return ans;
        // for(int i = 0; i < arr.size(); i++) for(int j = 0; j < i; j++){
        //     if(abs(arr[i]-arr[j]) == minval){
        //         ans.push_back({min(arr[i], arr[j]), max(arr[i], arr[j])});
        //     }
        //     else if(abs(arr[i]-arr[j]) < minval){
        //         ans = {{min(arr[i], arr[j]), max(arr[i], arr[j])}};
        //         minval = abs(arr[i]-arr[j]);
        //     }
        // }
        // sort(ans.begin(), ans.end());
        // return ans;
    }
};