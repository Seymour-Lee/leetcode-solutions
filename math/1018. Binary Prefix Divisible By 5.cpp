class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int num = 0;
        for(auto a: A){
            num = (num*2)%5 + a;
            ans.push_back(num%5 == 0);
        }
        return ans;
    }
};