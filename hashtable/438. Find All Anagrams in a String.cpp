class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hashp(256), hashs(256);
        for(auto c: p) hashp[c]++;
        int lenp = p.size(), lens = s.size();
        vector<int> result;
        for(int i = 0; i < lens; i++)
        {
            hashs[s[i]]++;
            if(i >= lenp) hashs[s[i-lenp]]--;
            if(hashp == hashs) result.push_back(i-lenp+1);
        }
        return result;

    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hashp(256), hashs(256);
        for(auto c: p) hashp[c]++;
        int lenp = p.size(), lens = s.size();
        vector<int> result;
        for(int i = 0; i < lens; i++)
        {
            hashs[s[i]]++;
            if(i >= lenp) hashs[s[i-lenp]]--;
            if(hashp == hashs) result.push_back(i-lenp+1);
        }
        return result;

    }
};