class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> a2c;
        for(auto a: arr) a2c[a]++;
        vector<int> nums;
        for(auto &p: a2c) nums.push_back(p.second);
        auto f = [](int a, int b){
            return a > b;
        };
        sort(nums.begin(), nums.end(), f);
        int ans = 0;
        int counter = 0;
        for(auto num: nums){
            if(counter >= arr.size()/2) break;
            ans++;
            counter += num;
            // cout<<ans<<" "<<num<<" "<<counter<<endl;
        }
        return ans;
    }
};

// [7,7,7,7,7,7]
// [1,9]
// [1000,1000,3,7]
// [1,2,3,4,5,6,7,8,9,10]