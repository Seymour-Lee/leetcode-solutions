class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> cur;
        int result = 0;
        
        int n = s.size();
        int i = 0, j = 0;
        while(i < n && j < n){
            if(cur.find(s.at(j)) == cur.end()){
                cur.insert(s.at(j));
                j++;
                result = max(result, j - i);
            }
            else{
                cur.erase(s.at(i));
                i++;
            }
        }
        
        return result;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        int ans = 1;
        unordered_set<char> seen;
        seen.insert(s[0]);
        int i = 0, j = 1;
        while(i < s.size() && j < s.size()){
            if(seen.find(s[j]) == seen.end()){
                seen.insert(s[j++]);
                ans = max(ans, j-i);
            }
            else{
                if(s[i] == s[j]) i++, j++;
                else seen.erase(s[i++]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        unordered_set<char> chars;
        int ans = 0;
        while(i <= j && j < s.size()){
            if(chars.find(s[j]) == chars.end()) chars.insert(s[j++]), ans = max(ans, j-i);
            else chars.erase(s[i++]);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int ans = 1;
        unordered_set<char> seen;
        seen.insert(s[0]);
        int l = 0, r = 1;
        while(l <= r && r < s.size()){
            if(seen.find(s[r]) == seen.end()){
                seen.insert(s[r]);
                ans = max(ans, r-l+1);
                r++;
            }
            else{
                seen.erase(s[l++]);
            }
        }
        return ans;
    }
};