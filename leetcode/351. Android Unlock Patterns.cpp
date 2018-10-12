class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        vector<bool> visited(9, false);
        for(int len = m; len <= n; len++){
            ans += backtracking(-1, len, visited);
        }
        return ans;
    }
    
private:
    bool valid(int cur, int next, vector<bool> visited){
        if(cur == -1 || cur == 4) return true;
        if(cur == 1) return next != 7 || visited[4] == true;
        if(cur == 3) return next != 5 || visited[4] == true;
        if(cur == 5) return next != 3 || visited[4] == true;
        if(cur == 7) return next != 1 || visited[4] == true;
        if(next % 2 == 1 || next == 4) return true;
        return visited[(cur+next)/2] == true;
    }
    
    int backtracking(int pos, int len, vector<bool> visited){
        if(len == 0) return 1;
        int ans = 0;
        for(int i = 0; i < 9; i++){
            if(visited[i] == false && valid(pos, i, visited)){
                visited[i] = true;
                ans += backtracking(i, len-1, visited);
                visited[i] = false;
            }
        }
        return ans;
    }
};