class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> result;
        map<string, vector<string>> content2dir;
        for(auto path:paths){
            string dir = "";
            int idx = 0;
            while(idx < path.size() && path[idx] != ' ') idx++;
            dir = path.substr(0, idx) + "/";
            path = path.substr(idx+1, path.size()-idx-1);
            idx = 0;
            while(idx < path.size()){
                while(idx < path.size() && path[idx] != ' ') idx++;
                string cur = path.substr(0, idx);
                pair<string, string> p = getNameAndContent(cur);
                content2dir[p.second].push_back(dir+p.first);
                path = idx == path.size()? "": path.substr(idx+1, path.size()-idx-1);
                idx = 0;
            }
        }
        for(auto e: content2dir){
            if(e.second.size() == 1) continue;
            vector<string> cur;
            for(auto p: e.second) cur.push_back(p);
            result.push_back(cur);
        }
        return result;
    }
    
private:
    pair<string, string> getNameAndContent(string str){
        string name = "";
        string content = "";
        int idx = 0;
        while(idx < str.size() && str[idx] != '(') idx++;
        name = str.substr(0, idx);
        content = str.substr(idx+1, str.size()-idx-2);
        return pair<string, string>{name, content};
    }
};