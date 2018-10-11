class Solution {
public:
    vector<string> generatePalindromes(string s) {
        if(s.size() == 0) return {};
        int size = s.size();
        set<string> ans;
        unordered_map<char, int> ch2freq;
        for(auto ch: s) ch2freq[ch]++;
        auto odds = valid(ch2freq);
        if(odds.first > 1) return {};
        string str = "";
        if(odds.first == 1){
            str = str + odds.second->first;
            odds.second->second--;
        }
        backtracking(ans, ch2freq, str, size);
        return vector<string>(ans.begin(), ans.end());
    }
    
private:
    void backtracking(set<string> &ans, unordered_map<char, int> &ch2freq, string cur, 
                                                                        const int size){
        if(cur.size() == size){
            ans.insert(cur);
            return;
        }
        for(auto &e: ch2freq){
            if(e.second == 0) continue;
            e.second = e.second - 2;
            backtracking(ans, ch2freq, string(1, e.first)+cur+string(1, e.first), size);
            e.second = e.second + 2;
        }
    }
    
    pair<int, unordered_map<char, int>::iterator> valid(unordered_map<char, int> &ch2freq){
        pair<int, unordered_map<char, int>::iterator> ans;
        for(auto itor = ch2freq.begin(); itor != ch2freq.end(); itor++){
            if(itor->second % 2 == 1){
                ans.first++;
                ans.second = itor;
            }
        }
        return ans;
    }
};