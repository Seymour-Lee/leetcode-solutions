class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0, j = 0;
        vector<int> vec(26, 0);
        int ans = 0;
        while(j < s.size()){
            vec[s[j++]-'A']++;
            while(j-i-*max_element(vec.begin(), vec.end()) > k)
                vec[s[i++]-'A']--;
            ans = max(ans, j-i);
        }
        return ans;
    }
};