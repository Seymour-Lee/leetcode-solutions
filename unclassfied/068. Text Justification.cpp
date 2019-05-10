class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        for(int i = 0; i < words.size(); ){
            string line = "";
            vector<string> strs = {};
            int length = 0;
            while(i < words.size() && length + words[i].size() <= maxWidth){
                strs.push_back(words[i]);
                length += words[i].size()+1;
                i++;
            }
            if(i == words.size()){
                for(auto str: strs) line += str + " ";
                line.pop_back();
                line += string(maxWidth - line.size(), ' ');
                ans.push_back(line);
            }
            else{
                if(strs.size() == 1){
                    line = strs.back() + string(maxWidth - strs[0].size(), ' ');
                }
                else{
                    int spaces = maxWidth - length + strs.size();
                    int average = spaces / (strs.size()-1);
                    int extra = spaces - average * (strs.size()-1);
                    line += strs[0];
                    for(int j = 1; j < strs.size(); j++, extra--){
                        line += string(average + (extra > 0? 1: 0), ' ') + strs[j];
                    }
                }
                ans.push_back(line);
            }
        }
        return ans;
    }
};