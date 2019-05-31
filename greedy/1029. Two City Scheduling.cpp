class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        int ans = 0;
        auto f = [](vector<int> a, vector<int> b){
            return (a[0]-a[1]) < (b[0]-b[1]);  
        };
        sort(costs.begin(), costs.end(), f);
        int count = 0;
        for(auto c: costs){
            if(count < n) ans += c[0], count++;
            else ans += c[1];
        }
        return ans;
    }
};

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        auto f = [](vector<int> &a, vector<int> &b){
            return (a[0]-a[1]) < (b[0]-b[1]);
        };
        sort(costs.begin(), costs.end(), f);
        int ans = 0;
        int acounter = 0;
        for(auto c: costs){
            if(acounter < costs.size()/2) ans += c[0], acounter++;
            else ans += c[1];
        }
        return ans;
    }
};