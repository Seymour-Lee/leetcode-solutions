class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        for(auto w: words){
            auto pos = text.find(w, 0);
            while(pos != string::npos){
                ans.push_back({pos, pos+w.size()-1});
                pos = text.find(w, pos+1);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};