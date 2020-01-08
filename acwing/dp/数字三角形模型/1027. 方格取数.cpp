#include <iostream>
#include <vector>

using namespace std;

// [i1][j1][i2][j2] = max value after [i1][j1] and [i2][j2]
// if A and B step into the same position => i1 == i2 && j1 == j2, 
//      [i1][j1][i2][j2] = g[i1][j1] 
//                  + max([i1][j1-1][i2][j2-1], [i1][j1-1][i2-1][j2], [i1-1][j1][i2-1][j2], [i1-1][j1][i2][j2-1])
// else [i1][j1][i2][j2] = g[i1][j1] + g[i2][j2]
//                  + max([i1][j1-1][i2][j2-1], [i1][j1-1][i2-1][j2], [i1-1][j1][i2-1][j2], [i1-1][j1][i2][j2-1])
// assuming i1+j1 == i2+j2 == k, we can get i1 == k-j1, i2 == k-j2
// [i1][j1][i2][j2] => dp[k][i1][i2]
// if(i1 == i2) A and B step into the same position [k][i1][i2] = max([k-1][][])
// else 
// => dp[k][i1][i2] = max()

const int N = 15;
int g[N][N];
int dp[N*2][N][N];

int main(){
    int n;
    cin >> n;
    int i, j, v;
    while(cin >> i >> j >> v, i || j || v) g[i][j] = v;
    for(int k = 2; k <= n+n; k++){
        for(int i1 = 1; i1 <= n && i1 < k; i1++){
            for(int i2 = 1; i2 <= n && i2 < k; i2++){
                int j1 = k-i1, j2 = k-i2;
                int t = g[i1][j1] + (i1 == i2? 0: g[i2][j2]);
                dp[k][i1][i2] = max(dp[k][i1][i2], dp[k-1][i1][i2]+t);
                dp[k][i1][i2] = max(dp[k][i1][i2], dp[k-1][i1-1][i2]+t);
                dp[k][i1][i2] = max(dp[k][i1][i2], dp[k-1][i1][i2-1]+t);
                dp[k][i1][i2] = max(dp[k][i1][i2], dp[k-1][i1-1][i2-1]+t);
            }
        }
    }
    cout<<dp[2*n][n][n];
    return 0;
}

