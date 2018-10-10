class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        map<string, vector<int>> str2idxs;
        for(int i = 0; i < words.size(); i++) str2idxs[words[i]].push_back(i);
        int ans = INT_MAX;
        if(word1 == word2){
            auto idxs = str2idxs[word1];
            sort(idxs.begin(), idxs.end());
            for(int i = 0; i < idxs.size()-1; i++) ans = min(ans, idxs[i+1]-idxs[i]);
        }
        else{
            auto idxs1 = str2idxs[word1];
            auto idxs2 = str2idxs[word2];
            sort(idxs1.begin(), idxs1.end());
            sort(idxs2.begin(), idxs2.end());
            int i = 0, j = 0;
            if(idxs1[i] < idxs2[j]) ans = min(ans, idxs2[j]-idxs1[i++]);
            else ans = min(ans, idxs1[i]-idxs2[j++]);
            while(i < idxs1.size() && j < idxs2.size()){
                if(idxs1[i] < idxs2[j]) ans = min(ans, idxs2[j]-idxs1[i++]);
                else ans = min(ans, idxs1[i]-idxs2[j++]);
            }
        }
        return ans;
    }
};