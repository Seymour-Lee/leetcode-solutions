class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        for(int i = 0, j = 1; i < S.size() && j < S.size(); i = j, j++){
            while(S[i] == S[j]) j++;
            if(j-i >= 3) result.push_back(vector<int>{i, j-1});
        }
        return result;
    }
};