class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n % 2 == 1){
            ans.push_back(0);
            n--;
        }
        int cur = 1;
        while(n){
            ans.push_back(cur);
            ans.push_back(-cur);
            cur++;
            n -= 2;
        }
        return ans;
    }
};