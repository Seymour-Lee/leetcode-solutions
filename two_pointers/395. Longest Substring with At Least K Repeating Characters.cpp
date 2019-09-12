class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        for(int i = 1; i <= 26; i++){
            vector<int> arr(26);
            int left = 0, right = 0;
            int j = 0, lessk = 0;
            while(right < s.size()){
                if(arr[s[right]-'a'] == 0) j++;
                arr[s[right]-'a']++;
                if(arr[s[right]-'a'] == k) lessk++;
                right++;
                while(j > i){
                    if(arr[s[left]-'a'] == k) lessk--;
                    arr[s[left]-'a']--;
                    if(arr[s[left]-'a'] == 0) j--;
                    left++;
                }
                if(j == lessk) ans = max(ans, right-left);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        for(int i = 1; i <= 26; i++){
            vector<int> arr(26);
            int left = 0, right = 0;
            int j = 0, lessk = 0;
            while(right < s.size()){
                if(arr[s[right]-'a'] == 0) j++;
                arr[s[right]-'a']++;
                if(arr[s[right]-'a'] == k) lessk++;
                right++;
                while(j > i){
                    if(arr[s[left]-'a'] == k) lessk--;
                    arr[s[left]-'a']--;
                    if(arr[s[left]-'a'] == 0) j--;
                    left++;
                }
                if(j == lessk) ans = max(ans, right-left);
            }
        }
        return ans;
    }
};