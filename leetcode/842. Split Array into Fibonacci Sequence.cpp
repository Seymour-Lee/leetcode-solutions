class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        backtracking(S, 0, result);
        return result;
    }
    
private:
    bool backtracking(string &s, int start, vector<int> &res){
        int n = s.size();
        if(start >= n && res.size() >= 3) return true;
        int maxSpliteSize = s[start] == '0'? 1: 10;
        for(int i = 1; i <= maxSpliteSize && start+i <= s.size(); i++){
            long long num = stoll(s.substr(start, i));
            if(num > INT_MAX) return false;
            int sz = res.size();
            if(sz >= 2 && res[sz-1] + res[sz-2] < num) return false;
            if(sz <= 1 || res[sz-1] + res[sz-2] == num){
                res.push_back(num);
                if(backtracking(s, start+i, res)) return true;
                res.pop_back();
            }
        }
        return false;
    }
};