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

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> c2t(26, 0);
        vector<bool> v(26, false);
        for(auto c: s) c2t[c-'a']++;
        string ans = "";
        for(auto c: s){
            c2t[c-'a']--;
            if(v[c-'a'] == false){
                while(ans.size() && c2t[ans.back()-'a'] > 0 && ans.back() >= c) {
                    v[ans.back()-'a'] = false;
                    ans.pop_back();
                }
                ans.push_back(c);
                v[c-'a'] = true;
            }
        }
        return ans;
    }
};