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

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> apos;
        vector<int> bpos;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                if(A[i][j] == 1){
                    apos.push_back(i*100+j);
                }
                if(B[i][j] == 1){
                    bpos.push_back(i*100+j);
                }
            }
        }
        map<int, int> delta2num;
        for(auto a: apos) for(auto b: bpos){
            delta2num[a-b]++;
        }
        int ans = 0;
        for(auto p: delta2num) ans = max(ans, p.second);
        return ans;
    }
};