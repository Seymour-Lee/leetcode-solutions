class Solution {
public:
    double soupServings(int N) {
        vector<vector<double>> memo(200, vector<double>(200, 0));
        return N >= 4800 ?  1.0 : f((N + 24) / 25, (N + 24) / 25, memo);
    }

private:
    double f(int a, int b, vector<vector<double>> &memo){
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1;
        if (b <= 0) return 0;
        if (memo[a][b] > 0) return memo[a][b];
        memo[a][b] = 0.25 * (f(a-4, b, memo) + f(a-3, b-1, memo) + 
                            f(a-2, b-2, memo) + f(a-1, b-3, memo));
        return memo[a][b];
    }
};