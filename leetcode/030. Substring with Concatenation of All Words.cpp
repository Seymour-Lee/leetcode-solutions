// TLE
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.size() <= 0 || words.size() <= 0) return ans;
        sort(words.begin(), words.end());
        string conca = "";
        for(auto str: words) conca += str;
        auto pos = s.find(conca);
        while(pos != string::npos){
            ans.push_back(pos);
            pos = s.find(conca, pos+1);
        }
        while(next_permutation(words.begin(), words.end())){
            conca = "";
            for(auto str: words) conca += str;
            pos = s.find(conca);
            while(pos != string::npos){
                ans.push_back(pos);
                pos = s.find(conca, pos+1);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size(), cnt = words.size();
        if(n <= 0 || cnt <= 0) return ans;
        unordered_map<string, int> dict;
        for(auto str: words) dict[str]++;
        int wl = words[0].size();
        for(int i = 0; i < wl; i++){
            int left = i, count = 0;
            unordered_map<string, int> tdict;
            for(int j = i; j <= n-wl; j+=wl){
                string str = s.substr(j, wl);
                if(dict.count(str)){
                    tdict[str]++;
                    if(tdict[str] <= dict[str]) count++;
                    else{
                        while(tdict[str] > dict[str]){
                            string str1 = s.substr(left, wl);
                            tdict[str1]--;
                            if(tdict[str1] < dict[str1]) count--;
                            left += wl;
                        }
                    }
                    if(count == cnt){
                        ans.push_back(left);
                        tdict[s.substr(left, wl)]--;
                        count--;
                        left += wl;
                    }
                }
                else{
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }
        return ans;
    }
};