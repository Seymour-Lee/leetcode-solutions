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

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < s.length(); ++i) {
            maxf = max(maxf, ++count[s[i]]);
            if (res - maxf < k)
                res++;
            else
                count[s[i - res]]--;
        }
        return res;
    }
};