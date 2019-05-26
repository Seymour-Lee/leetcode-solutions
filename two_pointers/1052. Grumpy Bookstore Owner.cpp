class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int ans = 0;
        for(int i = 0; i < customers.size(); i++) if(grumpy[i] == 0) ans += customers[i];
        int cur = 0;
        int i = 0;
        while(i < X) cur += customers[i] * grumpy[i], i++;
        int maxval = cur;
        while(i < customers.size()){
            cur = cur - customers[i-X] * grumpy[i-X] + customers[i] * grumpy[i];
            maxval = max(maxval, cur);
            i++;
        }
        return ans + maxval;
    }
};