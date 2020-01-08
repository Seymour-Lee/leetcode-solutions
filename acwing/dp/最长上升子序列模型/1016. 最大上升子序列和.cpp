#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n), dp(n);
    for(int i = 0; i < n; i++) cin >> nums[i], dp[i] = nums[i];
    for(int j = 0; j < n; j++) for(int i = 0; i < j; i++){
        if(nums[i] < nums[j]) dp[j] = max(dp[j], dp[i]+nums[j]);
    }
    cout<<*max_element(dp.begin(), dp.end());
    return 0;
}