class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return vector<int>{};
        vector<int> result(matrix.size()*matrix[0].size());
        for(int i = 0, r = 0, c = 0; i < result.size(); i++){
            result[i] = matrix[r][c];
            if((r + c) % 2 == 0){
                if(c == matrix[0].size()-1)r++;
                else if(r == 0) c++;
                else{r--; c++;}
            }
            else{
                if(r == matrix.size()-1) c++;
                else if(c == 0) r++;
                else{r++; c--;}
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& g) {
        if(g.size() == 0 || g[0].size() == 0) return {};
        int m = g.size(), n = g[0].size();
        vector<int> ans;
        int lx = 0, ly = 0, rx = 0, ry = 0;
        bool up = true;
        while(ans.size() < m*n){
            if(up){
                int i = lx, j = ly;
                while(i != rx && j != ry) ans.push_back(g[i--][j++]);
                ans.push_back(g[i][j]);
            }
            else{
                int i = rx, j = ry;
                while(i != lx && j != ly) ans.push_back(g[i++][j--]);
                ans.push_back(g[i][j]);
            }
            up = !up;
            if(lx+1 == m) ly++; else lx++;
            if(ry+1 == n) rx++; else ry++;
        }
        return ans;
    }
};