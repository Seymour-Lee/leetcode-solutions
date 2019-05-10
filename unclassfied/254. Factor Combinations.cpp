class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        set<multiset<int>> res;
        backtracking(res, n, {});
        vector<vector<int>> ans;
        for(auto g: res) ans.push_back(vector<int>(g.begin(), g.end()));
        return ans;
    }
    
private:
    void backtracking(set<multiset<int>> &ans, int n, multiset<int> cur){
        if(n == 1) return;
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                cur.insert(i); cur.insert(n/i);
                ans.insert(cur);
                cur.erase(cur.find(n/i));
                backtracking(ans, n/i, cur);
                cur.erase(cur.find(i));
            }
        }
    }
};