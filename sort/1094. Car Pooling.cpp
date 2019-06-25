class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> arr;
        for(auto t: trips){
            arr.push_back({t[1], t[0]});
            arr.push_back({t[2], -t[0]});
        }
        sort(arr.begin(), arr.end());
        for(auto p: arr){
            // cout<<p.first<<" "<<p.second<<endl;
            capacity -= p.second;
            if(capacity < 0) return false;
        }
        return true;
    }
};