class Solution {
public:
    void dfs(const int len, int remain, int curIndex, int val, vector<int>& vec){
        if(remain == 0 && len == 4 && val < 12) vec.push_back(val);
        if(remain == 0 && len == 6 && val < 60) vec.push_back(val);
        if(curIndex == len || remain == 0) return;
        dfs(len, remain, curIndex+1, val, vec);
        val += pow(2, curIndex);
        dfs(len, remain-1, curIndex+1, val, vec);
    }
    
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for(int i = max(0, num-6); i <= min(4, num); i++){
            vector<int> hours, minutes;
            dfs(4, i, 0, 0, hours);
            dfs(6, num-i, 0, 0, minutes);
            for(auto hour: hours)
                for(auto minute: minutes) {
                    string str = (to_string(minute).size()==1?"0":"") + to_string(minute);
                    result.push_back(to_string(hour)+":"+ str);
                }
        }
        return result;
    }

};