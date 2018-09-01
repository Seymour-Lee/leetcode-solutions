class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int result = 0;
        map<int, int> ab2sum;
        for(auto a: A){
            for(auto b: B){
                ab2sum[a+b]++;
            }
        }
        for(auto c: C){
            for(auto d: D){
                auto itor = ab2sum.find(0-c-d);
                if(itor != ab2sum.end()) result += itor->second;
            }
        }
        return result;
    }
};