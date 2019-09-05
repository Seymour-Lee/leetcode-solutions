class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        for(auto row: matrix){
            if(row.front() <= target && target <= row.back()){
                return binary_search(row.begin(), row.end(), target);
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int l = 0, r = matrix.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(matrix[m][0] <= target && target <= matrix[m].back())
                return binary_search(matrix[m].begin(), matrix[m].end(), target);
            if(matrix[m].back() < target) l = m+1;
            else r = m-1;
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        if(m.size() == false || m[0].size() == 0) return false;
        int rl = 0, rr = m.size();
        while(rl < rr){
            int rm = rl + (rr - rl) / 2;
            if(m[rm].back() < target) rl = rm + 1;
            else rr = rm;
        }
        if(rl == m.size()) return false;
        int cl = 0, cr = m[rl].size();
        while(cl < cr){
            int cm = cl + (cr - cl) / 2;
            if(m[rl][cm] < target) cl = cm + 1;
            else cr = cm;
        }
        return cl < m[rl].size() && m[rl][cl] == target;
    }
};