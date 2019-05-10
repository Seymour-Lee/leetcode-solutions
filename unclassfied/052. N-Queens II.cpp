class Solution {
public:
    int totalNQueens(int n) {
        if(n == 0) return 0;
        int ans = 0;
        for(int col = 0; col < n; col++)
            backtracking(ans, n, {{0, col}}, 1);
        return ans;
    }
    
private:
    void backtracking(int &ans, const int n, vector<pair<int, int>> queens, int row){
        if(row == n){
            ans++;
            return;
        }
        for(int col = 0; col < n; col++){
            bool ok = true;
            for(int i = 0; i < queens.size() && ok == true; i++) 
                ok = ok && valid({row, col}, queens[i]);
            if(ok == true){
                queens.push_back({row, col});
                backtracking(ans, n, queens, row+1);
                queens.pop_back();
            }
        }
    }
    
    bool valid(pair<int, int> a, pair<int, int> b){
        return a.first != b.first 
            && a.second != b.second 
            && abs(a.first-b.first) != abs(a.second-b.second);
    }
};