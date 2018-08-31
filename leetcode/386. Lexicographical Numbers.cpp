class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for(int i = 1; i < 10; i++){
            dfs(i, n, result);
        }
        return result;
    }
    
private:
    void dfs(int cur, int n, vector<int> &res){
        if(cur > n) return;
        res.push_back(cur);
        for(int i = 0; i < 10 && cur*10+i <= n; i++){
            dfs(cur*10+i, n, res);
        }
    }
};