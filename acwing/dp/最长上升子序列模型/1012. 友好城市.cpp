#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [](pair<int, int> b, pair<int, int> c){
        return b.first < c.first;
    });
    for(int j = 0; j < n; j++) for(int i = 0; i < j; i++){
        if(a[i].second < a[j].second) dp[j] = max(dp[j], dp[i]+1);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    cout<<ans;
    return 0;
}