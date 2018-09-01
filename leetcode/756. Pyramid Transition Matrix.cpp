class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if(bottom == "") return true;
        map<string, string> lr2t;
        for(auto a: allowed) lr2t[a.substr(0, 2)] += a.substr(2);
        return dfs(bottom, lr2t);
    }
    
private:
    bool dfs(string bottom, const map<string, string> &lr2t){
        if(bottom.size() <= 1) return true;
        vector<string> next = {""};
        for(int i = 0; i < bottom.size()-1; i++){
            vector<string> cur;
            string str = string(1, bottom[i]) + string(1, bottom[i+1]);
            auto itor = lr2t.find(str);
            if(itor == lr2t.end()) return false;
            for(auto c: itor->second){
                for(auto str: next){
                    cur.push_back(str + c);
                }
            }
            next = cur;
        }
        for(auto str: next){
            if(dfs(str, lr2t) == true) return true;
        }
        return false;
    }
};