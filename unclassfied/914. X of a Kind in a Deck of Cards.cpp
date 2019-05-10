class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int ,int> num2freq;
        for(auto num: deck) num2freq[num]++;
        vector<int> nums;
        for(auto it: num2freq) nums.push_back(it.second);
        int x = nums[0];
        for(int i = 1; i < nums.size(); i++) x = min(x, gcd(nums[i-1], nums[i]));
        return x >= 2;
    }

private:
    int gcd(int x, int y){
        while(y){
            int tmp = x % y;
            x = y;
            y = tmp;
        }
        return x;
    }
};