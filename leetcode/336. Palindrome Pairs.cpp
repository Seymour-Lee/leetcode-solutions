class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<string, int> str2idx;
        set<int> sizes;
        auto f = [](string str, int l, int r){
            while(l < r) if(str[l++] != str[r--]) return false;
            return true;
        };
        for(int i = 0; i < words.size(); i++){
            str2idx[words[i]] = i;
            sizes.insert(words[i].size());
        }
        for(int i = 0; i < words.size(); i++){
            string word = words[i];
            int len = word.size();
            reverse(word.begin(), word.end());
            if(str2idx.find(word) != str2idx.end() && str2idx[word] != i)
                ans.push_back({i, str2idx[word]});
            auto itor = sizes.find(len);
            for(auto it = sizes.begin(); it != itor; it++){
                int size = *it;
                if(f(word, 0, len-size-1) && str2idx.find(word.substr(len-size)) != str2idx.end()){
                    ans.push_back({i, str2idx[word.substr(len-size)]});
                }
                if(f(word, size, len-1) && str2idx.find(word.substr(0, size)) != str2idx.end()){
                    ans.push_back({str2idx[word.substr(0, size)], i});
                }
            }
        }
        return ans;
    }
};