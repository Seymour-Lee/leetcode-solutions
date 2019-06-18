class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        return binary(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1, target);
    }
    
private:
    bool binary(vector<vector<int>> &matrix, 
                int sr, int sc, int er, int ec,
                int target){
        if(sr > er || sc > ec) return false;
        if(sr == er && sc == ec) return matrix[sr][sc] == target;
        if(target < matrix[sr][sc] || matrix[er][ec] < target) return false;
        int mr = sr + (er - sr) / 2;
        int mc = sc + (ec - sc) / 2;
        int mid = matrix[mr][mc];
        if(mid == target) return true;
        else{
            return binary(matrix, sr, sc, mr, mc, target) ||
                   binary(matrix, sr, mc+1, mr, ec, target) ||
                   binary(matrix, mr+1, sc, er, mc, target) ||
                   binary(matrix, mr+1, mc+1, er, ec, target);
        }
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        return dq(matrix, target, 0, 0, matrix.size()-1, matrix[0].size()-1);
    }
    
private:
    bool dq(vector<vector<int>> &m, int t, int lr, int lc, int rr, int rc){
        if(lr > rr || lc > rc) return false;
        if(lr == rr && lc == rc) return m[lr][lc] == t;
        // cout<<lr<<" "<<lc<<" "<<rr<<" "<<rc<<endl;
        int mr = lr + (rr - lr) / 2;
        int mc = lc + (rc - lc) / 2;
        // cout<<mr<<" "<<mc<<endl;
        if(m[mr][mc] == t) return true;
        else if(m[mr][mc] > t) return dq(m, t, lr, lc, mr, mc) || dq(m, t, lr, mc+1, mr, rc) || dq(m, t, mr+1, lc, rr, mc);
        else return dq(m, t, lr, mc+1, mr, rc) || dq(m, t, mr+1, lc, rr, mc) || dq(m, t, mr+1, mc+1, rr, rc);
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int i = matrix.size()-1, j = 0;
        while(i >= 0 && j < matrix[0].size()){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) j++;
            else i--;
        }
        return false;
    }
};