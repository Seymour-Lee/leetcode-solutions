class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        backtracking(ans, "", word, 0, 0);
        return ans;
    }
    
private:
    void backtracking(vector<string> &ans, string cur, string word, int pos, int counter){
        if(pos == word.size()){
            if(counter > 0) cur += to_string(counter);
            ans.push_back(cur);
            return;
        }
        backtracking(ans, cur, word, pos+1, counter+1);
        backtracking(ans, cur+(counter? to_string(counter): "")+word[pos], word, pos+1, 0);
    }
};