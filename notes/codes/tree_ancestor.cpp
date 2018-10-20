#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> solution(vector<int>& A, int d) {
        if(A.size() <= 1) return A;
        vector<int> ancestors(A.size(), -1);
        for(int i = 1; i < A.size(); i++){
            int anc = A[i];
            int dis = d-1;
            while(dis > 0 && A[anc] != -1) anc = A[anc], dis--;
            ancestors[i] = dis > 0? -1: anc;
        }
        return ancestors;
    }

    vector<int> solution1(vector<int> A, int d){ // not good
        if(A.size() <= 1) return A;
        vector<int> ancestors(A.size(), -1);
        vector<vector<int>> dp(A.size(), vector<int>(d+1, -2));
        for(int i = 0; i < A.size(); i++){
            int anc = A[i];
            int dis = 1;
            vector<int> ancs = {-1, anc};
            while(dis <= d && A[anc] != -1){
                if(dp[anc][d-dis] != -2){
                    ancestors[i] = dp[anc][d-dis];
                    for(int j = 1; j < (int)ancs.size(); j++) dp[i][j] = ancs[j];
                    break;
                }
                ancs.push_back(anc);
                anc = A[anc], dis++;
            } 
            for(int j = 1; j < (int)ancs.size(); j++) dp[i][j] = ancs[j];
            ancestors[i] = dis > 0? -1: anc;
        }
        return ancestors;
    }
};

int main() {
    Solution sol;
    // vector<int> A = {-1, 0, 1, 2, 3};
    // int d = 2;
    vector<int> A = {-1, 0, 4, 2, 1};
    int d = 3;
    auto ans = sol.solution(A, d);
    for(auto a: ans) cout<<a<<" ";
    return 0;
}