class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int aa = (a >> i) & 1;
            int bb = (b >> i) & 1;
            int cc = (c >> i) & 1;
            vector<int> nums ={aa, bb, cc};
            if(nums == vector<int>{0, 0, 0}) ans += 0;
            if(nums == vector<int>{0, 0, 1}) ans += 1;
            if(nums == vector<int>{0, 1, 0}) ans += 1;
            if(nums == vector<int>{0, 1, 1}) ans += 0;
            if(nums == vector<int>{1, 0, 0}) ans += 1;
            if(nums == vector<int>{1, 0, 1}) ans += 0;
            if(nums == vector<int>{1, 1, 0}) ans += 2;
            if(nums == vector<int>{1, 1, 1}) ans += 0;
        }
        return ans;
    }
};