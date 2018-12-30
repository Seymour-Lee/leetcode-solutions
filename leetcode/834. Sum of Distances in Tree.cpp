class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        if(N == 1) return {0};
        ans = vector<int>(N, 0);
        cnt = vector<int>(N, 0);
        g = vector<unordered_set<int>>(N);
        for(auto e: edges){
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        dfs(0);
        dfs1(0, N);
        return ans;
    }
    
private:
    vector<int> ans;
    vector<int> cnt;
    vector<unordered_set<int>> g;
    unordered_set<int> v1;
    unordered_set<int> v2;
    
    void dfs(int root){
        v1.insert(root);
        for(auto i: g[root]){
            if(v1.find(i) == v1.end()){
                dfs(i);
                cnt[root] += cnt[i];
                ans[root] += ans[i] + cnt[i];
            }
        }
        cnt[root]++;
    }
    
    void dfs1(int root, int N){
        v2.insert(root);
        for (auto i : g[root]) if (v2.find(i) == v2.end()) {
                ans[i] = ans[root] - cnt[i] + N - cnt[i];
                dfs1(i, N);
        };
    }
};