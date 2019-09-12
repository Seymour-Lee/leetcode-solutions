class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        vector<int> sums = {0, 0};
        for(int i = 2; i < A.size(); i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                sums.push_back(sums[i-1] + 1);
                result += sums[i];
            }
            else{
                sums.push_back(0);
            }
        }
        return result;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2) return 0;
        int ans = 0;
        vector<vector<bool>> dp(A.size(), vector<bool>(A.size(), false));
        auto arithmetic = [](int a, int b, int c){return b-a == c-b;};
        for(int i = 0; i < A.size()-2; i++) 
            if(arithmetic(A[i], A[i+1], A[i+2])) dp[i][i+2] = true, ans++;
        for(int len = 4; len <= A.size(); len++){
            for(int i = 0; i+len <= A.size(); i++){
                int j = i+len-1;
                if(dp[i][j-1] && arithmetic(A[j-2], A[j-1], A[j]))
                    dp[i][j] = true, ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result = 0;
        vector<int> sums = {0, 0};
        for(int i = 2; i < A.size(); i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                sums.push_back(sums[i-1] + 1);
                result += sums[i];
            }
            else{
                sums.push_back(0);
            }
        }
        return result;
    }
};