class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        vector<vector<int>> count(2*n+1, vector<int>(2*n+1, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(A[i][j] == 1)
                    for(int i2 = 0; i2 < n; i2++)
                        for(int j2 = 0; j2 < n; j2++)
                            if(B[i2][j2] == 1)
                                count[i-i2+n][j-j2+n]++;
        int result = 0;
        for(auto row: count)
            for(auto v: row)
                result = max(result, v);
        return result;
    }
};