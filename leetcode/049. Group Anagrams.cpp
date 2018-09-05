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