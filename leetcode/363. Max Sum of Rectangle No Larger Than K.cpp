class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0) return 0;
        int ans = INT_MIN;
        int row = matrix.size(), col = matrix[0].size();
        for(int l = 0; l < col; l++){
            vector<int> sums(row, 0);
            for(int r = l; r < col; r++){
                for(int i = 0; i < row; i++) sums[i] += matrix[i][r];
                set<int> accuset;
                accuset.insert(0);
                int cursum = 0, curmax = INT_MIN;
                for(auto sum: sums){
                    cursum += sum;
                    auto it = accuset.lower_bound(cursum-k);
                    if(it != accuset.end()) curmax = max(curmax, cursum - *it);
                    accuset.insert(cursum);
                }
                ans = max(ans, curmax);
            }
        }
        return ans;
    }
};