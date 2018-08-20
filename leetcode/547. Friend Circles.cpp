class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result = 0;
        for(int i = 0; i < M.size(); i++){
            if(M[i][i]){
                result++;
                dfs(M, i);
            }
        }
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& M, int peo){
        for(int i = 0; i < M.size(); i++){
            if(peo != i && M[i][i] && M[peo][i]){
                M[peo][i] = 0;
                M[i][peo] = 0;
                dfs(M, i);
            }
        }
        M[peo][peo] = 0;
    }
};