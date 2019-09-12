class Solution {
public:
    int lengthLongestPath(string input) {
        if(input.size() == 0) return 0;
        map<int, string> level2str;
        int level = 0;
        vector<string> path;
        istringstream is(input);
        string str;
        auto ist = [](char c){return c == '\t';};
        while(getline(is, str, '\n')){
            auto itor = find_if_not(str.begin(), str.end(), ist);
            auto pos = itor - str.begin();
            string name = str.substr(pos);
            level2str[pos] = name;
            if(name.find('.') != string::npos){
                string pth = "";
                for(decltype(pos) i = 0; i <= pos; i++) pth += "/" + level2str[i];
                path.push_back(pth.substr(1));
            }
        }
        int ans = 0;
        for(auto p: path) ans = max(ans, (int)p.size());
        return ans;
    }
};

class Solution {
public:
    int lengthLongestPath(string input) {
        if(input.size() == 0) return 0;
        unordered_map<int, string> level2str;
        vector<string> path;
        istringstream is(input);
        string str;
        auto ist = [](char c){return c == '\t';};
        while(getline(is, str, '\n')){
            auto itor = find_if_not(str.begin(), str.end(), ist);
            auto pos = itor - str.begin();
            string name = str.substr(pos);
            level2str[pos] = name;
            if(name.find('.') != string::npos){
                string pth = "";
                for(decltype(pos) i = 0; i <= pos; i++) pth += "/" + level2str[i];
                path.push_back(pth.substr(1));
            }
        }
        int ans = 0;
        for(auto p: path) ans = max(ans, (int)p.size());
        return ans;
    }
};