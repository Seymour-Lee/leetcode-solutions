class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> universalWords;
        vector<int> bmax(26, 0);
        for(int i = 0; i < B.size(); i++){
            vector<int> bi = count(B[i]);
            for(int j = 0; j < bi.size(); j++){
                bmax[j] = max(bmax[j], bi[j]);
            }
        }
        for(int i = 0; i < A.size(); i++){
            auto ai = count(A[i]);
            bool isUniversal = true;
            for(int j = 0; j < ai.size(); j++){
                if(bmax[j] > ai[j]){
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal) universalWords.push_back(A[i]);
        }
        return universalWords;
    }
    
private:
    vector<int> count(string str){
        vector<int> ans(26, 0);
        for(auto ch: str) ans[ch-'a']++;
        return ans;
    }
};