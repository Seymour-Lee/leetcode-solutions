class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        string cur = target;
        string aim(target.length(), '*');
        while(cur != aim){
            int pos = getPosToUnstamp(cur, stamp);
            if(pos == cur.size()) return {}; // no ans
            ans.push_back(pos);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int getPosToUnstamp(string &cur, string stamp){
        for(int i = 0; i < cur.size(); i++){
            int j = 0, ii = i;
            bool flag = false;
            while(j < stamp.size() && ii < cur.size() && 
                  (cur[ii] == '*' || cur[ii] == stamp[j])){
                if(cur[ii] == stamp[j]) flag = true;
                ii++;
                j++;
            }
            if(j == stamp.size() && flag){
                for(int k = 0; k < stamp.size(); ++k) cur[i+k] = '*';
                return i;
            }
        }
        return cur.size(); // no ans
    }
};

// TLE
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        if(target.find(stamp) == string::npos) return {};
        backtracking({}, stamp, target, string(target.size(), '?'), 0);
        return ans;
    }
    
private:
    vector<int> ans;
    set<string> used;
    bool backtracking(vector<int> seq, string stamp, string target, string cur, int counter){
        if(counter > 10*target.size()) return false;
        used.insert(cur);
        if(cur == target){
            ans = seq;
            return true;
        }
        for(int i = 0; i <= target.size()-stamp.size(); i++){
            string next = cur;
            for(int j = 0; j < stamp.size(); j++){
                next[i+j] = stamp[j];
            }
            if(next == cur || used.find(next) != used.end()) continue;
            seq.push_back(i);
            if(backtracking(seq, stamp, target, next, counter+1)) return true;
            seq.pop_back();
        }
        return false;
    }
};