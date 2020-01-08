#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1010;

int nums[N];

int main(){
    int n = 0;
    while(cin >> nums[n]) n++;
    vector<int> dp(n, 1);
    for(int j = 0; j < n; j++) for(int i = 0; i < j; i++){
        if(nums[i] >= nums[j]) dp[j] = max(dp[j], dp[i]+1);
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
    
    vector<int> q;
    for(int i = 0; i < n; i++){
        int pos = 0;
        while(pos < q.size() && nums[i] > q[pos]) pos++;
        if(pos == q.size()) q.push_back(nums[i]);
        else q[pos] = nums[i];
    }
    cout<<q.size();
    return 0;
}