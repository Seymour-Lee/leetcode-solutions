class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int start = 0;
        int end = n - 1;
        int counter = 1;
        while(start < end){
            for(int c = start; c <= end; c++) result[start][c] = counter++;
            for(int r = start+1; r <= end-1; r++) result[r][end] = counter++;
            for(int c = end; c >= start; c--) result[end][c] = counter++;
            for(int r = end-1; r >= start+1; r--) result[r][start] = counter++;
            start++;
            end--;
        }
        if(start == end) result[start][start] = n * n;
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int num = 1;
        int si = 0, sj = 0;
        int ei = n-1, ej = n-1;
        while(si < ei && sj < ej){
            int i = si, j = sj;
            while(j <= ej) ans[i][j++] = num++; j--; i++;
            while(i < ei) ans[i++][j] = num++;
            while(j >= sj) ans[i][j--] = num++; j++; i--;
            while(i > si) ans[i--][j] = num++;
            si++, sj++, ei--, ej--;
        }
        if(si == ei) ans[si][sj] = n*n;
        return ans;
    }
};