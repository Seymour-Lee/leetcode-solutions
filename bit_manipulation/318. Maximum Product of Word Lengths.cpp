class Solution {
public:
    int maxProduct(vector<string>& words) {
        int result = 0;
        map<string, int> str2pattern;
        for(auto str: words){
            int p = 0;
            for(auto ch: str){
                p = p | (1 << (ch - 'a'));
            }
            str2pattern[str] = p;
        }
        for(int i = 0; i < words.size(); i++){
            for(int j = i; j < words.size(); j++){
                if((str2pattern[words[i]] & str2pattern[words[j]]) == 0){
                    result = max(result, 
                            (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums;
        for(auto str: words){
            int num = 0;
            for(auto c: str) num |= (1 << (c-'a'));
            nums.push_back(num);
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) for(int j = 0; j < i; j++){
            if((nums[i] & nums[j]) == 0) ans = max(ans, (int)words[i].size()*(int)words[j].size());
        }
        return ans;
    }
};