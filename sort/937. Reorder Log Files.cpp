class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letters;
        vector<string> digits;
        for(auto log: logs){
            istringstream is = istringstream(log);
            string id = "";
            string l = "";
            string str = "";
            getline(is, id, ' ');
            l = log.substr(id.size()+1);
            if(isdigit(l.front())) digits.push_back(log);
            else letters.push_back({log, l+id});
        }
        auto f = [](pair<string, string> a, pair<string, string> b){
            return a.second < b.second;
        };
        sort(letters.begin(), letters.end(), f);
        vector<string> ans;
        for(auto log: letters) ans.push_back(log.first);
        for(auto log: digits) ans.push_back(log);
        return ans;
    }
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> l;
        vector<string> d;
        for(auto log: logs){
            auto pos = log.find(' ');
            string id = log.substr(0, pos);
            string co = log.substr(pos+1);
            if(isdigit(co.front())) d.push_back(log);
            else l.push_back({log, co+id});
        }
        auto f = [](pair<string, string> a, pair<string, string> b){
            return a.second < b.second;
        };
        sort(l.begin(), l.end(), f);
        vector<string> ans;
        for(auto a: l) ans.push_back(a.first);
        for(auto a: d) ans.push_back(a);
        return ans;
    }
};