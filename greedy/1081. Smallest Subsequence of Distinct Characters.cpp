class Solution {
public:
    string smallestSubsequence(string text) {
        vector<int> count(26, 0);
        // for now and each letter, how many left
        for(auto c: text) count[c-'a']++;
        vector<bool> used(26, false);
        string ans = "";
        for(auto c: text){
            count[c-'a']--;
            if(used[c-'a']) continue;
            while(ans.size() && count[ans.back()-'a'] && c < ans.back()){
                used[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c-'a'] = true;
        }
        return ans;
    }
};

// "cdadabcc"
// cda