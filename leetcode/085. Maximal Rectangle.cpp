class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> left(n, 0), right(n, n), height(n, 0);
        for(int i = 0; i < m; i++){
            int curl = 0, curr = n;
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1') left[j] = max(left[j], curl);
                else{left[j] = 0; curl = j+1;}
            }
            for(int j = n-1; j >= 0; j--){
                if(matrix[i][j] == '1') right[j] = min(right[j], curr);
                else{right[j] = n; curr = j;}
            }
            for(int j = 0; j < n; j++)
                ans = max(ans, (right[j] - left[j]) * height[j]);
        }
        return ans;
    }
};