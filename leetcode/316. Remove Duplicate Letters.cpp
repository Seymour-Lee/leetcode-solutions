class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> seen(26, false);
        vector<int> cnt(26, 0);
        for(auto c: s) cnt[c-'a']++;
        stack<char> stk;
        for(auto c: s){
            cnt[c-'a']--;
            if(seen[c-'a'] || (stk.empty() == false && stk.top() == c)) continue;
            while(stk.empty() == false && stk.top() > c && cnt[stk.top()-'a'] > 0){
                seen[stk.top()-'a'] = false;
                stk.pop();
            }
            stk.push(c);
            seen[c-'a'] = true;
        }
        string ans = "";
        while(stk.empty() == false){
            ans = string(1, stk.top()) + ans;
            stk.pop();
        }
        return ans;
    }
};