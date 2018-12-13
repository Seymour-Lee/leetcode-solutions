class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0) return result;
        map<string, vector<string>> sorted2vec;
        for(auto str: strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            sorted2vec[sorted].push_back(str);
        }
        for(auto it: sorted2vec){
            result.push_back(it.second);
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> key2anas;
        for(auto str: strs){
            vector<int> dict = vector<int>(26, 0);
            for(auto c: str) dict[c-'a']++;
            string key = "";
            for(int i = 0; i < dict.size(); i++) key += string(1, i+'a') + to_string(dict[i]);
            key2anas[key].push_back(str);
        }
        for(auto p: key2anas) ans.push_back(p.second);
        return ans;
    }
};

class Solution {
protected:
    int primes[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long,vector<string>> m;
        for (string str : strs) {
            int num = 1;
            for (char c : str) {
                num *= primes[c-'a'];
            }
            m[num].push_back(str);
        }
        vector<vector<string>> res;
        for (auto it : m) {
            res.push_back(it.second);
        }
        return res;
    }
};