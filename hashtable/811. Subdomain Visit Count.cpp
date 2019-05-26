class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> result;
        map<string, int> mapping;
        for(auto str: cpdomains){
            int i = 0;
            while(str[i] != ' ') i++;
            int num = stoi(str.substr(0, i));
            mapping[str.substr(i+1, str.size()-i-1)] += num;
            
            for (i = i+1; i < str.size(); i++) {
                if (str[i] =='.') {
                    mapping[str.substr(i+1, str.size()-1-i)] += num;
                }
            }
        }
        for(auto cur: mapping){
            result.push_back(to_string(cur.second) + " " + cur.first);
        }
        return result;
    }
};

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string ,int> str2times;
        for(auto &str: cpdomains){
            auto pos = str.find(' ');
            int num = stoi(str.substr(0, pos));
            str = str.substr(pos+1);
            while(str.size()){
                str2times[str] += num;
                pos = str.find('.');
                if(pos == string::npos) break;
                str = str.substr(pos+1);
            }
        }
        vector<string> ans;
        for(auto p: str2times){
            ans.push_back(to_string(p.second) + " " + p.first);
        }
        return ans;
    }
};