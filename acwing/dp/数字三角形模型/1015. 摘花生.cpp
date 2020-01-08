#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int r, c;
        cin >> r >> c;
        vector<vector<int>> g = vector<vector<int>>(r, vector<int>(c));
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin>>g[i][j];
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) g[i][j] += max(i-1 >= 0? g[i-1][j]: 0, j-1 >= 0? g[i][j-1]: 0);
        cout<<g.back().back()<<endl;
    }
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int r, c;
        cin >> r >> c;
        vector<vector<int>> g(r, vector<int>(c, 0));
        vector<vector<int>> dp(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> g[i][j];
                int a = (i == 0? 0: dp[i-1][j]);
                int b = (j == 0? 0: dp[i][j-1]);
                dp[i][j] = max(a, b) + g[i][j];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        cout<<dp[r-1][c-1]<<endl;
    }
    return 0;
}
