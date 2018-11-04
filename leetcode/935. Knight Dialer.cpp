class Solution {
public:
    const unsigned int mod = 1000000000+7;
    const vector<vector<unsigned long long>> matrix = {
       //0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        {0, 0, 0, 0, 1, 0, 1, 0, 0, 0}, // 0
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}, // 1
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, // 2
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0}, // 3
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1}, // 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, // 6
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, // 7
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, // 8
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}, // 9
    };
    int knightDialer(int N) {
        if(N == 1) return 10;
        auto vec = fasterPower(N-1);
        unsigned long long ans = 0;
        for(auto row: vec){
            for(auto e: row){
                cout<<e<<" ";
                ans = (ans + e) % mod;
            }
            cout<<endl;
        }
        return (int)ans;
    }
    
    vector<vector<unsigned long long>> fasterPower(int n){
        if(n == 1) return matrix;
        if(n % 2 == 1){
            auto half = fasterPower(n / 2);
            return multiply(multiply(half, half), matrix);
        }
        else{
            auto half = fasterPower(n / 2);
            return multiply(half, half);
        }
    }
    
    vector<vector<unsigned long long>> multiply(vector<vector<unsigned long long>> a, 
                                                vector<vector<unsigned long long>> b){
        vector<vector<unsigned long long>> ans(10, vector<unsigned long long>(10, 0));
        int i, j, k; 
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                ans[i][j] = 0;
                for(k = 0; k < 10; k++){
                    ans[i][j] = (ans[i][j] + (a[i][k]*b[k][j]) % mod) % mod;
                }
            }
        }
        
        return ans;
    }
};