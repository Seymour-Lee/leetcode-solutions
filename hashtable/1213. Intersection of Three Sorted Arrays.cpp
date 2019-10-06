class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        unordered_map<int, int> a2c;
        vector<int> ans;
        for(auto a: arr1) a2c[a]++; for(auto a: arr2) a2c[a]++;
        for(auto a: arr3) if(a2c[a] == 2) ans.push_back(a);
        return ans;
    }
};