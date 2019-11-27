#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int a, b, c;
    cin>>a>>b>>c;
    vector<int> nums = {a, b, c};
    sort(nums.begin(), nums.end());
    for(auto a: nums) cout<<a<<endl;
    cout<<endl<<a<<endl<<b<<endl<<c;
    return 0;
}