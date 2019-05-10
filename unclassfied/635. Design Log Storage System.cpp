class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        time2id.emplace(timestamp, id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> ans;
        if(gra == "Year"){
            s = s.substr(0, 4) + ":01:01:00:00:00";
            e = e.substr(0, 4) + ":12:31:23:59:59";
        }
        else if(gra == "Month"){
            s = s.substr(0, 7) + ":01:00:00:00";
            e = e.substr(0, 7) + ":31:23:59:59";
        }
        else if(gra == "Day"){
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        }
        else if(gra == "Hour"){
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        }
        else if(gra == "Minute"){
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }
        auto lower = time2id.lower_bound(s);
        auto upper = time2id.upper_bound(e);
        while(lower != upper){
            ans.push_back(lower->second);
            lower++;
        }
        return ans;
    }
    
private:
    multimap<string, int> time2id;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */