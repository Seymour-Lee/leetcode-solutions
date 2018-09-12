class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<pair<int, int>> stk;
        for(auto log: logs){
            int id, time;
            bool start;
            getInfo(log, id, start, time);
            if(start == true){
                stk.push({id, time});
            }
            else{
                int stime = stk.top().second;
                stk.pop();
                int diff = time - stime + 1;
                ans[id] += diff;
                if(stk.empty() == false)
                    ans[stk.top().first] -= diff;
            }
        }
        return ans;
    }
    
private:
    void getInfo(string log, int &id, bool &start, int &time){
        istringstream is(log);
        string str = "";
        getline(is, str, ':');
        id = stoi(str);
        getline(is, str, ':');
        start = str == "start"? true: false;
        getline(is, str, ':');
        time = stoi(str);
    }
};