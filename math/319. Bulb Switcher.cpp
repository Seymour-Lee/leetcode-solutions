class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) if(sqrt(i)-floor(sqrt(i)) == 0) ans++;
        return ans;
    }
};